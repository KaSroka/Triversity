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

#ifndef _MICROHAL_VECTOR2D_H_
#define _MICROHAL_VECTOR2D_H_
/* **************************************************************************************************************************************************
 * INCLUDES
 */

#include "microhal.h"

/* **************************************************************************************************************************************************
 * CLASS
 */
namespace Drawing {

class Vector2D {
 public:
    constexpr Vector2D(int32_t aX, int32_t aY) noexcept : mX(aX), mY(aY) {}
    constexpr Vector2D& operator+=(const Vector2D& aRhs) noexcept {
        mX += aRhs.mX;
        mY += aRhs.mY;
        return *this;
    }

    friend constexpr Vector2D operator+(Vector2D aLhs, const Vector2D& aRhs) noexcept {
        aLhs += aRhs;
        return aLhs;
    }

    constexpr Vector2D& operator-=(const Vector2D& aRhs) noexcept {
        mX -= aRhs.mX;
        mY -= aRhs.mY;
        return *this;
    }

    friend constexpr Vector2D operator-(Vector2D aLhs, const Vector2D& aRhs) noexcept {
        aLhs -= aRhs;
        return aLhs;
    }

    constexpr Vector2D& operator=(const Vector2D& aRhs) noexcept {
        mX = aRhs.mX;
        mY = aRhs.mY;
        return *this;
    }

    friend constexpr bool operator<(Vector2D aLhs, const Vector2D& aRhs) noexcept { return (aLhs.mX < aRhs.mX) && (aLhs.mY < aRhs.mY); }
    friend constexpr bool operator<=(Vector2D aLhs, const Vector2D& aRhs) noexcept { return (aLhs.mX <= aRhs.mX) && (aLhs.mY <= aRhs.mY); }
    friend constexpr bool operator>(Vector2D aLhs, const Vector2D& aRhs) noexcept { return (aLhs.mX > aRhs.mX) && (aLhs.mY > aRhs.mY); }
    friend constexpr bool operator>=(Vector2D aLhs, const Vector2D& aRhs) noexcept { return (aLhs.mX >= aRhs.mX) && (aLhs.mY >= aRhs.mY); }
    friend constexpr bool operator==(Vector2D aLhs, const Vector2D& aRhs) noexcept { return (aLhs.mX == aRhs.mX) && (aLhs.mY == aRhs.mY); }
    friend constexpr bool operator!=(Vector2D aLhs, const Vector2D& aRhs) noexcept { return (aLhs.mX != aRhs.mX) && (aLhs.mY != aRhs.mY); }

    constexpr Vector2D& GetMinCoords(const Vector2D& aRhs) noexcept {
        mX = std::min(mX, aRhs.mX);
        mY = std::min(mY, aRhs.mY);
        return *this;
    }

    constexpr Vector2D& GetMaxCoords(const Vector2D& aRhs) noexcept {
        mX = std::max(mX, aRhs.mX);
        mY = std::max(mY, aRhs.mY);
        return *this;
    }

    friend constexpr Vector2D GetMinCoords(Vector2D aLhs, const Vector2D& aRhs) noexcept {
        aLhs.GetMinCoords(aRhs);
        return aLhs;
    }

    friend constexpr Vector2D GetMaxCoords(Vector2D aLhs, const Vector2D& aRhs) noexcept {
        aLhs.GetMaxCoords(aRhs);
        return aLhs;
    }

    constexpr int32_t GetX() const noexcept { return mX; }
    constexpr int32_t GetY() const noexcept { return mY; }

 protected:
    int32_t mX;
    int32_t mY;
};
}

#endif  // _MICROHAL_VECTOR2D_H_
