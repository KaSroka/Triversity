/**
 * @license    BSD 3-Clause
 * @copyright  microHAL
 * @version    $Id$
 * @brief
 *
 * @authors    kamil
 * created on: 16-08-2017
 * last modification: 16-08-2017
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

#ifndef _MICROHAL_WIDGET_H_
#define _MICROHAL_WIDGET_H_
/* **************************************************************************************************************************************************
 * INCLUDES
 */

#include "microhal.h"

#include "ButtonEvent.h"
#include "Graphics.h"
#include "Point.h"
#include "Vector2D.h"

/* **************************************************************************************************************************************************
 * CLASS
 */

enum class ButtonEvent;

namespace Drawing {

class Widget {
 public:
    Widget(const Rectangle& aRectangle = {{0, 0}, {0, 0}}) : mDrawingRectangle{aRectangle}, mIsVisible{true} {}
    void Draw(Graphics&& aGraphics) noexcept {
        if (mIsVisible) Draw(aGraphics);
    }
    virtual void Draw(Graphics& aGraphics) noexcept = 0;
    const Vector2D& GetSize() const noexcept { return mDrawingRectangle.GetSize(); }
    virtual const Vector2D& GetRequestedSize() const noexcept { return GetSize(); }
    const Point& GetPosition() const noexcept { return mDrawingRectangle.GetStartPoint(); }
    const Rectangle& GetDrawingRectangle() const noexcept { return mDrawingRectangle; }
    bool GetVisibility() { return mIsVisible; }
    void SetPosition(const Point& aPoint) noexcept {
        mDrawingRectangle = {aPoint, mDrawingRectangle.GetSize()};
        HandleSizeChange();
    }
    void SetSize(const Vector2D& aSize) noexcept {
        mDrawingRectangle = {mDrawingRectangle.GetStartPoint(), aSize};
        HandleSizeChange();
    }
    void SetDrawingRectangle(const Rectangle& aRectangle) noexcept {
        mDrawingRectangle = aRectangle;
        HandleSizeChange();
    }
    virtual void HandleButtonEvent(const ButtonEvent& aEvent) noexcept {}
    virtual void HandleSizeChange() noexcept {}
    virtual void Reset() noexcept {}
    virtual void Enable(bool aEnable) noexcept {}
    void SetVisibility(bool aIsVisible) { mIsVisible = aIsVisible; }
    virtual ~Widget() {}

 private:
    Rectangle mDrawingRectangle;
    bool mIsVisible;
};
}

#endif  // _MICROHAL_WIDGET_H_
