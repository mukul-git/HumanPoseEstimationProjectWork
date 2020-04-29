# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("CannyEdgeDetection")

# Include sub-projects.
add_subdirectory ("CannyEdgeDetection")

#SET(SOURCE_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR})



#message(STATUS "Buzz" ${SOURCE_ROOT_DIR} ${CMAKE_CURRENT_SOURCE_DIR})

#get_cmake_property(_variableNames VARIABLES)
#list (SORT _variableNames)
#foreach (_variableName ${_variableNames})
#    message(STATUS "${_variableName}=${${_variableName}}")
#endforeach()