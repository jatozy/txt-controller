#include <gtest/gtest.h>
#include <string>

namespace {
TEST(Exampletest, FirstTestWithTheWorstNameEver)
{
    const std::string s;

    EXPECT_STREQ("", s.c_str());

    EXPECT_EQ(0u, s.length());
}
} // namespace

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}