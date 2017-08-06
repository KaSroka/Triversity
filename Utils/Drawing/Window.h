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

#ifndef _MICROHAL_WINDOW_H_
#define _MICROHAL_WINDOW_H_
/* **************************************************************************************************************************************************
 * INCLUDES
 */
#include <functional>
#include <initializer_list>
#include <vector>

#include "microhal.h"

#include "ButtonEvent.h"
#include "Vector2D.h"
#include "Widget.h"

/* **************************************************************************************************************************************************
 * CLASS
 */

namespace Drawing {

class Window {
 private:
    void CalculateRequiredSize() noexcept {
        Vector2D size{0, 0};
        if (!mWidgets.empty()) {
            Point min = mWidgets[0].get().GetPosition();
            Point max = mWidgets[0].get().GetPosition() + mWidgets[0].get().GetSize();

            for (auto& widget : mWidgets) {
                min.GetMinCoords(widget.get().GetPosition());
                max.GetMaxCoords(widget.get().GetPosition() + widget.get().GetSize());
            }
            size = max - min;
        }

        mRequestedSize = size;
    }

 public:
    Window(std::initializer_list<std::reference_wrapper<Widget>> aInitList, const Rectangle& aRectangle = {{0, 0}, {0, 0}})
        : mWidgets{aInitList}, mRequestedSize{0, 0}, mDrawingRectangle{aRectangle} {
        CalculateRequiredSize();
    }
    const Vector2D& GetRequestedSize() const noexcept { return mRequestedSize; }

    void Draw(Graphics&& aGraphics) {
        for (auto& widget : mWidgets) {
            widget.get().Draw(aGraphics.CreateView(widget.get().GetDrawingRectangle()));
        }
    }

    const Vector2D& GetSize() const noexcept { return mDrawingRectangle.GetSize(); }
    const Point& GetPosition() const noexcept { return mDrawingRectangle.GetStartPoint(); }
    const Rectangle& GetDrawingRectangle() const noexcept { return mDrawingRectangle; }
    void SetPosition(const Point& aPoint) noexcept { mDrawingRectangle = {aPoint, mDrawingRectangle.GetSize()}; }
    void SetSize(const Vector2D& aSize) noexcept { mDrawingRectangle = {mDrawingRectangle.GetStartPoint(), aSize}; }
    void SetDrawingRectangle(const Rectangle& aRectangle) noexcept { mDrawingRectangle = aRectangle; }
    void Reset() noexcept {
        for (auto& widget : mWidgets) {
            widget.get().Reset();
        }
    }
    virtual void HandleButtonEvent(const ButtonEvent& aEvent) noexcept {}

    virtual ~Window() {}

 private:
    std::vector<std::reference_wrapper<Widget>> mWidgets;
    Vector2D mRequestedSize;
    Rectangle mDrawingRectangle;
};
}

#endif  // _MICROHAL_WINDOW_H_
