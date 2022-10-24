#include <gtest/gtest.h>

#include "../qt/include/app.hpp"

class ApplicationTest : ::testing::Test {};

TEST(ApplicationTest, BaseTest) {
  application::App app;
  EXPECT_EQ(FLAG, app.runApp());
}

TEST(ApplicationTest, Base2Test) {
  application::App app;
  EXPECT_EQ(100, NUMBER);
}