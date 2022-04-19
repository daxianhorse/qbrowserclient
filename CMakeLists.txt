cmake_minimum_required(VERSION 3.22)
project(qbrowserclient)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QT_PATH /home/liang/Qt/6.2.4/gcc_64)

set(CMAKE_PREFIX_PATH ${QT_PATH})

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED
        )

LINK_DIRECTORIES(${CMAKE_BINARY_DIR})

include_directories(${CMAKE_SOURCE_DIR}/include ${CMAKE_SOURCE_DIR})

add_executable(qbrowserclient main.cpp ClientHandler.cc ClientHandler.h)

target_link_libraries(qbrowserclient PUBLIC
        Qt::Core
        Qt::Gui
        Qt::Widgets
        libcef_dll_wrapper.a
        libcef.so
        X11
        libEGL.so
        libGLESv2.so
        libvk_swiftshader.so
        libvulkan.so.1
        )
