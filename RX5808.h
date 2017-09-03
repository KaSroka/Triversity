/**
 * @license    BSD 3-Clause
 * @copyright  microHAL
 * @version    $Id$
 * @brief
 *
 * @authors    kamil
 * created on: 20-08-2017
 * last modification: 20-08-2017
 *
 * @copyright Copyright (c) 2017, microHAL
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
 *
 *     1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
 *     2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the
 *        documentation and/or other materials provided with the distribution.
 *     3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this
 *        software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER
 * OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _MICROHAL_RX5808_H_
#define _MICROHAL_RX5808_H_
/* **************************************************************************************************************************************************
 * INCLUDES
 */

#include <algorithm>
#include <string>

#include "SPIDevice/SPIDevice.h"
#include "microhal.h"

/* **************************************************************************************************************************************************
 * CLASS
 */

#define _CHANNEL_REG_FLO(f) ((f - 479) / 2)
#define _CHANNEL_REG_N(f) (_CHANNEL_REG_FLO(f) / 32)
#define _CHANNEL_REG_A(f) (_CHANNEL_REG_FLO(f) % 32)
#define CHANNEL_REG(f) (_CHANNEL_REG_N(f) << 7) | _CHANNEL_REG_A(f)

#define BAND(band) band##0, band##1, band##2, band##3, band##4, band##5, band##6, band##7
#define FREQUENCY(ch, frequency) \
    { frequency, ch, #ch }
#define BAND_FREQUENCIES(band, f0, f1, f2, f3, f4, f5, f6, f7)                                                                \
    FREQUENCY(band##0, f0)                                                                                                    \
    , FREQUENCY(band##1, f1), FREQUENCY(band##2, f2), FREQUENCY(band##3, f3), FREQUENCY(band##4, f4), FREQUENCY(band##5, f5), \
        FREQUENCY(band##6, f6), FREQUENCY(band##7, f7)

class Channels {
 public:
    enum Channel { BAND(A), BAND(B), BAND(E), BAND(F), BAND(R), BAND(L), END, START = 0 };

    class Descriptor {
     private:
        uint32_t mFrequency;
        std::string mName;
        Channel mChannel;

     public:
        constexpr Descriptor(uint32_t aFrequency, const std::string& aName, Channels::Channel aChannel)
            : mFrequency{aFrequency}, mName{aName}, mChannel{aChannel} {}
        constexpr uint32_t GetFrequency() const noexcept { return mFrequency; }
        constexpr uint32_t GetRegValue() const noexcept { return CHANNEL_REG(mFrequency); }
        constexpr const std::string& GetName() const noexcept { return mName; }
        constexpr Channels::Channel GetChannel() const noexcept { return mChannel; }
    };

    friend constexpr Channel& operator++(Channel& aChannel) const noexcept {
        if (Channel < (Channel::END - 1)) aChannel++;
        return aChannel;
    }

    friend constexpr Channel& operator--(Channel& aChannel) const noexcept {
        if (Channel > Channel::START) aChannel--;
        return aChannel;
    }

    friend constexpr Channel& operator++(Channel& aChannel, int)const noexcept { return ++aChannel; }

    friend constexpr Channel& operator--(Channel& aChannel, int)const noexcept { return --aChannel; }

    static constexpr const Descriptor& GetByChannel(Channels::Channel aChannel) const noexcept {
        return *std::find_if(mChannels.cbegin(), mChannels.cend(),
                             [&aChannel](const Descriptor& aDescriptor) { return aDescriptor.GetChannel() == aChannel; });
    }

    static constexpr const Descriptor& GetByName(const std::string& aName) const noexcept {
        return *std::find_if(mChannels.cbegin(), mChannels.cend(),
                             [&aName](const Descriptor& aDescriptor) { return aDescriptor.GetName() == aName; });
    }

    static constexpr const Descriptor& GetByFrequency(uint32_t aFrequency) const noexcept {
        return *std::find_if(mChannels.cbegin(), mChannels.cend(),
                             [&aFrequency](const Descriptor& aDescriptor) { return aDescriptor.GetFrequency() == aFrequency; });
    }

 private:
    static constexpr std::array<Descriptor, Channels::Channel::END> mChannels{
        BAND_FREQUENCIES(A, 5865, 5845, 5825, 5805, 5785, 5765, 5745, 5725), BAND_FREQUENCIES(B, 5733, 5752, 5771, 5790, 5809, 5828, 5847, 5866),
        BAND_FREQUENCIES(E, 5705, 5685, 5665, 5645, 5885, 5905, 5925, 5945), BAND_FREQUENCIES(F, 5740, 5760, 5780, 5800, 5820, 5840, 5860, 5880),
        BAND_FREQUENCIES(R, 5658, 5695, 5732, 5769, 5806, 5843, 5880, 5917), BAND_FREQUENCIES(L, 5362, 5399, 5436, 5473, 5510, 5547, 5584, 5621)};
};

class RX5808 : private microhal::SPIDevice {
 private:
    enum Registers {
        SYNTH_A = 0x01,
        POWER = 0x0A,
    };

    struct Transaction {
        Registers reg : 4;
        bool write : 1;
        uint32_t command : 20;
    } __attribute__((packed));

    void Write(Transaction& aTransaction) noexcept { SPIDevice::writeBuffer(reinterpret_cast<uint8_t*>(&aTransaction), sizeof(aTransaction), true); }

 public:
    RX5808(microhal::SPI& aSpi, microhal::GPIO::IOPin aCSPin) : microhal::SPIDevice(aSpi, aCSPin) {}

    void DisableAudio() noexcept {
        Transaction transaction = {Registers::POWER, true, 0b00010000110111110011};
        Write(transaction);
    }

    void SetFrequency(uint32_t aFrequency) noexcept {
        Transaction transaction = {Registers::SYNTH_A, true, CHANNEL_REG(aFrequency)};
        Write(transaction);
    }

    void SetChannel(Channels::Channel aChannel) noexcept {
        Transaction transaction = {Registers::SYNTH_A, true, Channels::GetByChannel(aChannel).GetRegValue()};
        Write(transaction);
    }
};

#endif  // _MICROHAL_RX5808_H_
