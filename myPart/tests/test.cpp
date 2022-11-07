#include <gtest/gtest.h>

#include <server.hpp>

class ServerTest : ::testing::Test {};

TEST(ServerTest, BaseTest) {
  project::Server server;
  EXPECT_EQ(EXIT_SUCCESS, server.run());
}
