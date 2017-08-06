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

#include "SPIDevice/SPIDevice.h"
#include "microhal.h"

/* **************************************************************************************************************************************************
 * CLASS
 */

#define _CHANNEL_REG_FLO(f) ((f - 479) / 2)
#define _CHANNEL_REG_N(f) (_CHANNEL_REG_FLO(f) / 32)
#define _CHANNEL_REG_A(f) (_CHANNEL_REG_FLO(f) % 32)
#define CHANNEL_REG(f) (_CHANNEL_REG_N(f) << 7) | _CHANNEL_REG_A(f)

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

 public:
    RX5808(microhal::SPI& aSpi, microhal::GPIO::IOPin aCSPin) : microhal::SPIDevice(aSpi, aCSPin) {}

    void DisableAudio() {
        Transaction transaction = {Registers::POWER, true, 0b11111111111111111111};  // 0b00010000110111110011};

        SPIDevice::writeBuffer(reinterpret_cast<uint8_t*>(&transaction), sizeof(transaction), true);
    }

    void SetFrequency(uint32_t frequency) {
        Transaction transaction = {Registers::SYNTH_A, true, CHANNEL_REG(frequency)};  // 0b00010000110111110011};

        SPIDevice::writeBuffer(reinterpret_cast<uint8_t*>(&transaction), sizeof(transaction), true);
    }
};

#endif  // _MICROHAL_RX5808_H_
