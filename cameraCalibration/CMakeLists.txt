# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("CameraCalibration")

# Include sub-projects.
#add_subdirectory ("CameraCalibration")


find_package( OpenCV REQUIRED )

message ( "OpenCV lib details:" ${OpenCV_LIBS} ${OpenCV_INCLUDE_DIRS} )
include_directories( ${OpenCV_INCLUDE_DIRS} )


# Add source to this project's executable.
add_executable (CameraCalibration "CameraCalibrationV1.cpp" )
target_link_libraries( CameraCalibration ${OpenCV_LIBS} )
