#include <atomic>
#include <chrono>
#include <sstream>
#include <string>
#include <thread>

#include "microhal.h"
#include "microhal_bsp.h"

#include "WorkQueue.h"
#include "diagnostic/diagnostic.h"
#include "diagnostic/ticToc.h"
#include "itoa.h"

#include "Drawing.h"
#include "Widgets.h"
#include "Windows.h"

using namespace microhal;
using namespace microhal::diagnostic;

using namespace std::literals::chrono_literals;

using namespace Drawing;
using namespace WorkQueue;
using namespace TouchController;

const char* LcdState2String(TSL_StateId_enum_T state) {
    switch (state) {
        case TSL_STATEID_DEB_CALIB:
            return "DB_CALIB";
        case TSL_STATEID_CALIB:
            return "CALIB   ";
        case TSL_STATEID_RELEASE:
            return "RELEASE ";
        case TSL_STATEID_DEB_RELEASE_PROX:
        case TSL_STATEID_DEB_RELEASE_DETECT:
        case TSL_STATEID_DEB_RELEASE_TOUCH:
            return "DB_REL  ";
        case TSL_STATEID_PROX:
            return "PROX    ";
        case TSL_STATEID_DEB_PROX:
        case TSL_STATEID_DEB_PROX_DETECT:
        case TSL_STATEID_DEB_PROX_TOUCH:
            return "DB_PROX ";
        case TSL_STATEID_DETECT:
            return "DETECT  ";
        case TSL_STATEID_DEB_DETECT:
            return "DB_DET  ";
        case TSL_STATEID_TOUCH:
            return "TOUCH   ";
        case TSL_STATEID_ERROR:
            return "ERROR   ";
        case TSL_STATEID_DEB_ERROR_CALIB:
        case TSL_STATEID_DEB_ERROR_RELEASE:
        case TSL_STATEID_DEB_ERROR_PROX:
        case TSL_STATEID_DEB_ERROR_DETECT:
        case TSL_STATEID_DEB_ERROR_TOUCH:
            return "DB_ERR  ";
        case TSL_STATEID_OFF:
            return "OFF     ";
        default:
            return "UNKNOWN ";
    }
}

class Haptic {
 private:
 public:
    void Wibrate(std::chrono::milliseconds aDuration) {
        mVibrationMotor = true;
        std::this_thread::sleep_for(aDuration);
        mVibrationMotor = false;
    }
    Haptic(GPIO::IOPin aPin) : mVibrationMotor(aPin, GPIO::Direction::Output) { mVibrationMotor = false; }

 private:
    GPIO mVibrationMotor;
};

static Haptic haptic{bsp::VibrationMotor};

StatusBar statusBar{};
SubWindow subWindow{};
MainWindow window{subWindow};

int main(void) {
    GPIO en_rx_1(bsp::VideoSwitch::EN_RX_1, GPIO::Direction::Output);
    GPIO en_rx_2(bsp::VideoSwitch::EN_RX_2, GPIO::Direction::Output);
    GPIO en_rx_3(bsp::VideoSwitch::EN_RX_3, GPIO::Direction::Output);
    GPIO en_rx_osd(bsp::VideoSwitch::EN_RX_OSD, GPIO::Direction::Output);
    GPIO en_rx_no_osd(bsp::VideoSwitch::EN_RX_NO_OSD, GPIO::Direction::Output);

    subWindow.SetParent(window);

    en_rx_1 = true;
    en_rx_no_osd = true;
    en_rx_2 = false;
    en_rx_3 = false;
    en_rx_osd = false;

    //    TicToc drawTime;
    //    drawTime.callibrate();

    windowManager.SetStatusBar(statusBar);
    windowManager.SetCurrentWindow(window);

    touchController.buttonOk.Click.connect([](void* aArg) { windowManager.HandleButtonEvent(ButtonEvent::OK); });
    touchController.buttonUp.Click.connect([](void* aArg) { windowManager.HandleButtonEvent(ButtonEvent::UP); });
    touchController.buttonDown.Click.connect([](void* aArg) { windowManager.HandleButtonEvent(ButtonEvent::DOWN); });
    touchController.buttonLeft.Click.connect([](void* aArg) { windowManager.HandleButtonEvent(ButtonEvent::LEFT); });
    touchController.buttonRight.Click.connect([](void* aArg) { windowManager.HandleButtonEvent(ButtonEvent::RIGHT); });

    //    int32_t frameTime = 0;

    while (1) {
        //        drawTime.tic();
        {
            //            char buff[50];
            //            itoa(frameTime, buff, 10);
            //            frameTimeLabel.SetText(buff);
            //            drawTime.toc();

            //            graphics.SetPixel({0, 0}, true);
            //            graphics.SetPixel({0, 63}, true);
            //            graphics.SetPixel({127, 63}, true);
            //            graphics.SetPixel({127, 0}, true);
        }

        // frameTime = static_cast<int32_t>(drawTime.getDuration().count()) / 1000;

        en_rx_1 = true;
        en_rx_2 = false;
        en_rx_3 = false;

        std::this_thread::sleep_for(4s);

        en_rx_1 = false;
        en_rx_2 = true;
        en_rx_3 = false;

        std::this_thread::sleep_for(4s);

        en_rx_1 = false;
        en_rx_2 = false;
        en_rx_3 = true;

        std::this_thread::sleep_for(4s);
    }
}

