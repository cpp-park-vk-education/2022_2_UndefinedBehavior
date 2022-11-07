#include <server.hpp>

int main(int argc, char* argv[]) {
    std::cout << "Program starts" << std::endl;
    project::Server server;
    server.run();

    return 0;
}
