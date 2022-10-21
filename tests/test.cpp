#include <gtest/gtest.h>

#include <client.hpp>
#include <server.hpp>

class ServerTest : ::testing::Test {};

TEST(ServerTest, BaseTest) {
  project::Server server;
  EXPECT_EQ(SUCCESS_FLG, server.run());
}
