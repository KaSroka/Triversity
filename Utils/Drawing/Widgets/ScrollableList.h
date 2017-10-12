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

#ifndef _MICROHAL_SCROLLABLELIST_H_
#define _MICROHAL_SCROLLABLELIST_H_
/* **************************************************************************************************************************************************
 * INCLUDES
 */

#include <algorithm>
#include <functional>
#include <initializer_list>
#include <vector>

#include "microhal.h"

#include "Container.h"
#include "Vector2D.h"
#include "Widget.h"
#include "Widgets/Bitmap.h"

/* **************************************************************************************************************************************************
 * CLASS
 */

namespace Drawing {

class ScrollableList : public Widget {
 private:
    void CalculateRequiredSize() noexcept {
        Vector2D size{0, 0};
        if (!mElements.empty()) {
            int32_t maxX = mElements[0].GetRequestedSize().GetX();
            int32_t sumY = 0;
            for (auto &element : mElements) {
                sumY += element.GetRequestedSize().GetY();
                maxX = std::max(maxX, element.GetRequestedSize().GetX());
            }

            size = {maxX, sumY};
        }

        mRequestedSize = size;
    }

    void SetupWidgets() noexcept {
        Point pos{0, 0};

        for (auto &element : mElements) {
            Vector2D size{GetSize().GetX(), element.GetRequestedSize().GetY()};
            element.SetDrawingRectangle({pos, size});
            pos += {0, size.GetY()};
        }
    }

    void UpdateOffset() noexcept {
        auto &selectedElement = mElements[mSelectedElement];
        int32_t startX = selectedElement.GetPosition().GetY();
        int32_t endX = selectedElement.GetPosition().GetY() + selectedElement.GetSize().GetY();
        int32_t currentStartPos = startX - mOffset;
        int32_t currentEndPos = endX - mOffset;
        if (currentStartPos < 0) {
            mOffset = selectedElement.GetPosition().GetY();
            ResetElements();
        } else if (currentEndPos >= GetSize().GetY()) {
            int32_t sum = 0;
            int32_t i = mSelectedElement;
            for (; i >= 0; i--) {
                sum += mElements[i].GetSize().GetY();
                if (sum > GetSize().GetY()) {
                    i++;
                    break;
                }
            }
            mOffset = mElements[i].GetPosition().GetY();
            ResetElements();
        }
    }

    void DrawInternal(Graphics &&aGraphics) noexcept {
        for (Widget &element : mElements) {
            element.Draw(aGraphics.CreateView(element.GetDrawingRectangle()));
        }
    }

    void UpdateArrows() noexcept {
        for (HContainer &element : mElements) {
            element.GetComponent(0).SetVisibility(false);
            element.GetComponent(1).Enable(false);
        }
        mElements[mSelectedElement].GetComponent(0).SetVisibility(true);
        mElements[mSelectedElement].GetComponent(1).Enable(true);
    }

    void ResetElements() noexcept {
        for (auto &element : mElements) {
            element.Reset();
        }
    }

 public:
    ScrollableList(std::initializer_list<std::reference_wrapper<Widget>> aInitList, const Rectangle &aRectangle = {{0, 0}, {0, 0}}) noexcept
        : Widget{aRectangle},
          mRequestedSize{0, 0},
          mElements{},
          mOffset{0},
          mSelectedElement{0} {
        mElements.reserve(aInitList.size());
        for (auto &widget : aInitList) {
            auto arrow = new Arrow{};
            arrow->SetVisibility(false);
            HContainer container{{*arrow, 0.08f}, {widget, 0.92f}};
            mElements.push_back(container);
        }
        CalculateRequiredSize();
        SetupWidgets();
        UpdateArrows();
    }

    virtual void Draw(Graphics &aGraphics) noexcept override {
        DrawInternal(aGraphics.CreateView({{0, -mOffset}, {GetSize().GetX(), GetRequestedSize().GetY()}}));
    }

    virtual const Vector2D &GetRequestedSize() const noexcept override { return mRequestedSize; }

    virtual void HandleSizeChange() noexcept override {
        SetupWidgets();
        UpdateOffset();
    }

    virtual void HandleButtonEvent(const ButtonEvent &aEvent) noexcept override {
        mElements[mSelectedElement].GetComponent(1).HandleButtonEvent(aEvent);
    }

    void ScrollUp() {
        if (mSelectedElement) {
            mSelectedElement--;
            UpdateOffset();
            UpdateArrows();
        }
    }

    void ScrollDown() {
        if (mSelectedElement < (mElements.size() - 1)) {
            mSelectedElement++;
            UpdateOffset();
            UpdateArrows();
        }
    }

    virtual void Reset() noexcept override {
        mOffset = 0;
        mSelectedElement = 0;
        UpdateArrows();
        ResetElements();
    }

 private:
    Vector2D mRequestedSize;
    std::vector<HContainer> mElements;
    int32_t mOffset;
    size_t mSelectedElement;
};
}

#endif  // _MICROHAL_SCROLLABLELIST_H_
