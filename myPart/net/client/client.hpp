#pragma once // NOLINT

#define SUCCESS_FLG 0

#include <iostream>

namespace project {

struct Client {
  Client();
  static int connectToServer();
};

}  // namespace project
