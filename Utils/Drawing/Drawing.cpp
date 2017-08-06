/**
 * @license    BSD 3-Clause
 * @copyright  microHAL
 * @version    $Id$
 * @brief
 *
 * @authors    kamil
 * created on: 08-08-2017
 * last modification: 08-08-2017
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

/* **************************************************************************************************************************************************
 * INCLUDES
 */

#include <algorithm>

#include "Drawing.h"

namespace Drawing {

void Graphics::PutC(const Point& aPoint, const Font::Character& aChar) noexcept {
    auto topLeft = mViewport.TranslatePoint(aPoint);
    auto topRight = mViewport.TranslatePoint(aPoint + Point{aChar.mWidth - 1, 0});
    auto bottomLeft = mViewport.TranslatePoint(aPoint + Point{0, aChar.mHeight - 1});
    auto bottomRight = mViewport.TranslatePoint(aPoint + Point{aChar.mWidth - 1, aChar.mHeight - 1});

    if (!(topLeft.IsValid() || topRight.IsValid() || bottomLeft.IsValid() || bottomRight.IsValid())) {
        return;  // None of corners are visible - assume that char is clipped
    }

    for (int32_t y_byte = 0; y_byte < ((aChar.mHeight + 8 - 1) >> 3); y_byte++) {
        for (int32_t x = 0; x < aChar.mWidth; x++) {
            uint8_t bitmap = aChar.mBitmap[x + y_byte * aChar.mWidth];
            for (int32_t y = 0; y < std::min(8L, (aChar.mHeight - (y_byte << 3))); y++) {
                // SetPixelRaw(translation + Point{x, y + (y_byte << 3)}, static_cast<bool>(bitmap & (1 << y)));
                SetPixel(aPoint + Point{x, y + (y_byte << 3)}, static_cast<bool>(bitmap & (1 << y)));
            }
        }
    }
}

WindowManager windowManager{};
}
