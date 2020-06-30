cmake_minimum_required(VERSION 3.2.2)

project(test_string)

add_executable(${PROJECT_NAME}
    main.cpp
    ${CMAKE_SOURCE_DIR}/src/mystring.cpp
)

add_test(string ${PROJECT_NAME})

