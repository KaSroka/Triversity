/**
 * @license    BSD 3-Clause
 * @copyright  microHAL
 * @version    $Id$
 * @brief
 *
 * @authors    kamil
 * created on: 23-08-2017
 * last modification: 23-08-2017
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

#ifndef _MICROHAL_CONTAINER_H_
#define _MICROHAL_CONTAINER_H_
/* **************************************************************************************************************************************************
 * INCLUDES
 */

#include <functional>
#include <initializer_list>
#include <vector>

#include "microhal.h"

#include "Vector2D.h"
#include "Widget.h"

/* **************************************************************************************************************************************************
 * CLASS
 */

namespace Drawing {
class HContainer : public Widget {
 private:
    void CalculateRequiredSize() noexcept {
        Vector2D size{0, 0};
        if (!mComponents.empty()) {
            int32_t maxY = mComponents[0].widget.get().GetRequestedSize().GetY();
            int32_t sumX = 0;
            for (auto &component : mComponents) {
                Widget &widget = component.widget;
                sumX += widget.GetRequestedSize().GetX();
                maxY = std::max(maxY, widget.GetRequestedSize().GetY());
            }

            size = {sumX, maxY};
        }

        mRequestedSize = size;
    }

    void SetupWidgets() noexcept {
        Point pos{0, 0};
        float sum = 0;

        for (auto &component : mComponents) {
            float &weight = component.weight;
            sum += weight;
        }

        for (auto &component : mComponents) {
            Widget &widget = component.widget;
            float &weight = component.weight;
            Vector2D size{static_cast<int32_t>(GetSize().GetX() * weight / sum), GetSize().GetY()};
            widget.SetDrawingRectangle({pos, size});
            pos += {size.GetX(), 0};
        }
    }

 public:
    struct Component {
        std::reference_wrapper<Widget> widget;
        float weight;
    };
    HContainer(std::initializer_list<Component> aInitList, const Rectangle &aRectangle = {{0, 0}, {0, 0}}) noexcept : Widget{aRectangle},
                                                                                                                      mRequestedSize{0, 0},
                                                                                                                      mComponents{aInitList} {
        CalculateRequiredSize();
        SetupWidgets();
    }

    virtual void Draw(Graphics &aGraphics) noexcept override {
        for (auto &component : mComponents) {
            Widget &widget = component.widget;
            widget.Draw(aGraphics.CreateView(widget.GetDrawingRectangle()));
        }
    }

    virtual const Vector2D &GetRequestedSize() const noexcept override { return mRequestedSize; }

    virtual void HandleSizeChange() noexcept override { SetupWidgets(); }

    Widget &GetComponent(size_t aIdx) { return mComponents[aIdx].widget; }
    virtual void Reset() noexcept override {
        for (auto &component : mComponents) {
            Widget &widget = component.widget;
            widget.Reset();
        }
    }

 private:
    Vector2D mRequestedSize;
    std::vector<Component> mComponents;
};

class VContainer : public Widget {
 private:
    void CalculateRequiredSize() noexcept {
        Vector2D size{0, 0};
        if (!mComponents.empty()) {
            int32_t maxX = mComponents[0].widget.get().GetRequestedSize().GetX();
            int32_t sumY = 0;
            for (auto &component : mComponents) {
                Widget &widget = component.widget;
                sumY += widget.GetRequestedSize().GetY();
                maxX = std::max(maxX, widget.GetRequestedSize().GetX());
            }

            size = {maxX, sumY};
        }

        mRequestedSize = size;
    }

    void SetupWidgets() noexcept {
        Point pos{0, 0};
        float sum = 0;

        for (auto &component : mComponents) {
            float &weight = component.weight;
            sum += weight;
        }

        for (auto &component : mComponents) {
            Widget &widget = component.widget;
            float &weight = component.weight;
            Vector2D size{GetSize().GetX(), static_cast<int32_t>(GetSize().GetY() * weight / sum)};
            widget.SetDrawingRectangle({pos, size});
            pos += {0, size.GetY()};
        }
    }

 public:
    struct Component {
        std::reference_wrapper<Widget> widget;
        float weight;
    };
    VContainer(std::initializer_list<Component> aInitList, const Rectangle &aRectangle = {{0, 0}, {0, 0}}) noexcept : Widget{aRectangle},
                                                                                                                      mRequestedSize{0, 0},
                                                                                                                      mComponents{aInitList} {
        CalculateRequiredSize();
        SetupWidgets();
    }

    virtual void Draw(Graphics &aGraphics) noexcept override {
        for (auto &component : mComponents) {
            Widget &widget = component.widget;
            widget.Draw(aGraphics.CreateView(widget.GetDrawingRectangle()));
        }
    }

    virtual const Vector2D &GetRequestedSize() const noexcept override { return mRequestedSize; }

    virtual void HandleSizeChange() noexcept override { SetupWidgets(); }

 private:
    Vector2D mRequestedSize;
    std::vector<Component> mComponents;
};
}

#endif  // _MICROHAL_CONTAINER_H_
