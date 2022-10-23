#include <server.hpp>
#include <client.hpp>

int main(int argc, char* argv[]) {
    std::cout << "Program starts" << std::endl;
    project::Server server;
    server.run();

    project::Client client;
    client.connectToServer();

    return 0;
}
