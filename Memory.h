/**
 * @license    BSD 3-Clause
 * @copyright  microHAL
 * @version    $Id$
 * @brief
 *
 * @authors    kamil
 * created on: 03-09-2017
 * last modification: 03-09-2017
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

#ifndef _MICROHAL_MEMORY_H_
#define _MICROHAL_MEMORY_H_
/* **************************************************************************************************************************************************
 * INCLUDES
 */

#include <limits>

#include "microhal.h"

#include "Stringify.h"
#include "WorkQueue.h"

/* **************************************************************************************************************************************************
 * CLASS
 */

template <typename T>
class ExternalMemoryObject;

class ExternalMemory {
 public:
    ExternalMemory(size_t aSize) : mSize{aSize} {}
    virtual void ReadRegion(size_t aOffset, size_t aSize, uint8_t *aData) noexcept = 0;
    virtual void WriteRegion(size_t aOffset, size_t aSize, const uint8_t *aData) noexcept = 0;
    size_t GetSize() { return mSize; }
    virtual ~ExternalMemory() {}

 private:
    const size_t mSize;
};

template <typename T>
class ExternalMemoryObject {
 public:
    constexpr ExternalMemoryObject(ExternalMemory &aMemory, size_t aOffset, T aDefault, T aMin = std::numeric_limits<T>::lowest(),
                                   T aMax = std::numeric_limits<T>::max())
        : mMemory{aMemory}, mOffset{aOffset}, mDefault{aDefault}, mMin{aMin}, mMax{aMax} {}
    virtual void Write(const T &aObject) { mMemory.WriteRegion(mOffset, sizeof(T), reinterpret_cast<const uint8_t *>(&aObject)); }
    virtual void Write(const T &&aObject) { mMemory.WriteRegion(mOffset, sizeof(T), reinterpret_cast<const uint8_t *>(&aObject)); }
    T Read() {
        T ret;
        mMemory.ReadRegion(mOffset, sizeof(T), reinterpret_cast<uint8_t *>(&ret));
        if (ret < mMin) {
            ret = mDefault;
            ExternalMemoryObject::Write(mDefault);
        } else if (ret > mMax) {
            ret = mDefault;
            ExternalMemoryObject::Write(mDefault);
        }

        return ret;
    }

    constexpr size_t GetSize() { return sizeof(T); }

    ExternalMemoryObject &operator++() noexcept {
        auto val = Read();
        ++val;
        Write(val);
        return *this;
    }

    ExternalMemoryObject &operator--() noexcept {
        auto val = Read();
        --val;
        Write(val);
        return *this;
    }

    ExternalMemoryObject &operator++(int)noexcept {
        auto val = Read();
        val++;
        Write(val);
        return *this;
    }

    ExternalMemoryObject &operator--(int)noexcept {
        auto val = Read();
        val--;
        Write(val);
        return *this;
    }

    ExternalMemoryObject &operator=(const T &aVal) noexcept {
        Write(aVal);
        return *this;
    }

    ExternalMemoryObject &operator=(const T &&aVal) noexcept {
        Write(aVal);
        return *this;
    }

    operator T() { return Read(); }
    virtual ~ExternalMemoryObject() {}

 private:
    ExternalMemory &mMemory;
    const size_t mOffset;
    T mDefault;
    T mMin;
    T mMax;
};

template <typename T>
class WatchedExternalMemoryObject : public ExternalMemoryObject<T> {
 public:
    WatchedExternalMemoryObject(ExternalMemory &aMemory, size_t aOffset, T aDefault, T aMin = std::numeric_limits<T>::lowest(),
                                T aMax = std::numeric_limits<T>::max())
        : ExternalMemoryObject<T>{aMemory, aOffset, aDefault, aMin, aMax} {}
    virtual void Write(const T &aObject) override {
        ExternalMemoryObject<T>::Write(aObject);
        WorkQueue::workQueue.Add({Updated});
    }
    virtual void Write(const T &&aObject) override {
        ExternalMemoryObject<T>::Write(aObject);
        WorkQueue::workQueue.Add({Updated});
    }

    microhal::Signal<WorkRequestArg &> Updated;
};

class ExternalMemoryMap {
 public:
    ExternalMemoryMap(ExternalMemory &aMemory) : mMemory{aMemory}, mUsedSize{0} {}

    template <typename T>
    ExternalMemoryObject<T> CreateObject(T aDefault, T aMin = std::numeric_limits<T>::lowest(), T aMax = std::numeric_limits<T>::max()) {
        size_t location = mUsedSize;
        mUsedSize += sizeof(T);
        assert(mUsedSize <= mMemory.GetSize());
        return ExternalMemoryObject<T>{mMemory, location, aDefault, aMin, aMax};
    }

    template <typename T>
    WatchedExternalMemoryObject<T> CreateWatchedObject(T aDefault, T aMin = std::numeric_limits<T>::lowest(),
                                                       T aMax = std::numeric_limits<T>::max()) {
        size_t location = mUsedSize;
        mUsedSize += sizeof(T);
        assert(mUsedSize <= mMemory.GetSize());
        return WatchedExternalMemoryObject<T>{mMemory, location, aDefault, aMin, aMax};
    }

 private:
    ExternalMemory &mMemory;
    size_t mUsedSize;
};

#endif  // _MICROHAL_MEMORY_H_
