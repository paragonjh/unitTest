cmake_minimum_required(VERSION 3.2.2)

project(test_world)

add_executable(${PROJECT_NAME}
    main.cpp
    ${CMAKE_SOURCE_DIR}/src/shape.cpp
    ${CMAKE_SOURCE_DIR}/src/circle.cpp
    ${CMAKE_SOURCE_DIR}/src/world.cpp
    ${CMAKE_SOURCE_DIR}/src/mystring.cpp
)

add_test(world ${PROJECT_NAME})

