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
#include "Stringify.h"

/* **************************************************************************************************************************************************
 * CLASS
 */

namespace Drawing {

class Number : public Label {
 public:
    Number(const Font& aFont) : Label{aFont, "0"} {}
    void SetValue(int32_t aValue) { SetText(std::toString(aValue)); }
};

class Range : public Widget {
 private:
 public:
    Range() : mRange{0}, mSelected{false} {}
    void SetRange(float aRange) { mRange = static_cast<uint8_t>(std::round(aRange * mMaxRange)); }
    void SetSelected(bool aSelected) { mSelected = aSelected; }
    virtual void Draw(Graphics& aGraphics) noexcept override {
        if (mRange) {
            for (uint8_t x = 0; x < mMaxRange; x++) {
                for (uint8_t y = 0; y < mMaxRange; y++) {
                    if (x < mRange && y < x) aGraphics.SetPixel({x, mMaxRange - y - 1}, true);
                }
            }
        } else {
            for (uint8_t x = 1; x < mMaxRange - 2; x++) {
                aGraphics.SetPixel({x + 1, x + 1}, true);
                aGraphics.SetPixel({x + 1, mMaxRange - 1 - x}, true);
            }
        }

        if (mSelected) {
            aGraphics.SetPixel({mMaxRange / 2, mMaxRange + 1}, true);
            for (int32_t i = -1; i < 2; i++) {
                aGraphics.SetPixel({mMaxRange / 2 + i, mMaxRange + 2}, true);
            }
        }
    }

 private:
    uint8_t mRange;
    bool mSelected;
    static constexpr uint8_t mMaxRange{10};
};

template <typename T>
class ValueUpDown : public Widget {
 private:
    void UpdateValue() {
        mValueLabel.SetText(std::toString(mValue));
        mDirty = false;
    }

 public:
    ValueUpDown(T& aValue, const std::string& aName = "numeric") : Widget{}, mValue{aValue} { mNameLabel.SetText(aName); }

    virtual void Draw(Graphics& aGraphics) noexcept override {
        if (mDirty) UpdateValue();
        mContainer.Draw(aGraphics);
    }

    virtual void Enable(bool aEnable) noexcept override { mContainer.Enable(aEnable); }

    virtual const Vector2D& GetRequestedSize() const noexcept override { return mContainer.GetRequestedSize(); }

    virtual void HandleSizeChange() noexcept override { mContainer.SetSize(GetSize()); }

    virtual void HandleButtonEvent(const ButtonEvent& aEvent) noexcept override {
        switch (aEvent) {
            case ButtonEvent::LEFT:
                mValue--;
                mDirty = true;
                break;
            case ButtonEvent::RIGHT:
                mValue++;
                mDirty = true;
                break;
            default:
                break;
        }
    }

    virtual void Reset() noexcept override { mContainer.Reset(); }

 private:
    Label mNameLabel{Fonts::RobotoLight::pt10};
    EmptyWidget mSpacer{};
    Label mValueLabel{Fonts::RobotoLight::pt10};
    HContainer mContainer{{mNameLabel, 0.65f}, {mSpacer, 0.1f}, {mValueLabel, 0.25f}};
    T& mValue;
    bool mDirty = true;
};

class Button : public Label {
 public:
    Button(const std::string& aName = "button") : Label{Fonts::RobotoLight::pt10, aName} {}

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
