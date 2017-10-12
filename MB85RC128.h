/**
 * @license    BSD 3-Clause
 * @copyright  microHAL
 * @version    $Id$
 * @brief
 *
 * @authors    kamil
 * created on: 17-09-2017
 * last modification: 17-09-2017
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

#ifndef _MICROHAL_MB85RC128_H_
#define _MICROHAL_MB85RC128_H_
/* **************************************************************************************************************************************************
 * INCLUDES
 */

#include "I2CDevice/I2CDevice.h"
#include "microhal.h"

#include "Memory.h"

using namespace microhal;

/* **************************************************************************************************************************************************
 * CLASS
 */

class MB85RC128 : public ExternalMemory, private I2CDevice {
 private:
    enum { I2C_ADDR = 0b10100000, SIZE = 1024 * 16 };

 public:
    MB85RC128(microhal::I2C &aI2C) : ExternalMemory{SIZE}, I2CDevice{aI2C, I2C_ADDR} {}
    virtual void ReadRegion(size_t aOffset, size_t aSize, uint8_t *aData) noexcept override {
        I2CDevice::readRegisters(static_cast<uint16_t>(aOffset), aData, aSize);
    }
    virtual void WriteRegion(size_t aOffset, size_t aSize, uint8_t *aData) noexcept override {
        I2CDevice::writeRegisters(static_cast<uint16_t>(aOffset), aData, aSize);
    }
};

#endif  // _MICROHAL_MB85RC128_H_
