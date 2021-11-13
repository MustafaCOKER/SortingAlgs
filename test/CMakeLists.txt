include_directories("${PROJECT_SOURCE_DIR}/include")
include_directories("${PROJECT_SOURCE_DIR}/test/include")


file(GLOB sources "${PROJECT_SOURCE_DIR}/source/*.c")
list(REMOVE_ITEM sources "${PROJECT_SOURCE_DIR}/source/Main.c")

file(GLOB tests "${PROJECT_SOURCE_DIR}/test/source/*.cpp")
list(REMOVE_ITEM tests "${PROJECT_SOURCE_DIR}/test/source/Main.cpp")

foreach(file ${tests})
  set(name)
  get_filename_component(name ${file} NAME_WE)
  add_executable("${name}_tests"
    ${sources}
    ${file}
    "${PROJECT_SOURCE_DIR}/test/source/Main.cpp")
  target_link_libraries("${name}_tests" gtest_main)
  add_test(NAME ${name} COMMAND "${name}_tests")
endforeach()