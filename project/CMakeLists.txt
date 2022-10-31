cmake_minimum_required(VERSION 3.0.0)
project(YourCollection VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)

option(BUILD_TEST OFF)

#if(BUILD_TEST)
    set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-fprofile-arcs -ftest-coverage -fPIC -O0")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -coverage -lgcov" )
#else()
#    set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-Wall -Wextra -Wpedantic -Werror")
#endif()

add_subdirectory(src/client)
add_subdirectory(src/server)

file(GLOB SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

set(SANITIZER_FLAGS "-fsanitize=leak,undefined,address")
option(SANITIZE ON)
if(${SANITIZE})
    set(CMAKE_CXX_FLAGS ${CMAKE_C_FLAGS} ${SANITIZER_FLAGS})
endif()

add_custom_target(check chmod 777 ${CMAKE_CURRENT_SOURCE_DIR}/scripts/*.sh)

target_include_directories(${PROJECT_NAME} PUBLIC ${CLIENT_LIB_INCLUDE_DIRS} PUBLIC ${SERVER_LIB_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE ${CLIENT_LIB_LIBRARIES} PRIVATE ${SERVER_LIB_LIBRARIES})

enable_testing()
add_subdirectory(tests)