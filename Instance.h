/**
 * @license    BSD 3-Clause
 * @copyright  microHAL
 * @version    $Id$
 * @brief
 *
 * @authors    kamil
 * created on: 02-11-2017
 * last modification: 02-11-2017
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

#ifndef _MICROHAL_INSTANCE_H_
#define _MICROHAL_INSTANCE_H_
/* **************************************************************************************************************************************************
 * INCLUDES
 */
#include <array>

#include "microhal.h"
#include "microhal_bsp.h"

#include "Analog.h"
#include "Graphics.h"
#include "Memory.h"
#include "RX5808.h"
#include "SSD1306.h"
#include "TouchController.h"
#include "VideoSwitch.h"
#include "WindowManager.h"
#include "WorkQueue.h"

/* **************************************************************************************************************************************************
 * CLASS
 */

class Instance {
 private:
    Instance()
        : mDisplay{bsp::Display::spi, bsp::Display::CS, bsp::Display::DC, bsp::Display::Reset},
          mGraphics{mDisplay},
          mWindowManager{},
          mTouchController{},
          mMemory{bsp::Memory::i2c},
          mVideoRxes{RX5808{bsp::VideoRx::spi, bsp::VideoRx::A::CS}, RX5808{bsp::VideoRx::spi, bsp::VideoRx::B::CS},
                     RX5808{bsp::VideoRx::spi, bsp::VideoRx::C::CS}},
          mMemoryMap{mMemory},
          mChannel{},
          mAnalog{},
          mVideoSwitch{{bsp::VideoSwitch::EN_RX_1, bsp::VideoSwitch::EN_RX_2, bsp::VideoSwitch::EN_RX_3},
                       bsp::VideoSwitch::EN_RX_OSD,
                       bsp::VideoSwitch::EN_RX_NO_OSD},
          mWorkQueue{} {}

 public:
    static Instance& GetInstance() {
        static Instance instance;
        return instance;
    }

    Instance(Instance const&) = delete;
    void operator=(Instance const&) = delete;

    void Init() {
        mGraphics.Init();
        mChannel = memoryMap.CreateWatchedObject<Channels::Channel>(Channels::A0);
    }

    Drawing::Graphics& GetGraphics() { return mGraphics; }
    Drawing::WindowManager& GetWindowManager() { return mWindowManager; }
    TouchLib::TouchController& GetTouchController() { return mTouchController; }

    WorkQueue& GetWorkQueue() { return mWorkQueue; }

 private:
    SSD1306 mDisplay;
    Drawing::Graphics mGraphics;
    Drawing::WindowManager mWindowManager;
    TouchLib::TouchController mTouchController;
    MB85RC128 mMemory;
    std::array<RX5808, 3> mVideoRxes;
    ExternalMemoryMap mMemoryMap;
    WatchedExternalMemoryObject<Channels::Channel> mChannel;
    Analog mAnalog;
    VideoSwitch mVideoSwitch;
    WorkQueue mWorkQueue;
};

#endif  // _MICROHAL_INSTANCE_H_
