#include <chrono>
#include <thread>

#include "Instance.h"

using namespace microhal;

using namespace std::literals::chrono_literals;

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

int main(void) {
    while (1) {
        std::this_thread::sleep_for(5s);
    }
}

extern "C" void HardFault_Handler(void) {
    while (1)
        ;
}
