cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(pcl_detect_holes)
set(PCL_DIR "~/myapps/share/pcl-1.7/")
find_package(PCL 1.2 REQUIRED)

include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

add_executable (detect_holes main.cpp)
target_link_libraries (detect_holes ${PCL_LIBRARIES})
