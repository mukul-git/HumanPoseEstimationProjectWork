# CMakeList.txt : CMake project for CannyEdgeDetection, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (CannyEdgeDetection "CannyEdgeDetection2.cpp"  "CannyEdgeDetection.h") #"CannyEdgeDetection1.cpp"

message ( "Hello world" ${OpenCV_LIBS} ${OpenCV_INCLUDE_DIRS} )
#message ( "Hello world" ${OpenCV_LIBS} $ENV{OPENCV_PATH} )
#add_subdirectory ( $ENV{OPENCV_PATH} )

find_package( OpenCV REQUIRED )

include_directories( ${OpenCV_INCLUDE_DIRS} )

#set( OpenCV_LIBS "$ENV{OPENCV_DIR}\\x64\\vc15\\lib" )

target_link_libraries( CannyEdgeDetection ${OpenCV_LIBS} )
#message ( "Hello world" ${OpenCV_LIBS} ${OpenCV_INCLUDE_DIRS} )
#set(OPENCV_INCLUDE_DIRS "$ENV{OPENCV_PATH}\\build\\include")
#message ( ${OPENCV_INCLUDE_DIRS} )
#target_link_libraries(myapp PRIVATE ${TIFF_LIBRARY})
#target_link_libraries(CannyEdgeDetection PUBLIC "$ENV{OPENCV_PATH}/bin")
#TARGET_LINK_LIBRARIES (CannyEdgeDetection ${OPENCV_INCLUDE_DIRS} )  

target_include_directories(CannyEdgeDetection PUBLIC ${OpenCV_INCLUDE_DIRS})


