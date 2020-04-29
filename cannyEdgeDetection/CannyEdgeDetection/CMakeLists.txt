# CMakeList.txt : CMake project for CannyEdgeDetection, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

find_package( OpenCV REQUIRED )

message ( "OpenCV lib details:" ${OpenCV_LIBS} ${OpenCV_INCLUDE_DIRS} )
include_directories( ${OpenCV_INCLUDE_DIRS} )


# Add source to this project's executable.
add_executable (CannyEdgeDetection "CannyEdgeDetection2.cpp" )


#add_executable (CannyEdgeDetection "CannyEdgeDetection1.cpp"  "CannyEdgeDetection.h")
target_link_libraries( CannyEdgeDetection ${OpenCV_LIBS} )


add_definitions(-DSOURCE_ROOT_DIR=${CMAKE_CURRENT_SOURCE_DIR})






