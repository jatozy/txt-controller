// clang-format off
#include <KeLibTxtDl.h>
#include <FtShmem.h>
// clang-format on

#include <gtest/gtest.h>

#include "TxtController/Controller.hpp"

namespace {
TEST(Controller, PrepareMotor1_Rotate1TimesWithMaximumSpeedCounterClockwise)
{
    const uint16_t distance{127};
    const int16_t rotationSpeed1{512};
    const int16_t rotationSpeed2{0};

    FISH_X1_TRANSFER hardwareInterface;
    jatozy::TxtController::Controller sut(&hardwareInterface);

    // Here starts the test.
    sut.PrepareMotor1(distance, rotationSpeed1, rotationSpeed2);

    EXPECT_EQ(distance, hardwareInterface.ftX1out.distance[0]);
    EXPECT_EQ(rotationSpeed1, hardwareInterface.ftX1out.duty[0]);
    EXPECT_EQ(rotationSpeed2, hardwareInterface.ftX1out.duty[1]);
}
} // namespace

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}