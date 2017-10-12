/**
 * @license    BSD 3-Clause
 * @copyright  microHAL
 * @version    $Id$
 * @brief
 *
 * @authors    kamil
 * created on: 27-08-2017
 * last modification: 27-08-2017
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

#include <chrono>
#include <thread>

#include "microhal.h"
#include "microhal_bsp.h"

#include "DrawCall.h"
#include "Graphics.h"
#include "Window.h"

using namespace std::literals::chrono_literals;

static volatile UBaseType_t uxHighWaterMarkwm;

void Drawing::WindowManager::ManagerThread(void* arg) noexcept {
    auto& wm = *static_cast<WindowManager*>(arg);
    auto lastRedraw = std::chrono::system_clock::now();
    while (1) {
        if (wm.mWindow != wm.mNewWindow) {
            if (wm.mWindow) wm.mWindow->Reset();
            wm.mWindow = wm.mNewWindow;
            if (wm.mWindow) wm.mWindow->Reset();
        }
        if (wm.mStatusBar != wm.mNewStatusBar) {
            if (wm.mStatusBar) wm.mStatusBar->Reset();
            wm.mStatusBar = wm.mNewStatusBar;
            if (wm.mStatusBar) wm.mStatusBar->Reset();
        }
        {
            std::unique_lock<std::mutex> lock{wm.mMutex};
            DrawCall drawCall{graphics};
            graphics.Fill(false);

            if (wm.mStatusBar) {
                wm.mStatusBar->Draw(graphics.CreateView(wm.mStatusBar->GetDrawingRectangle()));
            }
            if (wm.mWindow) {
                wm.mWindow->Draw(graphics.CreateView(wm.mWindow->GetDrawingRectangle()));
            }
        }
        std::this_thread::sleep_until(lastRedraw + 20ms);
        lastRedraw = std::chrono::system_clock::now();

        uxHighWaterMarkwm = uxTaskGetStackHighWaterMark(NULL);
    }
}
