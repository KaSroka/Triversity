/**
 * @license    BSD 3-Clause
 * @copyright  microHAL
 * @version    $Id$
 * @brief
 *
 * @authors    kamil
 * created on: 21-08-2017
 * last modification: 21-08-2017
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

#ifndef _MICROHAL_LABEL_H_
#define _MICROHAL_LABEL_H_
/* **************************************************************************************************************************************************
 * INCLUDES
 */

#include <chrono>

#include "Fonts.h"
#include "Point.h"
#include "Widget.h"

/* **************************************************************************************************************************************************
 * CLASS
 */

using namespace std::chrono_literals;

namespace Drawing {

class Label : public Widget {
 private:
    void CalculateRequiredSize() noexcept {
        Vector2D calculatedSize{0, 0};
        for (auto& c : mText) {
            auto character = mCurrentFont->GetChar(c);
            calculatedSize += {character.mWidth + character.mInterCharSpace, 0};
        }
        calculatedSize += {0, mCurrentFont->GetFontInfo().mCharHeight};

        mRequestedSize = calculatedSize;
    }

    void DrawInternal(Graphics&& aGraphics) const noexcept {
        Point writePos{0, 0};
        for (auto& c : mText) {
            auto character = mCurrentFont->GetChar(c);
            aGraphics.PutC(writePos, character);
            writePos += {character.mWidth + character.mInterCharSpace, 0};
        }
    }

 public:
    Label(const Font& aFont, const Rectangle& aRectangle = {{0, 0}, {0, 0}}) noexcept : Widget{aRectangle},
                                                                                        mRequestedSize{0, 0},
                                                                                        mCurrentFont{&aFont},
                                                                                        mScrollPos{0} {
        SetText("Label");
    }
    Label(const Font& aFont, const std::string& aText, const Rectangle& aRectangle = {{0, 0}, {0, 0}}) noexcept : Widget{aRectangle},
                                                                                                                  mRequestedSize{0, 0},
                                                                                                                  mCurrentFont{&aFont},
                                                                                                                  mScrollPos{0} {
        SetText(aText);
    }
    virtual void Enable(bool aEnable) noexcept override {
        mEnabled = aEnable;
        Reset();
    }
    void SetFont(const Font& aFont) noexcept { mCurrentFont = &aFont; }
    void SetText(const std::string& aText) noexcept {
        mText = aText;
        CalculateRequiredSize();
        Reset();
    }

    virtual void Draw(Graphics& aGraphics) noexcept override {
        if (mRequestedSize.GetX() > GetSize().GetX() && mEnabled && mScrollHold) {
            auto timeNow = std::chrono::system_clock::now();
            if ((timeNow - mLastPosUpdate) > mHoldTime) {
                mScrollHold = false;
                mLastPosUpdate = timeNow;
            }
        } else if (mRequestedSize.GetX() > GetSize().GetX() && mEnabled) {
            auto timeNow = std::chrono::system_clock::now();
            mAccumulatedDelta += std::chrono::duration_cast<std::chrono::milliseconds>(timeNow - mLastPosUpdate).count() / 1000.0f;
            float offset = mSpeed * mAccumulatedDelta;
            mAccumulatedDelta = (offset - std::floor(offset)) / mSpeed;
            mScrollPos = (mScrollPos + static_cast<int32_t>(std::floor(offset))) % (mRequestedSize.GetX() + 25);
            mLastPosUpdate = timeNow;

            DrawInternal(aGraphics.CreateView({{-mScrollPos + mRequestedSize.GetX() + 25, 0}, mRequestedSize}));
        } else {
            Reset();
        }
        DrawInternal(aGraphics.CreateView({{-mScrollPos, 0}, mRequestedSize}));
    }

    virtual const Vector2D& GetRequestedSize() const noexcept override { return mRequestedSize; }
    virtual void Reset() noexcept override {
        mLastPosUpdate = std::chrono::system_clock::now();
        mScrollPos = 0;
        mAccumulatedDelta = 0;
        mScrollHold = true;
    }

 private:
    Vector2D mRequestedSize;
    std::string mText;
    const Font* mCurrentFont;
    int32_t mScrollPos;
    std::chrono::system_clock::time_point mLastPosUpdate;
    float mAccumulatedDelta;
    bool mEnabled{false};
    bool mScrollHold{true};
    static constexpr float mSpeed{15.0f};
    const std::chrono::milliseconds mHoldTime{700ms};
};
}

#endif  // _MICROHAL_LABEL_H_
