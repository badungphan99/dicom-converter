cmake_minimum_required(VERSION 3.10)
project(dicom_extract)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV REQUIRED)

include_directories(include)

add_executable(dicom_extract main.cpp src/dicom_extract.cpp include/dicom_extract.h include/core.h src/dicom.cpp include/dicom.h)