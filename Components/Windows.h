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
#include "Widgets.h"

#include "FIR.h"

/* **************************************************************************************************************************************************
 * CLASS
 */

namespace Drawing {
class StatusBar : public Window {
 public:
    StatusBar() : Window{{mContainer}, {{0, 0}, {128, 16}}} { mContainer.SetSize(GetSize()); }

    void SetVoltage(float aVoltage) { mVoltage.SetValue((int32_t)(mVoltageFIR.Update(aVoltage) * 10 / 3.0f)); }
    void SetRSSI(float aRSSI, size_t aChannel) { mRssi[aChannel].SetRange(mRssiFIR[aChannel].Update(aRSSI)); }
    void SetSelectedRx(size_t aSelected) {
        for (size_t i = 0; i < mRssi.size(); i++) {
            mRssi[i].SetSelected(i == aSelected);
        }
    }

 private:
    Number mVoltage{Fonts::RobotoLight::pt10};
    FIR mVoltageFIR{};
    Label vSign{Fonts::RobotoLight::pt10, "V"};
    std::array<Label, 3> mRssiNum{{{Fonts::RobotoLight::pt10, "1"}, {Fonts::RobotoLight::pt10, "2"}, {Fonts::RobotoLight::pt10, "3"}}};
    std::array<Range, 3> mRssi{};
    std::array<FIR, 3> mRssiFIR{};
    EmptyWidget mSpacer{};
    HContainer mContainer{{mVoltage, 1.0f},    {mSpacer, 0.6f},  {mRssiNum[2], 0.3f}, {mRssi[2], 0.5f},    {mSpacer, 0.3f},
                          {mRssiNum[0], 0.3f}, {mRssi[0], 0.5f}, {mSpacer, 0.3f},     {mRssiNum[1], 0.3f}, {mRssi[1], 0.5f}};
};

class MainWindow : public Window {
 private:
    void JumpToChild() noexcept;

 public:
    MainWindow(Window& aChild, Memory::ExternalMemoryMap& aMemoryMap)
        : Window{{mList}, {{0, 16}, {128, 48}}},
          mChild{&aChild},
          mChannel{aMemoryMap.CreateWatchedObject<Video::Channels::Channel>(Video::Channels::A0)},
          mChannelUD{mChannel, "Channel:"} {
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

    Memory::WatchedExternalMemoryObject<Video::Channels::Channel>& GetChannel() { return mChannel; }

 private:
    Window* mChild;
    Memory::WatchedExternalMemoryObject<Video::Channels::Channel> mChannel;
    ValueUpDown<Memory::WatchedExternalMemoryObject<Video::Channels::Channel>> mChannelUD;
    Button mChildButton{"Sub menu"};
    microhal::Slot_0<MainWindow, &MainWindow::JumpToChild> mSubMenu{};
    ScrollableList mList{mChannelUD, mChildButton};
};

class SubWindow : public Window {
 private:
    void Exit() noexcept;

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
