#include "TxtController/Controller.hpp"

// clang-format off
#include <KeLibTxtDl.h>
#include <FtShmem.h>
// clang-format on

jatozy::TxtController::Controller::Controller(FISH_X1_TRANSFER* hardwareInterface)
{
    m_hardwareInterface = hardwareInterface;
}

void jatozy::TxtController::Controller::PrepareMotor1(uint16_t distance,
                                                      int16_t rotationSpeed1,
                                                      int16_t rotationSpeed2)
{
    PrepareMotor(distance, rotationSpeed1, rotationSpeed2, 0, 0, 1);
}

void jatozy::TxtController::Controller::PrepareMotor2(uint16_t distance,
                                                      int16_t rotationSpeed1,
                                                      int16_t rotationSpeed2)
{
    PrepareMotor(distance, rotationSpeed1, rotationSpeed2, 1, 2, 3);
}

void jatozy::TxtController::Controller::PrepareMotor(uint16_t distance, int16_t rotationSpeed1, int16_t rotationSpeed2, int distanceIndex, int dutyCycleIndex1, int dutyCycleIndex2)
{
    if (m_hardwareInterface) {
        m_hardwareInterface->ftX1out.distance[distanceIndex] = distance;
        m_hardwareInterface->ftX1out.duty[dutyCycleIndex1] = rotationSpeed1;
        m_hardwareInterface->ftX1out.duty[dutyCycleIndex2] = rotationSpeed2;
    }
}