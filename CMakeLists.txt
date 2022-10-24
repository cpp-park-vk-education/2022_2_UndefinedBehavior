cmake_minimum_required(VERSION 3.0.0)
project(fapplication VERSION 0.1.0)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -Wall -Werror -Wextra")

add_subdirectory(qt)

message("APP_LIB_INCLUDE_DIRS-${APP_LIB_INCLUDE_DIRS}")
message("APP_LIB_LIBRARIES-${APP_LIB_LIBRARIES}")

add_executable(${PROJECT_NAME} main.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${APP_LIB_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${APP_LIB_LIBRARIES})

enable_testing()
add_subdirectory(tests)
