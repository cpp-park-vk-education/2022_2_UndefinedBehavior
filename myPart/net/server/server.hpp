#pragma once // NOLINT

#define SUCCESS_FLG 0

#include <iostream>

namespace project {

struct Server {
  Server();
  static int run();
};

}  // namespace project
