cmake_minimum_required(VERSION 3.5)
project(CalculatorApp)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_AUTOMOC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(CalculatorApp
    src/main.cpp
    src/CalculatorWindow.cpp
)

target_link_libraries(CalculatorApp Qt5::Widgets)
