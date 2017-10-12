/**
 * @license    BSD 3-Clause
 * @copyright  microHAL
 * @version    $Id$
 * @brief
 *
 * @authors    kamil
 * created on: 29-08-2017
 * last modification: 29-08-2017
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

#ifndef _MICROHAL_WINDOWS_H_
#define _MICROHAL_WINDOWS_H_
/* **************************************************************************************************************************************************
 * INCLUDES
 */

#include <array>

#include "Drawing.h"
#include "Memory.h"

/* **************************************************************************************************************************************************
 * CLASS
 */

namespace Drawing {
class StatusBar : public Window {
 public:
    StatusBar() : Window{{container}, {{0, 0}, {128, 16}}} { container.SetSize(GetSize()); }

    void SetVoltage(float aVoltage) { voltage.SetValue((int32_t)(aVoltage * 10 / 3.0f)); }
    void SetRSSI(float aRSSI, size_t aChannel) { rssi[aChannel].SetRange((aRSSI * 10 - 2.0f) / 3.5f); }
    void SetSelectedRx(size_t aSelected) {
        for (size_t i = 0; i < rssi.size(); i++) {
            rssi[i].SetSelected(i == aSelected);
        }
    }

 private:
    Number voltage{Fonts::RobotoLight::pt10};
    Label vSign{Fonts::RobotoLight::pt10, "V"};
    std::array<Label, 3> rssiNum{{{Fonts::RobotoLight::pt10, "1"}, {Fonts::RobotoLight::pt10, "2"}, {Fonts::RobotoLight::pt10, "3"}}};
    std::array<Range, 3> rssi{};
    EmptyWidget spacer{};
    HContainer container{{voltage, 1.0f},    {spacer, 0.6f},  {rssiNum[2], 0.3f}, {rssi[2], 0.5f},    {spacer, 0.3f},
                         {rssiNum[0], 0.3f}, {rssi[0], 0.5f}, {spacer, 0.3f},     {rssiNum[1], 0.3f}, {rssi[1], 0.5f}};
};

class MainWindow : public Window {
 private:
    void JumpToChild() { windowManager.SetCurrentWindow(mChild); }

 public:
    MainWindow(Window& aChild, WatchedExternalMemoryObject<Channels::Channel>& aChannel)
        : Window{{mList}, {{0, 16}, {128, 48}}}, mChild{&aChild}, mChannel{aChannel, "Channel:"} {
        mList.SetSize(GetSize());
        mChildButton.CallbackFunction.connect(mSubMenu, *this);
    }
    virtual void HandleButtonEvent(const ButtonEvent& aEvent) noexcept override {
        switch (aEvent) {
            case ButtonEvent::UP:
                mList.ScrollUp();
                break;
            case ButtonEvent::DOWN:
                mList.ScrollDown();
                break;
            default:
                mList.HandleButtonEvent(aEvent);
                break;
        }
    }

 private:
    Window* mChild;
    ValueUpDown<WatchedExternalMemoryObject<Channels::Channel>> mChannel;
    Button mChildButton{"Sub menu"};
    microhal::Slot_0<MainWindow, &MainWindow::JumpToChild> mSubMenu{};
    ScrollableList mList{mChannel, mChildButton};
};

class SubWindow : public Window {
 private:
    void Exit() { windowManager.SetCurrentWindow(mParent); }

 public:
    SubWindow() : Window{{mList}, {{0, 16}, {128, 48}}}, mParent{nullptr} {
        mList.SetSize(GetSize());
        mExitButton.CallbackFunction.connect(mExit, *this);
    }
    void SetParent(Window& aParent) noexcept { mParent = &aParent; }
    virtual void HandleButtonEvent(const ButtonEvent& aEvent) noexcept override {
        switch (aEvent) {
            case ButtonEvent::UP:
                mList.ScrollUp();
                break;
            case ButtonEvent::DOWN:
                mList.ScrollDown();
                break;
            default:
                mList.HandleButtonEvent(aEvent);
                break;
        }
    }

 private:
    Window* mParent;
    int32_t value1{0};
    int32_t value2{0};
    ValueUpDown<int32_t> mWidget1{value1, "Sub menu value 1"};
    ValueUpDown<int32_t> mWidget2{value2, "Sub menu value 2"};
    Button mExitButton{"Exit"};
    ScrollableList mList{mWidget1, mWidget2, mExitButton};
    microhal::Slot_0<SubWindow, &SubWindow::Exit> mExit{};
};
}

#endif  // _MICROHAL_WINDOWS_H_
