#include <Analog.h>
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

static StatusBar statusBar{};
static SubWindow subWindow{};
static MainWindow window{subWindow, Config::Channel};

static volatile UBaseType_t uxHighWaterMark;

static void UpdateRxChannel() {
    for (auto& videoRx : videoRxes) {
        videoRx.SetChannel(Config::Channel);
    }
}

int main(void) {
    subWindow.SetParent(window);

    windowManager.SetStatusBar(statusBar);
    windowManager.SetCurrentWindow(window);

    UpdateRxChannel();

    touchController.buttonOk.Click.connect([](WorkRequestArg& aArg) { windowManager.HandleButtonEvent(ButtonEvent::OK); });
    touchController.buttonUp.Click.connect([](WorkRequestArg& aArg) { windowManager.HandleButtonEvent(ButtonEvent::UP); });
    touchController.buttonDown.Click.connect([](WorkRequestArg& aArg) { windowManager.HandleButtonEvent(ButtonEvent::DOWN); });
    touchController.buttonLeft.Click.connect([](WorkRequestArg& aArg) { windowManager.HandleButtonEvent(ButtonEvent::LEFT); });
    touchController.buttonRight.Click.connect([](WorkRequestArg& aArg) { windowManager.HandleButtonEvent(ButtonEvent::RIGHT); });
    analog.VoltageUpdate.connect([](WorkRequestArg& aArg) { statusBar.SetVoltage(aArg.Voltage); });
    analog.RSSIUpdate[0].connect([](WorkRequestArg& aArg) { statusBar.SetRSSI(aArg.RSSI1, 0); });
    analog.RSSIUpdate[1].connect([](WorkRequestArg& aArg) { statusBar.SetRSSI(aArg.RSSI2, 1); });
    analog.RSSIUpdate[2].connect([](WorkRequestArg& aArg) { statusBar.SetRSSI(aArg.RSSI3, 2); });
    Config::Channel.Updated.connect([](WorkRequestArg& aArg) { UpdateRxChannel(); });

    while (1) {
        videoSwitch.SelectRx(0);
        statusBar.SetSelectedRx(0);

        std::this_thread::sleep_for(5s);

        videoSwitch.SelectRx(1);
        statusBar.SetSelectedRx(1);

        std::this_thread::sleep_for(5s);

        videoSwitch.SelectRx(2);
        statusBar.SetSelectedRx(2);

        std::this_thread::sleep_for(5s);

        uxHighWaterMark = uxTaskGetStackHighWaterMark(NULL);
    }
}

extern "C" void HardFault_Handler(void) {
    while (1)
        ;
}
