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

/* **************************************************************************************************************************************************
 * INCLUDES
 */

#include "TouchController.h"
#include "TouchControllerInternals.h"

#include "WorkQueue.h"

namespace TouchController {

#define channel(chann) \
    TSL_ChannelSrc_T { chann##_SRC, chann##_IO_MSK, chann##_GRP_MSK }
#define bank(start, bank_num)                                                                                                                \
    {                                                                                                                                        \
        &Channels_Src[start], &Channels_Dest[start], Internals::Channels_Data, BANK_##bank_num##_NBCHANNELS, BANK_##bank_num##_MSK_CHANNELS, \
            BANK_##bank_num##_MSK_GROUPS                                                                                                     \
    }

CONST TSL_ChannelSrc_T Channels_Src[TSLPRM_TOTAL_CHANNELS] = {channel(ROT_1_UP), channel(ROT_2_RIGHT), channel(ROT_3_DOWN), channel(ROT_4_LEFT),
                                                              channel(KEY)};

CONST TSL_ChannelDest_T Channels_Dest[TSLPRM_TOTAL_CHANNELS] = {
    {ROT_1_UP_DEST}, {ROT_2_RIGHT_DEST}, {ROT_3_DOWN_DEST}, {ROT_4_LEFT_DEST}, {KEY_DEST}};

CONST TSL_Bank_T Banks[TSLPRM_TOTAL_BANKS] = {bank(0, 0), bank(4, 1)};

TouchKey keyOk{KEY_DEST};
TouchKey keyUp{ROT_1_UP_DEST};
TouchKey keyDown{ROT_3_DOWN_DEST};
TouchKey keyLeft{ROT_4_LEFT_DEST};
TouchKey keyRight{ROT_2_RIGHT_DEST};

// Delta Normalization Process
// The MSB is the integer part, the LSB is the real part
// Examples:
// - To apply a factor 1.10:
//   0x01 to the MSB
//   0x1A to the LSB (0.10 x 256 = 25.6 -> rounded to 26 = 0x1A)
// - To apply a factor 0.90:
//   0x00 to the MSB
//   0xE6 to the LSB (0.90 x 256 = 230.4 -> rounded to 230 = 0xE6)
CONST uint16_t LinRot0_DeltaCoeff[4] = {0x0215, 0x00c5, 0x0069, 0x007f};

// LinRots list (ROM)
CONST TSL_LinRot_T LinRots[TSLPRM_TOTAL_LNRTS] = {
    {&Internals::LinRots_Data[0], &Internals::LinRots_Param[0], &Internals::Channels_Data[ROT_1_UP_DEST], 4, LinRot0_DeltaCoeff,
     (TSL_tsignPosition_T *)TSL_POSOFF_4CH_ROT_M, TSL_SCTCOMP_4CH_ROT_M, 0, Internals::LinRots_StateMachine, &Internals::LinRots_Methods}};

//==============================================================================
// Generic Objects
//==============================================================================

CONST TSL_Object_T Objects[TSLPRM_TOTAL_OBJECTS] = {keyOk.CreateObject(),   keyUp.CreateObject(),    keyDown.CreateObject(),
                                                    keyLeft.CreateObject(), keyRight.CreateObject(), {TSL_OBJ_ROTARY, (TSL_LinRot_T *)&LinRots[0]}};

// Group (RAM)
TSL_ObjectGroup_T MyObjGroup = {
    &Objects[0],           // First object
    TSLPRM_TOTAL_OBJECTS,  // Number of objects
    0x00,                  // State mask reset value
    TSL_STATE_NOT_CHANGED  // Current state
};

void TouchController::TouchProcess(void *arg) {
    TouchController *touchController = static_cast<TouchController *>(arg);
    while (1) {
        if (touchController->Process() == TSL_STATUS_OK) {
            if (keyOk.IsClicked()) {
                WorkQueue::workQueue.Add({touchController->buttonOk.Click});
            }
            if (keyUp.IsClicked()) {
                WorkQueue::workQueue.Add({touchController->buttonUp.Click});
            }
            if (keyDown.IsClicked()) {
                WorkQueue::workQueue.Add({touchController->buttonDown.Click});
            }
            if (keyLeft.IsClicked()) {
                WorkQueue::workQueue.Add({touchController->buttonLeft.Click});
            }
            if (keyRight.IsClicked()) {
                WorkQueue::workQueue.Add({touchController->buttonRight.Click});
            }
            //            if (LinRots[0].p_Data->Change && LinRots[0].p_Data->StateId == TSL_STATEID_DETECT) {
            //                detectPosition = LinRots[0].p_Data->Position;
            //            } else if (LinRots[0].p_Data->PosChange && LinRots[0].p_Data->StateId == TSL_STATEID_DETECT &&
            //                       detectPosition != LinRots[0].p_Data->Position && !LinRots[0].p_Data->Change) {
            //                value += LinRots[0].p_Data->Direction ? -1 : 1;
            //            }
        }
    }
}

TouchController::TouchController() {
    mIntSemaphore = xSemaphoreCreateBinary();

    xTaskCreate(TouchProcess, "TP", 256, this, configMAX_PRIORITIES - 1, nullptr);
}

void TouchController::Init() {
#if TSLPRM_TSC_GPIO_CONFIG == 0
    // Automatic GPIO configuration not selected:
    // This function must be created by the user to initialize the Touch Sensing GPIOs.
    TSL_user_InitGPIOs();
#endif

    TSL_obj_GroupInit(&MyObjGroup);  // Init Objects

    TSL_Init(Banks);  // Init timing and acquisition modules

    keyUp.SetDetectionTresholds(30, 25);
    keyRight.SetDetectionTresholds(80, 75);
    keyDown.SetDetectionTresholds(180, 175);
    keyLeft.SetDetectionTresholds(130, 125);
    //    LinRots_Param[0].DetectInTh = 30;
    //    LinRots_Param[0].DetectOutTh = 25;
    //    LinRots_Param[1].DetectInTh = 80;
    //    LinRots_Param[1].DetectOutTh = 75;
    //    LinRots_Param[2].DetectInTh = 180;
    //    LinRots_Param[2].DetectOutTh = 175;
    //    LinRots_Param[3].DetectInTh = 130;
    //    LinRots_Param[3].DetectOutTh = 125;
}

TSL_Status_enum_T TouchController::Process() {
    static uint32_t idx_bank = 0;
    static uint32_t config_done = 0;
    TSL_Status_enum_T status;

    mutex.lock();

    // Configure bank
    if (!config_done) {
        TSL_acq_BankConfig(idx_bank);  // Configure Bank
        TSL_acq_BankStartAcq();        // Start Bank acquisition
        config_done = 1;
    }

// Check end of acquisition
#if TSLPRM_USE_ACQ_INTERRUPT > 0
    mutex.unlock();
    xSemaphoreTake(mIntSemaphore, portMAX_DELAY);
    mutex.lock();
#else
    if (TSL_acq_BankWaitEOC() == TSL_STATUS_OK)
#endif
    {
        TSL_acq_BankGetResult(idx_bank, 0, 0);  // Get Bank Result
        idx_bank++;                             // Next bank
        config_done = 0;
    }

    // Process objects, DxS and ECS
    // Check if all banks have been acquired
    if (idx_bank > TSLPRM_TOTAL_BANKS - 1) {
        // Reset flags for next banks acquisition
        idx_bank = 0;
        config_done = 0;

        // Process Objects
        TSL_obj_GroupProcess(&MyObjGroup);

        // DxS processing (if TSLPRM_USE_DXS option is set)
        TSL_dxs_FirstObj(&MyObjGroup);

        // ECS every 100ms
        if (TSL_tim_CheckDelay_ms(100, &Gv_ECS_last_tick) == TSL_STATUS_OK) {
            if (TSL_ecs_Process(&MyObjGroup) == TSL_STATUS_OK) {
            } else {
            }
        }

        status = TSL_STATUS_OK;  // All banks have been acquired and sensors processed

    } else {
        status = TSL_STATUS_BUSY;
    }

    mutex.unlock();
    return status;
}
}
