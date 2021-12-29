include_directories(
    ${PROJECT_SOURCE_DIR}/include
)

file(GLOB LIB_SRCS ${PROJECT_SOURCE_DIR}/*.c)
add_library (sortings STATIC ${LIB_SRCS})