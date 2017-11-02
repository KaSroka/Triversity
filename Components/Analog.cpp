/**
 * @license    BSD 3-Clause
 * @copyright  microHAL
 * @version    $Id$
 * @brief
 *
 * @authors    kamil
 * created on: 01-10-2017
 * last modification: 01-10-2017
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

#include "ports/stm32f3xx/device/stm32f3xx.h"

#include "microhal.h"
#include "microhal_bsp.h"

static TimerHandle_t ADCTimer;

void StartADC(TimerHandle_t xTimer) {
    ADC1->CR2 |= ADC_CR2_SWSTART;
}

Analog::Analog() {
    mUpdate.connect(mUpdateSlot, *this);

    RCC->AHBENR |= RCC_AHBENR_DMA1EN;
    RCC->APB2ENR |= RCC_APB2ENR_ADC1EN;

    RCC->CFGR |= RCC_CFGR_ADCPRE_DIV8;

    DMA1_Channel1->CNDTR = 4;
    DMA1_Channel1->CPAR = (uint32_t)&ADC1->DR;
    DMA1_Channel1->CMAR = (uint32_t)&mAdcData;
    DMA1_Channel1->CCR |= 0b01 << DMA_CCR_MSIZE_Pos | 0b01 << DMA_CCR_PSIZE_Pos | DMA_CCR_MINC | DMA_CCR_CIRC | DMA_CCR_TCIE | DMA_CCR_EN;

    ADC1->CR1 |= ADC_CR1_SCAN;
    ADC1->CR2 |= ADC_CR2_EXTTRIG | 0b111 << ADC_CR2_EXTSEL_Pos | ADC_CR2_DMA | ADC_CR2_ADON;
    ADC1->SQR3 |= 6 << ADC_SQR3_SQ1_Pos | 3 << ADC_SQR3_SQ2_Pos | 1 << ADC_SQR3_SQ3_Pos | 4 << ADC_SQR3_SQ4_Pos;
    ADC1->SQR1 |= 3 << ADC_SQR1_L_Pos;
    ADC1->SMPR2 |= 0b111 << ADC_SMPR2_SMP1_Pos | 0b111 << ADC_SMPR2_SMP3_Pos | 0b111 << ADC_SMPR2_SMP4_Pos | 0b111 << ADC_SMPR2_SMP6_Pos;

    NVIC_SetPriority(DMA1_Channel1_IRQn, 5);
    NVIC_EnableIRQ(DMA1_Channel1_IRQn);

    ADCTimer = xTimerCreate("ADC", pdMS_TO_TICKS(20), pdTRUE, NULL, StartADC);
    assert(ADCTimer);
    xTimerStart(ADCTimer, 0);
}

void DMA1_Channel1_IRQHandler(void) {
    BaseType_t xHigherPriorityTaskWoken;
    DMA1->IFCR |= DMA_IFCR_CTCIF1;
    WorkQueue::workQueue.AddFromISR({analog.mUpdate}, xHigherPriorityTaskWoken);
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}
