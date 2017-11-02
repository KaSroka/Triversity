/* ========================================================================================================================== */ /**
 @license    BSD 3-Clause
 @copyright  microHAL
 @version    $Id$
 @brief      board support package for stm32f4Discovery board

 @authors    kamil
 created on: 16-04-2014
 last modification: <DD-MM-YYYY>

 @copyright Copyright (c) 2017, microHAL
 All rights reserved.
 Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following
 conditions are met:
 	 1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
 	 2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer
 	 	in the documentation and/or other materials provided with the distribution.
 	 3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived
 	 	from this software without specific prior written permission.
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING,
 BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
 SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
 OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

 */ /* ==========================================================================================================================
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                     */

#ifndef TRIVERSITY_V1_H_
#define TRIVERSITY_V1_H_

#include <array>

#include "Analog.h"
#include "Drawing.h"
#include "MB85RC128.h"
#include "Memory.h"
#include "RX5808.h"
#include "TouchController.h"
#include "VideoSwitch.h"

namespace bsp {

namespace Display {
static microhal::SPI &spi = microhal::stm32f3xx::SPI::spi1;
constexpr microhal::GPIO::IOPin Reset(microhal::stm32f3xx::GPIO::PortB, 6);
constexpr microhal::GPIO::IOPin CS(microhal::stm32f3xx::GPIO::PortB, 9);
constexpr microhal::GPIO::IOPin DC(microhal::stm32f3xx::GPIO::PortB, 7);
}

namespace VideoRx {
static microhal::SPI &spi = microhal::stm32f3xx::SPI::spi3;
namespace A {
constexpr microhal::GPIO::IOPin CS(microhal::stm32f3xx::GPIO::PortC, 11);
}

namespace B {
constexpr microhal::GPIO::IOPin CS(microhal::stm32f3xx::GPIO::PortA, 15);
}

namespace C {
constexpr microhal::GPIO::IOPin CS(microhal::stm32f3xx::GPIO::PortD, 2);
}
}

namespace VideoSwitch {
constexpr microhal::GPIO::IOPin EN_RX_1(microhal::stm32f3xx::GPIO::PortA, 8);
constexpr microhal::GPIO::IOPin EN_RX_2(microhal::stm32f3xx::GPIO::PortC, 9);
constexpr microhal::GPIO::IOPin EN_RX_3(microhal::stm32f3xx::GPIO::PortC, 8);
constexpr microhal::GPIO::IOPin EN_RX_OSD(microhal::stm32f3xx::GPIO::PortC, 7);
constexpr microhal::GPIO::IOPin EN_RX_NO_OSD(microhal::stm32f3xx::GPIO::PortC, 6);
}

namespace Memory {
static microhal::I2C &i2c = microhal::stm32f3xx::I2C::i2c2;
}

constexpr microhal::GPIO::IOPin VibrationMotor(microhal::stm32f3xx::GPIO::PortA, 12);
}

namespace Config {
extern WatchedExternalMemoryObject<Channels::Channel> Channel;
}

extern Drawing::Graphics graphics;
extern TouchLib::TouchController touchController;
extern std::array<RX5808, 3> videoRxes;
extern VideoSwitch videoSwitch;
extern MB85RC128 memory;
extern ExternalMemoryMap memoryMap;
extern Analog analog;

#endif /* TRIVERSITY_V1_H_ */
