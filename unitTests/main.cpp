// clang-format off
#include <KeLibTxtDl.h>
#include <FtShmem.h>
// clang-format on

#include <tuple>
#include <memory>
#include <string>
#include <gtest/gtest.h>

#include "TxtController/Controller.hpp"

namespace {
class PrepareMotor1
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

TEST_P(PrepareMotor1, DataIsSet)
{
    const uint16_t distance = std::get<1>(GetParam());
    const int16_t rotationSpeed1 = std::get<2>(GetParam());
    const int16_t rotationSpeed2 = std::get<3>(GetParam());

    FISH_X1_TRANSFER hardwareInterface;
    controller = std::shared_ptr<jatozy::TxtController::Controller>(
        new jatozy::TxtController::Controller(&hardwareInterface));

    // Here starts the test.
    controller->PrepareMotor1(distance, rotationSpeed1, rotationSpeed2);

    EXPECT_EQ(distance, hardwareInterface.ftX1out.distance[0]);
    EXPECT_EQ(rotationSpeed1, hardwareInterface.ftX1out.duty[0]);
    EXPECT_EQ(rotationSpeed2, hardwareInterface.ftX1out.duty[1]);
}

INSTANTIATE_TEST_CASE_P(Controller,
                        PrepareMotor1,
                        ::testing::Values(
                            std::make_tuple("One_Rotation_Counter_Clockwise_Full_Speed", 127, 512, 0),
                            std::make_tuple("One_Rotation_Clockwise_Full_Speed", 127, 0, 512),
                            std::make_tuple("Half_Rotation_Counter_Clockwise_Full_Speed", 64, 512, 0),
                            std::make_tuple("One_Rotation_Counter_Clockwise_Quarter_Speed", 127, 128, 0),
                            std::make_tuple("14_Degree_Rotation_Clockwise_10_Percent_Speed", 5, 0, 51)),
                        PrepareMotor1::PrintToStringParamName());

class PrepareMotor2
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

TEST_P(PrepareMotor2, DataIsSet)
{
    const uint16_t distance = std::get<1>(GetParam());
    const int16_t rotationSpeed1 = std::get<2>(GetParam());
    const int16_t rotationSpeed2 = std::get<3>(GetParam());

    FISH_X1_TRANSFER hardwareInterface;
    controller = std::shared_ptr<jatozy::TxtController::Controller>(
        new jatozy::TxtController::Controller(&hardwareInterface));

    // Here starts the test.
    controller->PrepareMotor2(distance, rotationSpeed1, rotationSpeed2);

    EXPECT_EQ(distance, hardwareInterface.ftX1out.distance[1]);
    EXPECT_EQ(rotationSpeed1, hardwareInterface.ftX1out.duty[2]);
    EXPECT_EQ(rotationSpeed2, hardwareInterface.ftX1out.duty[3]);
}

INSTANTIATE_TEST_CASE_P(Controller,
                        PrepareMotor2,
                        ::testing::Values(
                            std::make_tuple("One_Rotation_Counter_Clockwise_Full_Speed", 127, 512, 0),
                            std::make_tuple("One_Rotation_Clockwise_Full_Speed", 127, 0, 512),
                            std::make_tuple("Half_Rotation_Counter_Clockwise_Full_Speed", 64, 512, 0),
                            std::make_tuple("One_Rotation_Counter_Clockwise_Quarter_Speed", 127, 128, 0),
                            std::make_tuple("14_Degree_Rotation_Clockwise_10_Percent_Speed", 5, 0, 51)),
                        PrepareMotor1::PrintToStringParamName());

} // namespace

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}