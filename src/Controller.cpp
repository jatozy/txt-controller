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
    if (m_hardwareInterface) {
        m_hardwareInterface->ftX1out.distance[0] = distance;
        m_hardwareInterface->ftX1out.duty[0] = rotationSpeed1;
        m_hardwareInterface->ftX1out.duty[1] = rotationSpeed2;
    }
}

void jatozy::TxtController::Controller::PrepareMotor2(uint16_t distance,
                                                      int16_t rotationSpeed1,
                                                      int16_t rotationSpeed2)
{
    if (m_hardwareInterface) {
        m_hardwareInterface->ftX1out.distance[1] = distance;
        m_hardwareInterface->ftX1out.duty[2] = rotationSpeed1;
        m_hardwareInterface->ftX1out.duty[3] = rotationSpeed2;
    }
}