#include <gtest/gtest.h>

#include <server.hpp>
#include <client.hpp>

using namespace project;

class ServerTest : ::testing::Test {
};

TEST(ServerTest, BaseTest) {
    Server server;
    EXPECT_EQ(SUCCESS_FLG, server.run());
}