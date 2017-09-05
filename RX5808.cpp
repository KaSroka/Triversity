/**
 * @license    BSD 3-Clause
 * @copyright  microHAL
 * @version    $Id$
 * @brief
 *
 * @authors    kamil
 * created on: 04-09-2017
 * last modification: 04-09-2017
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

#include "RX5808.h"

constexpr Channels::Descriptor::Descriptor(uint32_t aFrequency, Channels::Channel aChannel, const char aName[3])
    : mFrequency{aFrequency}, mChannel{aChannel}, mName{aName} {}

const std::array<Channels::Descriptor, Channels::Channel::END> Channels::mChannels{
    {BAND_FREQUENCIES(A, 5865, 5845, 5825, 5805, 5785, 5765, 5745, 5725), BAND_FREQUENCIES(B, 5733, 5752, 5771, 5790, 5809, 5828, 5847, 5866),
     BAND_FREQUENCIES(E, 5705, 5685, 5665, 5645, 5885, 5905, 5925, 5945), BAND_FREQUENCIES(F, 5740, 5760, 5780, 5800, 5820, 5840, 5860, 5880),
     BAND_FREQUENCIES(R, 5658, 5695, 5732, 5769, 5806, 5843, 5880, 5917), BAND_FREQUENCIES(L, 5362, 5399, 5436, 5473, 5510, 5547, 5584, 5621)}};
