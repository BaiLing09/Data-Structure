cmake_minimum_required(VERSION 2.8)
PROJECT(TEST)

list(APPEND CMAKE_CXX_FLAGS
-pthread)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pg")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -pg")
SET(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} -pg")

set(CMAKE_CXX_STANDARD 11)
LINK_LIBRARIES("/media/hp/System1/SoftWare/JH/ubuntu_x64/JHCap2/libJHCap.so")

set(CMAKE_PREFIX_PATH "/media/hp/System1/SoftWare/Opencv4/opencv") 
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

set(PROJ_SOURCES
main.cpp
Order_Stack.hpp
Link_Stack.hpp
Caluculator.cpp
Test.cpp
)

ADD_EXECUTABLE(${PROJECT_NAME} ${PROJ_SOURCES})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${OpenCV_LIBS})