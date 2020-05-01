#include "TxtController/Controller.hpp"

#include <gtest/gtest.h>
#include <iostream>
#include <memory>
#include <string>
#include <timercpp.h>
#include <tuple>

// clang-format off
#include <KeLibTxtDl.h>
#include <FtShmem.h>
// clang-format on

namespace {
class MoveMotors
    : public ::testing::TestWithParam<std::tuple<std::string, uint16_t, int16_t, int16_t>> {
public:
    struct PrintToStringParamName {
        template <class ParamType>
        std::string operator()(const testing::TestParamInfo<ParamType>& info) const
        {
            auto testData =
                static_cast<std::tuple<std::string, uint16_t, int16_t, int16_t>>(info.param);
            return std::get<0>(testData);
        }
    };

protected:
    std::shared_ptr<jatozy::TxtController::Controller> controller;
};

TEST_P(MoveMotors, MoveMotors)
{
    const uint16_t distance = std::get<1>(GetParam());
    const int16_t rotationSpeed1 = std::get<2>(GetParam());
    const int16_t rotationSpeed2 = std::get<3>(GetParam());

    FISH_X1_TRANSFER hardwareInterface = {};
    controller = std::shared_ptr<jatozy::TxtController::Controller>(
        new jatozy::TxtController::Controller(&hardwareInterface));

    controller->PrepareMotor1(distance, rotationSpeed1, rotationSpeed2);
    controller->PrepareMotor2(distance, rotationSpeed1, rotationSpeed2);
    const uint16_t motor1LastCommandId = hardwareInterface.ftX1out.motor_ex_cmd_id[0];
    const uint16_t motor2LastCommandId = hardwareInterface.ftX1out.motor_ex_cmd_id[1];

    Timer t = Timer();

    t.setInterval(
        [&]() {
            hardwareInterface.ftX1in.motor_ex_cmd_id[0]++;
            hardwareInterface.ftX1in.motor_ex_cmd_id[1]++;
        },
        100);

    t.setTimeout(
        [&]() {
            t.stop();
            abort();
        },
        1000);

    // Here starts the test.
    controller->RotateMotors();
    controller->WaitUntilMotorsRotationFinished();
    t.stop();
}

INSTANTIATE_TEST_CASE_P(
    ControllerIntegrationTests,
    MoveMotors,
    ::testing::Values(
        std::make_tuple("Move_Both_Motors_Counter_Clockwise", 127, 512, 0)),
    MoveMotors::PrintToStringParamName());
} // namespace

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}