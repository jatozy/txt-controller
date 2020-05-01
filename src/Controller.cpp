#include "TxtController/Controller.hpp"

#include <chrono>
#include <thread>

// clang-format off
#include <KeLibTxtDl.h>
#include <FtShmem.h>
// clang-format on

jatozy::TxtController::Controller::Controller(FISH_X1_TRANSFER* hardwareInterface)
    : m_hardwareInterface(hardwareInterface), m_motor1Prepared(false), m_motor2Prepared(false)
{
}

void jatozy::TxtController::Controller::PrepareMotor1(uint16_t distance,
                                                      int16_t rotationSpeed1,
                                                      int16_t rotationSpeed2)
{
    PrepareMotor(distance, rotationSpeed1, rotationSpeed2, 0, 0, 1);
    m_motor1Prepared = true;
}

void jatozy::TxtController::Controller::PrepareMotor2(uint16_t distance,
                                                      int16_t rotationSpeed1,
                                                      int16_t rotationSpeed2)
{
    PrepareMotor(distance, rotationSpeed1, rotationSpeed2, 1, 2, 3);
    m_motor2Prepared = true;
}

void jatozy::TxtController::Controller::PrepareMotor(uint16_t distance,
                                                     int16_t rotationSpeed1,
                                                     int16_t rotationSpeed2,
                                                     int distanceIndex,
                                                     int dutyCycleIndex1,
                                                     int dutyCycleIndex2)
{
    if (m_hardwareInterface) {
        m_hardwareInterface->ftX1out.distance[distanceIndex] = distance;
        m_hardwareInterface->ftX1out.duty[dutyCycleIndex1] = rotationSpeed1;
        m_hardwareInterface->ftX1out.duty[dutyCycleIndex2] = rotationSpeed2;
    }
}

void jatozy::TxtController::Controller::RotateMotors()
{
    if (m_motor1Prepared) {
        m_hardwareInterface->ftX1out.motor_ex_cmd_id[0]++;
    }
    if (m_motor2Prepared) {
        m_hardwareInterface->ftX1out.motor_ex_cmd_id[1]++;
    }
}

void jatozy::TxtController::Controller::WaitUntilMotorsRotationFinished() const
{
    while (m_hardwareInterface->ftX1in.motor_ex_cmd_id[0] <
               m_hardwareInterface->ftX1out.motor_ex_cmd_id[0] &&
           m_hardwareInterface->ftX1in.motor_ex_cmd_id[1] <
               m_hardwareInterface->ftX1out.motor_ex_cmd_id[1]) {
        std::this_thread::sleep_for(std::chrono::milliseconds(7));
    }
}