// void DisplayTouchCoeffs() {
//    touchController.mutex.lock();
//    TSL_tDelta_T keyDelta = TKeys[0].p_ChD->Delta;
//    TSL_StateId_enum_T keyState = TKeys[0].p_Data->StateId;
//    TSL_tPosition_T rotPos = LinRots[0].p_Data->Position;
//    TSL_StateId_enum_T rotState = LinRots[0].p_Data->StateId;
//    TSL_tDelta_T rotDelta[4];
//    rotDelta[0] = LinRots[0].p_ChD[0].Delta;
//    rotDelta[1] = LinRots[0].p_ChD[1].Delta;
//    rotDelta[2] = LinRots[0].p_ChD[2].Delta;
//    rotDelta[3] = LinRots[0].p_ChD[3].Delta;
//    uint16_t rotCoeff[4];
//    rotCoeff[0] = LinRots[0].p_DeltaCoeff[0];
//    rotCoeff[1] = LinRots[0].p_DeltaCoeff[1];
//    rotCoeff[2] = LinRots[0].p_DeltaCoeff[2];
//    rotCoeff[3] = LinRots[0].p_DeltaCoeff[3];
//    touchController.mutex.unlock();
//
//    {
//        DrawCall drawCall{graphics};
//        graphics.Fill(false);
//
//        graphics.SetWritePosition({0, 0});
//        graphics.Write(LcdState2String(keyState));
//        graphics.SetWritePosition({64, 0});
//        graphics.Write(static_cast<int32_t>(keyDelta));
//
//        graphics.SetWritePosition({0, 16});
//        graphics.Write(LcdState2String(rotState));
//        graphics.SetWritePosition({64, 16});
//        graphics.Write(static_cast<uint32_t>(rotPos));
//
//        graphics.SetWritePosition({0, 32});
//        graphics.Write(static_cast<int32_t>(rotDelta[0]));
//        graphics.SetWritePosition({32, 32});
//        graphics.Write(static_cast<int32_t>((rotDelta[0] * rotCoeff[0]) >> 8));
//        graphics.SetWritePosition({64, 32});
//        graphics.Write(static_cast<int32_t>(rotDelta[1]));
//        graphics.SetWritePosition({96, 32});
//        graphics.Write(static_cast<int32_t>((rotDelta[1] * rotCoeff[1]) >> 8));
//
//        graphics.SetWritePosition({0, 48});
//        graphics.Write(static_cast<int32_t>(rotDelta[2]));
//        graphics.SetWritePosition({32, 48});
//        graphics.Write(static_cast<int32_t>((rotDelta[2] * rotCoeff[2]) >> 8));
//        graphics.SetWritePosition({64, 48});
//        graphics.Write(static_cast<int32_t>(rotDelta[3]));
//        graphics.SetWritePosition({96, 48});
//        graphics.Write(static_cast<int32_t>((rotDelta[3] * rotCoeff[3]) >> 8));
//    }
//    std::this_thread::sleep_for(20ms);
//}
