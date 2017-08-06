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

#ifndef _MICROHAL_GRAPHICS_H_
#define _MICROHAL_GRAPHICS_H_
/* **************************************************************************************************************************************************
 * INCLUDES
 */

#include "microhal.h"

#include "Display.h"
#include "Font.h"
#include "Point.h"
#include "Rectangle.h"
#include "ValidablePoint.h"
#include "Vector2D.h"

/* **************************************************************************************************************************************************
 * CLASS
 */

namespace Drawing {

class Graphics {
 private:
    class Viewport {
     private:
     public:
        constexpr Viewport(const Vector2D& aTranslation, const Rectangle& aClippingRectangle)
            : mTranslation{aTranslation}, mClippingRectangle{aClippingRectangle} {}

        constexpr Viewport(const Rectangle& aClippingRectangle) : mTranslation{0, 0}, mClippingRectangle{aClippingRectangle} {}

        Viewport CreateNew(const Rectangle& aNewRectangle) {
            Point newStartPoint = GetMaxCoords(mClippingRectangle.GetStartPoint(), mTranslation + aNewRectangle.GetStartPoint());
            Point newEndPoint = GetMinCoords(mClippingRectangle.GetStartPoint() + mClippingRectangle.GetSize(),
                                             mTranslation + aNewRectangle.GetStartPoint() + aNewRectangle.GetSize());
            return Viewport{mTranslation + aNewRectangle.GetStartPoint(), {newStartPoint, newEndPoint - newStartPoint}};
        }

        ValidablePoint TranslatePoint(const ValidablePoint& aPoint) const noexcept {
            ValidablePoint retPoint = aPoint;
            retPoint += mTranslation;
            retPoint.SetValid(retPoint.IsInRectangle(mClippingRectangle));
            return retPoint;
        }

     private:
        Vector2D mTranslation;
        Rectangle mClippingRectangle;
    };

    Graphics(Display& aDisplay, const Viewport& aViewport) : mDisplay{aDisplay}, mViewport{aViewport} {}

 public:
    Graphics(Display& aDisplay) : mDisplay{aDisplay}, mViewport{{{0, 0}, mDisplay.GetSize()}} {}

    void Init() noexcept { mDisplay.Init(); }

    bool SetPixel(const Point& aPoint, bool aColor) noexcept {
        auto point = mViewport.TranslatePoint(aPoint);
        if (point.IsValid()) {
            mDisplay.SetPixel(point, aColor);
        }
        return point.IsValid();
    }

    void Redraw() noexcept { mDisplay.Redraw(); }
    void Fill(bool aColor) { mDisplay.Fill(aColor); }

    Graphics CreateView(const Rectangle& aRectangle) { return Graphics{mDisplay, mViewport.CreateNew(aRectangle)}; }

    Graphics CreateView(const Vector2D& aSize) { return CreateView({{0, 0}, aSize}); }

    void PutC(const Point& aPoint, const Font::Character& aChar) noexcept;

 private:
    Display& mDisplay;
    Viewport mViewport;
};
}

#endif  // _MICROHAL_GRAPHICS_H_
