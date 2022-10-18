cmake_minimum_required(VERSION 3.14)
project(tests)

set(CMAKE_CXX_STANDARD 14)
if(BUILD_FOR_TEST)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-fprofile-arcs -ftest-coverage -O0")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -coverage -lgcov" )
endif()

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

file(GLOB TEST_SOURCES *.cpp)
include(GoogleTest)

add_executable(${PROJECT_NAME} ${TEST_SOURCES})
target_link_libraries(${PROJECT_NAME} ${NET_LIB} GTest::gtest_main)
target_include_directories(${PROJECT_NAME} PUBLIC ${NET_INCLUDE_DIRS})

SET(memcheck_command)

if (WITH_MEMCHECK)
        message("Memcheck enabled")
        SET(memcheck_command ${CMAKE_SOURCE_DIR}/memtest.sh)
else()
        message("Memcheck disabled")
endif()

SET (TEST_COMMAND ${memcheck_command} ${CMAKE_BINARY_DIR}/tests/tests)

ADD_TEST(
        NAME BaseTest
        COMMAND ${TEST_COMMAND}
)

#gtest_discover_tests(${PROJECT_NAME})
