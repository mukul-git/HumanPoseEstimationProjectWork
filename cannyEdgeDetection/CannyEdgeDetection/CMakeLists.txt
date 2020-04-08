# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project (CannyEdgeDetection)
set ( OPENCV_INCLUDE_DIRS "$ENV{OPENCV_PATH}/build/include" )

# Include sub-projects.
add_subdirectory ("CannyEdgeDetection")

link_directories( ${OPENCV_INCLUDE_DIRS} )
# TODO: Add tests and install targets if needed.
#install(TARGETS CannyEdgeDetection DESTINATION bin)