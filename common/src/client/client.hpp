#pragma once // NOLINT

#define SUCCESS_FLG 0

#include <iostream>

namespace project {

struct Client {
  Client() {std::cout << "Create client" << std::endl;} 
  static int connectToServer();
  ~CLient() {std::cout << "Delete client" << std::endl;} 
};

}  // namespace project