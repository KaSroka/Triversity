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

#ifndef _MICROHAL_FONT_H_
#define _MICROHAL_FONT_H_
/* **************************************************************************************************************************************************
 * INCLUDES
 */

#include "microhal.h"

/* **************************************************************************************************************************************************
 * CLASS
 */

class Font {
 private:
 public:
    struct FontDescriptor {
        int32_t mWidth;
        int32_t mOffset;
    };

    struct FontInfo {
        int32_t mCharHeight;
        char mStartCharacter;
        char mEndCharacter;
        int32_t mInterCharSpace;
        int32_t mInterLineSpace;
    };

    struct Character {
        const uint8_t* mBitmap;
        int32_t mWidth;
        int32_t mHeight;
        int32_t mInterCharSpace;
        int32_t mInterLineSpace;
    };

    constexpr Font(const FontInfo& aFontInfo, const uint8_t* aFontBitmaps, const FontDescriptor* aFontDescriptors) noexcept
        : mFontInfo(aFontInfo),
          mFontBitmaps(aFontBitmaps),
          mFontDescriptors(aFontDescriptors) {}

    constexpr Character GetChar(char c) const noexcept {
        Character character = {nullptr, 0, mFontInfo.mCharHeight, mFontInfo.mInterCharSpace, mFontInfo.mInterLineSpace};
        if ((c >= mFontInfo.mStartCharacter) && (c <= mFontInfo.mEndCharacter)) {
            c -= mFontInfo.mStartCharacter;
            character.mBitmap = &mFontBitmaps[mFontDescriptors[c].mOffset];
            character.mWidth = mFontDescriptors[c].mWidth;
        }
        return character;
    }

    constexpr const FontInfo& GetFontInfo() const noexcept { return mFontInfo; }

 private:
    const FontInfo& mFontInfo;
    const uint8_t* mFontBitmaps;
    const FontDescriptor* mFontDescriptors;
};

#endif  // _MICROHAL_FONT_H_
