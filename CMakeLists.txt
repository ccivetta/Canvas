cmake_minimum_required(VERSION 3.14)
project(Canvas)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 14)

include_directories(.)
find_package(Qt5 COMPONENTS Widgets REQUIRED)
add_executable(Canvas
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui)

target_link_libraries(Canvas PRIVATE Qt5::Widgets)
