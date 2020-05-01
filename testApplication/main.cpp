#include <TxtController/Controller.hpp>
#include <chrono>
#include <cstdio>
#include <iostream>
#include <thread>

// clang-format off
#include <KeLibTxtDl.h>
#include <FtShmem.h>
// clang-format on

// The following global variables are needed from the libROBOProLib.so
unsigned int DebugFlags;
FILE* DebugFile;

int main(void)
{
    FISH_X1_TRANSFER* hardwareInterface = nullptr;
    if (StartTxtDownloadProg() == KELIB_ERROR_NONE) {
        hardwareInterface = GetKeLibTransferAreaMainAddress();
        if (hardwareInterface) {
            jatozy::TxtController::Controller controller(hardwareInterface);

            controller.PrepareMotor1(255, 256, 0);
            controller.PrepareMotor2(255, 256, 0);
            controller.RotateMotors();

            std::cout << "wait until motors are rotated." << std::endl;
            controller.WaitUntilMotorsRotationFinished();
            std::cout << "waiting finshed." << std::endl;

            std::cout << "wait some seconds before the motors are rotated back."
                      << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(5));

            controller.PrepareMotor1(511, 0, 512);
            controller.PrepareMotor2(511, 0, 512);
            controller.RotateMotors();

            std::cout << "wait until motors are rotated." << std::endl;
            controller.WaitUntilMotorsRotationFinished();
            std::cout << "waiting finshed." << std::endl;
        }
        StopTxtDownloadProg();
    }
    return 0;
}
