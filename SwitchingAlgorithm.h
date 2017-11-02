/**
 * @license    BSD 3-Clause
 * @copyright  microHAL
 * @version    $Id$
 * @brief
 *
 * @authors    kamil
 * created on: 28-10-2017
 * last modification: 28-10-2017
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

#ifndef _MICROHAL_SWITCHINGALGORITHM_H_
#define _MICROHAL_SWITCHINGALGORITHM_H_
/* **************************************************************************************************************************************************
 * INCLUDES
 */

#include <chrono>

#include "microhal.h"

#include "VideoSwitch.h"

/* **************************************************************************************************************************************************
 * CLASS
 */

template <size_t rxn>
class SwitchingAlgorithm {
 private:
 public:
    void Update(std::array<float, rxn> &aRSSI) {
        auto max = std::max_element(aRSSI.begin(), aRSSI.end());
        auto maxIdx = std::distance(aRSSI.begin(), max);
        auto timeNow = std::chrono::system_clock::now();

        if (maxIdx != mCurrentSwitch && ((*max - aRSSI[mCurrentSwitch]) > mCriticalTreshold ||
                                         std::chrono::duration_cast<std::chrono::milliseconds>(timeNow - mLastSwitchTime).count() > 700)) {
            mLastSwitchTime = timeNow;
            // Switch to max_idx
        }
    }

 private:
    VideoSwitch &mSwitch;
    std::chrono::system_clock::time_point mLastSwitchTime;
    float mCriticalTreshold{0.2f};
    std::chrono::duration mSwitchTimeout{1s};
    size_t mCurrentSwitch{0};
};

#endif  // _MICROHAL_SWITCHINGALGORITHM_H_
