/**
 * @license    BSD 3-Clause
 * @copyright  microHAL
 * @version    $Id$
 * @brief
 *
 * @authors    kamil
 * created on: 13-08-2017
 * last modification: 13-08-2017
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

#ifndef _MICROHAL_TOUCHCONTROLLER_H_
#define _MICROHAL_TOUCHCONTROLLER_H_
/* **************************************************************************************************************************************************
 * INCLUDES
 */
#include "microhal.h"
#include "tsl.h"

#include "TouchControllerInternals.h"
#include "WorkRequest.h"

/* **************************************************************************************************************************************************
 * CLASS
 */

namespace TouchLib {

#define ROT_1_UP_IO_MSK (TSL_GROUP2_IO2)
#define ROT_1_UP_GRP_MSK (TSL_GROUP2)
#define ROT_1_UP_SRC (1)   // Index in source register (TSC->IOGXCR[])
#define ROT_1_UP_DEST (0)  // Index in destination result array

#define ROT_2_RIGHT_IO_MSK (TSL_GROUP1_IO1)
#define ROT_2_RIGHT_GRP_MSK (TSL_GROUP1)
#define ROT_2_RIGHT_SRC (0)   // Index in source register (TSC->IOGXCR[])
#define ROT_2_RIGHT_DEST (1)  // Index in destination result array

#define ROT_3_DOWN_IO_MSK (TSL_GROUP3_IO1)
#define ROT_3_DOWN_GRP_MSK (TSL_GROUP3)
#define ROT_3_DOWN_SRC (2)   // Index in source register (TSC->IOGXCR[])
#define ROT_3_DOWN_DEST (2)  // Index in destination result array

#define ROT_4_LEFT_IO_MSK (TSL_GROUP6_IO1)
#define ROT_4_LEFT_GRP_MSK (TSL_GROUP6)
#define ROT_4_LEFT_SRC (5)   // Index in source register (TSC->IOGXCR[])
#define ROT_4_LEFT_DEST (3)  // Index in destination result array

#define KEY_IO_MSK (TSL_GROUP3_IO2)
#define KEY_GRP_MSK (TSL_GROUP3)
#define KEY_SRC (2)   // Index in source register (TSC->IOGXCR[])
#define KEY_DEST (4)  // Index in destination result array

//======================
// Shield IOs definition
//======================

#define SHIELD_IO_MSK (TSL_GROUP4_IO1)  // Must be added in BANK_x_MSK_CHANNELS if used

//=================
// Banks definition
//=================

#define BANK_0_NBCHANNELS (4)
#define BANK_0_MSK_CHANNELS (ROT_1_UP_IO_MSK | ROT_2_RIGHT_IO_MSK | ROT_3_DOWN_IO_MSK | ROT_4_LEFT_IO_MSK | SHIELD_IO_MSK)  // Shield enabled
#define BANK_0_MSK_GROUPS (ROT_1_UP_GRP_MSK | ROT_2_RIGHT_GRP_MSK | ROT_3_DOWN_GRP_MSK | ROT_4_LEFT_GRP_MSK)  // Only these groups will be acquired

#define BANK_1_NBCHANNELS (1)
#define BANK_1_MSK_CHANNELS (KEY_IO_MSK | SHIELD_IO_MSK)  // Shield enabled
#define BANK_1_MSK_GROUPS (KEY_GRP_MSK)                   // Only these groups will be acquired

class TouchKey : public TSL_TouchKeyB_T {
 public:
    constexpr TouchKey(size_t aDataIdx) : mData{}, mParam{}, TSL_TouchKeyB_T{&mData, &mParam, &Internals::Channels_Data[aDataIdx]} {}
    constexpr bool IsClicked() const noexcept { return (mData.Change && mData.StateId == TSL_STATEID_DETECT); }
    constexpr TSL_Object_T CreateObject() const noexcept { return TSL_Object_T{TSL_OBJ_TOUCHKEYB, (TSL_TouchKeyB_T *)this}; }
    constexpr void SetDetectionTresholds(TSL_tThreshold_T aInTrs, TSL_tThreshold_T aOutTrs) noexcept {
        mParam.DetectInTh = aInTrs;
        mParam.DetectOutTh = aOutTrs;
    }

 private:
    TSL_TouchKeyData_T mData;
    TSL_TouchKeyParam_T mParam;
};

class TouchController {
 private:
 public:
    class Button {
     public:
        microhal::Signal<WorkRequestArg &> Click;
        microhal::Signal<WorkRequestArg &> LongClick;
        microhal::Signal<WorkRequestArg &> Release;
    };

    TouchController() noexcept;
    void Init() noexcept;
    TSL_Status_enum_T Process() noexcept;
    void TSCInterruptHandler() noexcept {
        BaseType_t xHigherPriorityTaskWoken = pdFALSE;

#if TSLPRM_TSC_IODEF > 0  // Default = Input Floating
        // Set IO default in Output PP Low to discharge all capacitors
        TSC->CR &= (uint32_t)(~(1 << 4));
#endif
        TSC->ICR |= 0x03;  // Clear EOAF and MCEF flags

        xSemaphoreGiveFromISR(mIntSemaphore, &xHigherPriorityTaskWoken);
        portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
    }

    static void TouchProcess(void *arg);

    microhal::Slot_0<TouchController, &TouchController::TSCInterruptHandler> TSCInterruptSlot;

    Button buttonOk;
    Button buttonUp;
    Button buttonDown;
    Button buttonLeft;
    Button buttonRight;

    std::mutex mutex;

 private:
    SemaphoreHandle_t mIntSemaphore;
    __IO TSL_tTick_ms_T Gv_ECS_last_tick;
};
}

#endif  // _MICROHAL_TOUCHCONTROLLER_H_
