cmake_minimum_required(VERSION 3.10)
project(dicom-converter)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Widgets)

find_package(DCMTK REQUIRED)

message(STATUS "DCMTK package was found with include dir: '${DCMTK_INCLUDE_DIRS}'")

include_directories(${DCMTK_INCLUDE_DIRS})

find_package(OpenCV REQUIRED)

message(STATUS "OpenCV package was found with include dir: '${OpenCV_INCLUDE_DIRS}'")

include_directories(include)

file(GLOB dicom_extract_SRC
        "src/*.cpp"
        "include/*.h"
        "*.cpp"
        "*.h"
        )

add_executable(dicom-converter main.cpp ${dicom_extract_SRC})

target_link_libraries(dicom-converter Qt5::Widgets ${OpenCV_LIBS} ${DCMTK_LIBRARIES})