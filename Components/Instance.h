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
#include "MB85RC128.h"
#include "Memory.h"
#include "RX5808.h"
#include "SSD1306.h"
#include "SwitchingAlgorithm.h"
#include "TouchController.h"
#include "VideoSwitch.h"
#include "WindowManager.h"
#include "Windows.h"
#include "WorkQueue.h"

/* **************************************************************************************************************************************************
 * CLASS
 */

class Instance {
 private:
    Instance()
        : mWorkQueue{},
          mMemory{bsp::Memory::i2c},
          mMemoryMap{mMemory},
          mDisplay{bsp::Display::spi, bsp::Display::CS, bsp::Display::DC, bsp::Display::Reset},
          mGraphics{mDisplay},
          mWindowManager{},
          mTouchController{},
          mVideoRxes{Video::RX5808{bsp::VideoRx::spi, bsp::VideoRx::A::CS}, Video::RX5808{bsp::VideoRx::spi, bsp::VideoRx::B::CS},
                     Video::RX5808{bsp::VideoRx::spi, bsp::VideoRx::C::CS}},
          mVideoSwitch{{bsp::VideoSwitch::EN_RX_1, bsp::VideoSwitch::EN_RX_2, bsp::VideoSwitch::EN_RX_3},
                       bsp::VideoSwitch::EN_RX_OSD,
                       bsp::VideoSwitch::EN_RX_NO_OSD},
          mAnalog{mMemoryMap},
          mAlgorithm{},
          mStatusBar{},
          mSubWindow{},
          mMainWindow{mSubWindow, mMemoryMap} {}

    static Instance& GetInstance() {
        static Instance instance;
        return instance;
    }

    static void UpdateRxChannel() {
        for (auto& videoRx : GetVideoRxes()) {
            videoRx.SetChannel(GetMainWindow().GetChannel());
        }
    }

 public:
    Instance(Instance const&) = delete;
    void operator=(Instance const&) = delete;

    static void Init() {
        GetAnalog().Init();
        GetGraphics().Init();

        GetSubWindow().SetParent(GetMainWindow());

        GetWindowManager().SetStatusBar(GetStatusBar());
        GetWindowManager().SetCurrentWindow(GetMainWindow());

        UpdateRxChannel();

        GetTouchController().buttonOk.Click.connect([](WorkRequestArg& aArg) { GetWindowManager().HandleButtonEvent(ButtonEvent::OK); });
        GetTouchController().buttonUp.Click.connect([](WorkRequestArg& aArg) { GetWindowManager().HandleButtonEvent(ButtonEvent::UP); });
        GetTouchController().buttonDown.Click.connect([](WorkRequestArg& aArg) { GetWindowManager().HandleButtonEvent(ButtonEvent::DOWN); });
        GetTouchController().buttonLeft.Click.connect([](WorkRequestArg& aArg) { GetWindowManager().HandleButtonEvent(ButtonEvent::LEFT); });
        GetTouchController().buttonRight.Click.connect([](WorkRequestArg& aArg) { GetWindowManager().HandleButtonEvent(ButtonEvent::RIGHT); });
        GetSwitchingAlgorithm().UpdateChannel.connect([](WorkRequestArg& aArg) {
            GetStatusBar().SetSelectedRx(aArg.Channel);
            GetVideoSwitch().SelectRx(aArg.Channel);
        });
        GetAnalog().VoltageUpdate.connect([](WorkRequestArg& aArg) { GetStatusBar().SetVoltage(aArg.Voltage); });
        GetAnalog().RSSIUpdate.connect([](WorkRequestArg& aArg) {
            GetStatusBar().SetRSSI(aArg.RSSI1, 0);
            GetStatusBar().SetRSSI(aArg.RSSI2, 1);
            GetStatusBar().SetRSSI(aArg.RSSI3, 2);
            GetSwitchingAlgorithm().Update({aArg.RSSI1, aArg.RSSI2, aArg.RSSI3});
        });
        GetMainWindow().GetChannel().Updated.connect([](WorkRequestArg& aArg) { UpdateRxChannel(); });
    }

    static WorkQueue& GetWorkQueue() { return GetInstance().mWorkQueue; }
    static Memory::ExternalMemoryMap& GetMemoryMap() { return GetInstance().mMemoryMap; }
    static Drawing::Graphics& GetGraphics() { return GetInstance().mGraphics; }
    static Drawing::WindowManager& GetWindowManager() { return GetInstance().mWindowManager; }
    static TouchLib::TouchController& GetTouchController() { return GetInstance().mTouchController; }
    static std::array<Video::RX5808, 3>& GetVideoRxes() { return GetInstance().mVideoRxes; }
    static Video::VideoSwitch& GetVideoSwitch() { return GetInstance().mVideoSwitch; }
    static Analog& GetAnalog() { return GetInstance().mAnalog; }
    static SwitchingAlgorithm& GetSwitchingAlgorithm() { return GetInstance().mAlgorithm; }
    static Drawing::StatusBar& GetStatusBar() { return GetInstance().mStatusBar; }
    static Drawing::SubWindow& GetSubWindow() { return GetInstance().mSubWindow; }
    static Drawing::MainWindow& GetMainWindow() { return GetInstance().mMainWindow; }

 private:
    WorkQueue mWorkQueue;
    Memory::MB85RC128 mMemory;
    Memory::ExternalMemoryMap mMemoryMap;
    SSD1306 mDisplay;
    Drawing::Graphics mGraphics;
    Drawing::WindowManager mWindowManager;
    TouchLib::TouchController mTouchController;
    std::array<Video::RX5808, 3> mVideoRxes;
    Video::VideoSwitch mVideoSwitch;
    Analog mAnalog;
    SwitchingAlgorithm mAlgorithm;

    Drawing::StatusBar mStatusBar;
    Drawing::SubWindow mSubWindow;
    Drawing::MainWindow mMainWindow;
};

#endif  // _MICROHAL_INSTANCE_H_
