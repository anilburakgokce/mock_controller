cmake_minimum_required(VERSION 3.16)
project(mock_controller)

set(CMAKE_CXX_STANDARD 17)

add_executable(mock_controller
    main.cpp
    controller.cpp
    device.cpp
)