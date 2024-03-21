cmake_minimum_required (VERSION 3.8)

project ("LabsASD4")

add_executable (LabsASD4 "LabsASD4.cpp" "LabsASD4.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET LabsASD4 PROPERTY CXX_STANDARD 20)
endif()

