#ifndef _MICROHAL_SSD1306_H_
#define _MICROHAL_SSD1306_H_
/* **************************************************************************************************************************************************
 * INCLUDES
 */
#include <Drawing.h>
#include <assert.h>
#include <array>
#include <bitset>
#include <chrono>

#include "SPIDevice/SPIDevice.h"
#include "microhal.h"

using namespace std::literals::chrono_literals;
using namespace Drawing;

/* **************************************************************************************************************************************************
 * CLASS
 */

class SSD1306 : private microhal::SPIDevice, public Display {
 private:
    enum Params { Width = 128, Height = 64 };

    virtual void SetPixel(const Point& aPoint, bool aColor) noexcept override {
        assert(aPoint.GetX() >= 0);
        assert(aPoint.GetX() < Width);
        assert(aPoint.GetY() >= 0);
        assert(aPoint.GetY() < Height);
        mPixels[aPoint.GetX()][aPoint.GetY()] = aColor;
    }
    virtual bool GetPixel(const Point& aPoint) const noexcept override { return mPixels[aPoint.GetX()][aPoint.GetY()]; }
    virtual void Redraw() noexcept override { SPIDevice::writeBuffer(reinterpret_cast<uint8_t*>(&mPixels), Width * Height / 8, true); }
    virtual void Fill(bool aColor) noexcept override { memset(reinterpret_cast<uint8_t*>(&mPixels), aColor ? 0xff : 0, Width * Height / 8); }
    virtual void Init() noexcept override {
        uint8_t initSequence[] = {0x20, 0x01, 0xa1, 0xc8, 0xda, 0x12, 0x8d, 0x14, 0xaf};
        std::this_thread::sleep_for(10ms);
        mResetPin = true;
        mDCPin = false;
        SPIDevice::writeBuffer(initSequence, sizeof(initSequence), true);
        mDCPin = true;
        //        SendCommand(0x20);  // Memory addressing mode
        //        SendCommand(1);     // Vertical
        //        SendCommand(0xA1);  // ustaw remapowanie
        //        SendCommand(0xC8);  // kierunek skanowania
        //        SendCommand(0xDA);  // konfiguracja wyprowadzeñ sterownika
        //        SendCommand(0x12);
        //        SendCommand(0x8D);  // ustawienie Charge Pump
        //        SendCommand(0x14);
        //        SendCommand(0xAF);  // w³¹cza wyœwietlacz
    }

 public:
    SSD1306(microhal::SPI& aSpi, microhal::GPIO::IOPin aCSPin, microhal::GPIO::IOPin aDCPin, microhal::GPIO::IOPin aResetPin)
        : microhal::SPIDevice(aSpi, aCSPin),
          Display({Width, Height}),
          mDCPin(aDCPin, microhal::GPIO::Direction::Output),
          mResetPin(aResetPin, microhal::GPIO::Direction::Output) {
        mDCPin = false;
        mResetPin = false;
    }
    virtual ~SSD1306() {}

 private:
    microhal::GPIO mDCPin;
    microhal::GPIO mResetPin;
    std::array<std::bitset<Params::Height>, Params::Width> mPixels;
};

#endif  // _MICROHAL_SSD1306_H_
