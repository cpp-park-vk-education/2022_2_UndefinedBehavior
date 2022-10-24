cmake_minimum_required(VERSION 3.0.0)
project(application VERSION 0.1.0)

set(APP_LIB_LIBRARIES)
set(APP_LIB_INCLUDE_DIRS)

file(GLOB SOURCES "src/*.cpp" "../**/*.cpp")
file(GLOB INCLUDE_DIRS ../include)

add_library(${PROJECT_NAME} ${SOURCES})

set(APP_LIB_LIBRARIES ${PROJECT_NAME} PARENT_SCOPE)
set(APP_LIB_INCLUDE_DIRS ${PROJECT_NAME} PARENT_SCOPE)
