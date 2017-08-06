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

#ifndef _MICROHAL_WIDGETS_H_
#define _MICROHAL_WIDGETS_H_
/* **************************************************************************************************************************************************
 * INCLUDES
 */
#include <string.h>
#include <functional>

#include "Drawing.h"

/* **************************************************************************************************************************************************
 * CLASS
 */

namespace Drawing {
class NumericUpDown : public Widget {
 private:
    void UpdateValue() {
        char buff[50];
        itoa(mValue, buff, 10);
        mValueLabel.SetText(buff);
    }

 public:
    NumericUpDown(const std::string& aName = "numeric") : Widget{}, mValue{0} {
        mNameLabel.SetText(aName);
        mValueLabel.SetText("0");
    }

    virtual void Draw(Graphics& aGraphics) noexcept override { mContainer.Draw(aGraphics); }

    virtual const Vector2D& GetRequestedSize() const noexcept override { return mContainer.GetRequestedSize(); }

    virtual void HandleSizeChange() noexcept override { mContainer.SetSize(GetSize()); }

    virtual void HandleButtonEvent(const ButtonEvent& aEvent) noexcept override {
        switch (aEvent) {
            case ButtonEvent::LEFT:
                mValue--;
                UpdateValue();
                break;
            case ButtonEvent::RIGHT:
                mValue++;
                UpdateValue();
                break;
            default:
                break;
        }
    }

    virtual void Reset() noexcept override { mContainer.Reset(); }

 private:
    Label mNameLabel{Fonts::RobotoMono::pt8};
    EmptyWidget mSpacer{};
    Label mValueLabel{Fonts::RobotoMono::pt8};
    HContainer mContainer{{mNameLabel, 0.65f}, {mSpacer, 0.1f}, {mValueLabel, 0.25f}};
    int32_t mValue;
};

class Button : public Label {
 public:
    Button(const std::string& aName = "button") : Label{Fonts::RobotoMono::pt8, aName} {}

    virtual void HandleButtonEvent(const ButtonEvent& aEvent) noexcept override {
        switch (aEvent) {
            case ButtonEvent::OK:
                CallbackFunction.emit();
                break;
            default:
                break;
        }
    }

    microhal::Signal<> CallbackFunction{};

 private:
};
}

#endif  // _MICROHAL_WIDGETS_H_
