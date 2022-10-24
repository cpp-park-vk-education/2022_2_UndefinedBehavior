cmake_minimum_required(VERSION 3.10)

project(YourCollection)

OPTION(WITH_MEMCHECK "Run with memcheck" OFF)
OPTION(BUILD_FOR_TEST "build_for_test" OFF)

set(CMAKE_CXX_STANDARD 11)
if(BUILD_FOR_TEST)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -coverage -lgcov" )
endif()

#enable_testing()



message("BUSINESS_LOGIC_LIB = ${BUSINESS_LOGIC_LIB}")
message("BUSINESS_LOGIC_INCLUDE_DIRS = ${BUSINESS_LOGIC_INCLUDE_DIRS}")

target_link_libraries(${PROJECT_NAME} PRIVATE ${BUSINESS_LOGIC_LIB})
target_include_directories(${PROJECT_NAME} PUBLIC ${BUSINESS_LOGIC_INCLUDE_DIRS})