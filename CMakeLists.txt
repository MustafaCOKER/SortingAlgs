cmake_minimum_required(VERSION 3.0.0)
project (SortingAlgo)


set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)


aux_source_directory(. ALL_SRCS)
add_subdirectory(source)
add_executable(${CMAKE_PROJECT_NAME} ${ALL_SRCS})

target_link_libraries(${CMAKE_PROJECT_NAME} sortings)
include_directories(${CMAKE_PROJECT_NAME} "include")