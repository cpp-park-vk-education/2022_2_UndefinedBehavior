cmake_minimum_required(VERSION 3.0.0)
project(Test)

enable_testing()

set(CMAKE_CXX_STANDARD 20)

file(GLOB SOURCES *.cpp)

find_package(GTest REQUIRED)

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} ${CLIENT_LIB_LIBRARIES} ${SERVER_LIB_LIBRARIES} GTest::gtest_main)
target_include_directories(${PROJECT_NAME} PUBLIC ${CLIENT_LIB_INCLUDE_DIRS} PUBLIC ${SERVER_LIB_INCLUDE_DIRS})

gtest_discover_tests(${PROJECT_NAME})