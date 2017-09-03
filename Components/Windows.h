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

#include "Drawing.h"

/* **************************************************************************************************************************************************
 * CLASS
 */

namespace Drawing {
class StatusBar : public Window {
 public:
    StatusBar() : Window{{container}, {{0, 0}, {128, 16}}} { container.SetSize(GetSize()); }

 private:
    Label label1{Fonts::RobotoMono::pt8, "Status bar placeholder"};
    HContainer container{{label1, 1.0f}};
};

class MainWindow : public Window {
 private:
    void JumpToChild() { windowManager.SetCurrentWindow(mChild); }

 public:
    MainWindow(Window& aChild) : Window{{mList}, {{0, 16}, {128, 48}}}, mChild{&aChild} {
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
    int32_t value{0};
    ValueUpDown<int32_t> mWidget1{value, "Value 1"};
    ValueUpDown<int32_t> mWidget2{value, "Value 2"};
    ValueUpDown<int32_t> mWidget3{value, "Value 3"};
    ValueUpDown<int32_t> mWidget4{value, "Value 4"};
    ValueUpDown<int32_t> mWidget5{value, "Value 5"};
    ValueUpDown<int32_t> mWidget6{value, "Value 6"};
    Button mChildButton{"Sub menu"};
    microhal::Slot_0<MainWindow, &MainWindow::JumpToChild> mSubMenu{};
    ScrollableList mList{mWidget1, mWidget2, mWidget3, mWidget4, mWidget5, mWidget6, mChildButton};
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
