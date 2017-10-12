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
        Channel mChannel;
        const char* mName;

     public:
        constexpr Descriptor(uint32_t aFrequency, Channels::Channel aChannel, const char aName[3]);
        constexpr uint32_t GetFrequency() const noexcept { return mFrequency; }
        constexpr uint32_t GetRegValue() const noexcept { return CHANNEL_REG(mFrequency); }
        const std::string GetName() const noexcept { return mName; }
        constexpr Channels::Channel GetChannel() const noexcept { return mChannel; }
    };

    friend constexpr Channel& operator++(Channel& aChannel) noexcept {
        if (aChannel < (Channel::END - 1)) aChannel = (Channel)((uint8_t)(aChannel) + 1);
        return aChannel;
    }

    friend constexpr Channel& operator--(Channel& aChannel) noexcept {
        if (aChannel > Channel::START) aChannel = (Channel)((uint8_t)(aChannel)-1);
        return aChannel;
    }

    friend constexpr Channel operator++(Channel& aChannel, int)noexcept {
        if (aChannel < (Channel::END - 1)) aChannel = (Channel)((uint8_t)(aChannel) + 1);
        return (Channel)((uint8_t)(aChannel)-1);
    }

    friend constexpr Channel operator--(Channel& aChannel, int)noexcept {
        if (aChannel > Channel::START) aChannel = (Channel)((uint8_t)(aChannel)-1);
        return (Channel)((uint8_t)(aChannel) + 1);
    }

    static const Descriptor& GetByChannel(Channels::Channel aChannel) noexcept {
        return *std::find_if(mChannels.cbegin(), mChannels.cend(),
                             [&aChannel](const Descriptor& aDescriptor) { return aDescriptor.GetChannel() == aChannel; });
    }

    static const Descriptor& GetByName(const std::string& aName) noexcept {
        return *std::find_if(mChannels.cbegin(), mChannels.cend(),
                             [&aName](const Descriptor& aDescriptor) { return aDescriptor.GetName() == aName; });
    }

    static const Descriptor& GetByFrequency(uint32_t aFrequency) noexcept {
        return *std::find_if(mChannels.cbegin(), mChannels.cend(),
                             [&aFrequency](const Descriptor& aDescriptor) { return aDescriptor.GetFrequency() == aFrequency; });
    }

 private:
    static const std::array<Descriptor, Channels::Channel::END> mChannels;
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

namespace std {
template <>
class numeric_limits<Channels::Channel> {
 public:
    static Channels::Channel lowest() { return Channels::START; };
    static Channels::Channel min() { return Channels::START; };
    static Channels::Channel max() { return static_cast<Channels::Channel>(Channels::END - 1); };
};
}

#endif  // _MICROHAL_RX5808_H_
