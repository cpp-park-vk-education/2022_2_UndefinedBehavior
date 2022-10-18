cmake_minimum_required(VERSION 3.10)

project(YourCollection)

set(CMAKE_CXX_STANDARD 11)
if(BUILD_FOR_TEST)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -coverage -lgcov" )
endif()
OPTION(WITH_MEMCHECK "Run with memcheck" OFF)
OPTION(BUILD_FOR_TEST "build_for_test" OFF)

enable_testing()
#add_subdirectory(business_logic)
add_subdirectory(net)
add_subdirectory(tests)

message("NET_LIB = ${NET_LIB}")
message("NET_INCLUDE_DIRS = ${NET_INCLUDE_DIRS}")

add_executable(${PROJECT_NAME} start/main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE ${NET_LIB})
target_include_directories(${PROJECT_NAME} PUBLIC ${NET_INCLUDE_DIRS})
