#pragma once

#include <cstdint>

struct shm_if_s;

namespace jatozy::TxtController {
struct Controller {
    Controller(struct shm_if_s* hardwareInterface);

    void PrepareMotor1(uint16_t distance, int16_t rotationSpeed1, int16_t rotationSpeed2);
    void PrepareMotor2(uint16_t distance, int16_t rotationSpeed1, int16_t rotationSpeed2);

private:
    struct shm_if_s* m_hardwareInterface;
};
} // namespace jatozy::TxtController