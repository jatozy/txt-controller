#pragma once

#include <cstdint>

struct shm_if_s;

namespace jatozy::TxtController {
struct Controller {
    Controller(struct shm_if_s* hardwareInterface);
    Controller(const Controller&) = default;
    Controller(Controller&&) = default;
    Controller& operator=(const Controller&) = default;
    Controller& operator=(Controller&&) = default;
    ~Controller() = default;

    void PrepareMotor1(uint16_t distance, int16_t rotationSpeed1, int16_t rotationSpeed2);
    void PrepareMotor2(uint16_t distance, int16_t rotationSpeed1, int16_t rotationSpeed2);
    void RotateMotors();

private:
    void PrepareMotor(uint16_t distance,
                      int16_t rotationSpeed1,
                      int16_t rotationSpeed2,
                      int distanceIndex,
                      int dutyCycleIndex1,
                      int dutyCycleIndex2);

    struct shm_if_s* m_hardwareInterface;
    bool m_motor1Prepared;
    bool m_motor2Prepared;
};
} // namespace jatozy::TxtController