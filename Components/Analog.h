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

#ifndef _ANALOG_H_
#define _ANALOG_H_
/* **************************************************************************************************************************************************
 * INCLUDES
 */
#include <array>

#include "microhal.h"

#include "Memory.h"
#include "WorkQueue.h"

/* **************************************************************************************************************************************************
 * CLASS
 */

extern ExternalMemoryMap memoryMap;

extern "C" void DMA1_Channel1_IRQHandler(void);

class Analog {
 private:
    class Params {
     public:
        class Voltage {
         public:
            static constexpr float UpperRes{100e3};
            static constexpr float LowerRes{24e3};
        };

        class RSSI {
         public:
            static constexpr float UpperRes{4.7e3};
            static constexpr float LowerRes{9.1e3};
        };

        static constexpr uint32_t AdcResolution{12};
        static constexpr uint32_t AdcRange{1 << AdcResolution};
        static constexpr float RefVoltage{3.3f};
    };
    struct AdcData {
        volatile uint16_t mVoltage;
        std::array<volatile uint16_t, 3> mRSSI;
    };

    struct RSSIData {
        ExternalMemoryObject<float> mMin;
        ExternalMemoryObject<float> mMax;
    };

    friend void DMA1_Channel1_IRQHandler(void);
    void Update(WorkRequestArg &aRequest) {
        mVoltage = mAdcData.mVoltage * Params::RefVoltage / Params::AdcRange * (Params::Voltage::LowerRes + Params::Voltage::UpperRes) /
                   Params::Voltage::LowerRes;
        for (size_t i = 0; i < mAdcData.mRSSI.size(); i++) {
            float voltage = mAdcData.mRSSI[i] * Params::RefVoltage / Params::AdcRange * (Params::RSSI::LowerRes + Params::RSSI::UpperRes) /
                            Params::RSSI::LowerRes;

            if (voltage < mRSSIData[i].mMin) mRSSIData[i].mMin = voltage;
            if (voltage > mRSSIData[i].mMax) mRSSIData[i].mMax = voltage;

            mRSSI[i] = (voltage - mRSSIData[i].mMin) / (mRSSIData[i].mMax - mRSSIData[i].mMin);
        }

        WorkQueue::workQueue.Add({VoltageUpdate, GetVoltage()});
        for (size_t i = 0; i < mRSSI.size(); i++) {
            WorkQueue::workQueue.Add({RSSIUpdate[i], GetRSSI(i)});
        }
    }

 public:
    Analog() noexcept;
    float GetVoltage() const noexcept { return mVoltage; }
    float GetRSSI(size_t aChannel) const noexcept { return mRSSI[aChannel]; }

    microhal::Signal<WorkRequestArg &> RSSIUpdate[3];
    microhal::Signal<WorkRequestArg &> VoltageUpdate;

 private:
    microhal::Signal<WorkRequestArg &> mUpdate{};
    microhal::Slot_1<Analog, WorkRequestArg &, &Analog::Update> mUpdateSlot;
    AdcData mAdcData{0, {{0, 0, 0}}};
    float mVoltage{0};
    std::array<float, 3> mRSSI{{0, 0, 0}};
    std::array<RSSIData, 3> mRSSIData{{{memoryMap.CreateObject<float>(3.3f, 0.0f, 3.3f), memoryMap.CreateObject<float>(0.0f, 0.0f, 3.3f)},
                                       {memoryMap.CreateObject<float>(3.3f, 0.0f, 3.3f), memoryMap.CreateObject<float>(0.0f, 0.0f, 3.3f)},
                                       {memoryMap.CreateObject<float>(3.3f, 0.0f, 3.3f), memoryMap.CreateObject<float>(0.0f, 0.0f, 3.3f)}}};
};

#endif  // _ANALOG_H_
