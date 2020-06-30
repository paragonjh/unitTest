cmake_minimum_required(VERSION 3.2.2)

project(myproject)

set(CMAKE_CXX_FLAGS "-std=c++14")

add_executable(${CMAKE_PROJECT_NAME}
    src/main.cpp
    src/shape.cpp
    src/circle.cpp
    src/world.cpp
    src/mystring.cpp
)

include_directories(src)

#if (BUILD_TESTING)
    enable_testing()
    add_subdirectory(tests)
#endif()

