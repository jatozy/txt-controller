// clang-format off
#include <KeLibTxtDl.h>
#include <FtShmem.h>
// clang-format on

#include <tuple>
#include <memory>
#include <gtest/gtest.h>

#include "TxtController/Controller.hpp"

namespace {
class ControllerParameterizedMethodPrepareMotor1
    : public ::testing::TestWithParam<std::tuple<uint16_t, int16_t, int16_t>> {
protected:
    std::shared_ptr<jatozy::TxtController::Controller> controller;
};

TEST_P(ControllerParameterizedMethodPrepareMotor1, PrepareMotor1)
{
    const uint16_t distance = std::get<0>(GetParam());
    const int16_t rotationSpeed1 = std::get<1>(GetParam());
    const int16_t rotationSpeed2 = std::get<2>(GetParam());

    FISH_X1_TRANSFER hardwareInterface;
    controller = std::shared_ptr<jatozy::TxtController::Controller>(
        new jatozy::TxtController::Controller(&hardwareInterface));

    // Here starts the test.
    controller->PrepareMotor1(distance, rotationSpeed1, rotationSpeed2);

    EXPECT_EQ(distance, hardwareInterface.ftX1out.distance[0]);
    EXPECT_EQ(rotationSpeed1, hardwareInterface.ftX1out.duty[0]);
    EXPECT_EQ(rotationSpeed2, hardwareInterface.ftX1out.duty[1]);
}

INSTANTIATE_TEST_CASE_P(ControllerTests,
                        ControllerParameterizedMethodPrepareMotor1,
                        ::testing::Values(std::make_tuple(127, 512, 0),
                                          std::make_tuple(127, 0, 512),
                                          std::make_tuple(64, 512, 0),
                                          std::make_tuple(64, 0, 512),
                                          std::make_tuple(127, 256, 0),
                                          std::make_tuple(127, 0, 256),
                                          std::make_tuple(64, 256, 0),
                                          std::make_tuple(64, 0, 256)));

} // namespace

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}