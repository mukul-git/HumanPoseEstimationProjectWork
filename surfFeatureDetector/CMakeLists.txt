# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("SurfFeatureDetector")

# Include sub-projects.
#add_subdirectory ("SurfFeatureDetector")


find_package( OpenCV REQUIRED )

message ( "OpenCV lib details:" ${OpenCV_LIBS} ${OpenCV_INCLUDE_DIRS} )
include_directories( ${OpenCV_INCLUDE_DIRS} )


# Add source to this project's executable.
add_executable (SurfFeatureDetector "SurfFeatureDetectorV3.cpp" )
target_link_libraries( SurfFeatureDetector ${OpenCV_LIBS} )
