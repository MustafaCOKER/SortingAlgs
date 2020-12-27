cmake_minimum_required(VERSION 3.0.0)
project (SortingAlgo)

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

include_directories(${CMAKE_PROJECT_NAME} "include")

add_subdirectory(source)
aux_source_directory(. ALL_SRCS)
add_executable(${CMAKE_PROJECT_NAME} ${ALL_SRCS})
target_link_libraries(${CMAKE_PROJECT_NAME} sortings)


configure_file(CMakeLists.txt.in
        googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )

add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
        ${CMAKE_BINARY_DIR}/googletest-build)

include(CTest)
add_subdirectory(test)
