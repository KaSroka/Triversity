/**
 * @license    BSD 3-Clause
 * @copyright  microHAL
 * @version    $Id$
 * @brief
 *
 * @authors    kamil
 * created on: 14-08-2017
 * last modification: 14-08-2017
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

#ifndef _MICROHAL_WORKQUEUET_H_
#define _MICROHAL_WORKQUEUET_H_

/* **************************************************************************************************************************************************
 * INCLUDES
 */

#include "microhal.h"

#include "WorkRequest.h"

using namespace microhal;

namespace WorkQueue {

class WorkQueue {
 public:
    WorkQueue() noexcept {
        mWorkQueue = xQueueCreate(10, sizeof(WorkRequest));
        xTaskCreate(WorkThread, "WQ", configMINIMAL_STACK_SIZE, mWorkQueue, 0, nullptr);
    }

    void Add(WorkRequest aRequest) noexcept { xQueueSend(mWorkQueue, &aRequest, portMAX_DELAY); }

    bool TryAdd(WorkRequest aRequest) noexcept { return xQueueSend(mWorkQueue, &aRequest, portMAX_DELAY) == pdTRUE; }

    bool AddFromISR(WorkRequest aRequest, BaseType_t& aHigherPriorityTaskWoken) noexcept {
        return xQueueSendFromISR(mWorkQueue, &aRequest, &aHigherPriorityTaskWoken) == pdTRUE;
    }

 private:
    static void WorkThread(void* arg) noexcept;

    QueueHandle_t mWorkQueue;
};

extern WorkQueue workQueue;
}

#endif  // _MICROHAL_WORKQUEUET_H_
