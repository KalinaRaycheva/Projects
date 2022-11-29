cmake_minimum_required(VERSION 3.5.1)

project(codename_kids_next_door)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake_helpers/helpers_c.cmake)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/01_Restaurant)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/02_Warcraft)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/03_Starcraft)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/04_Counter_Strike)