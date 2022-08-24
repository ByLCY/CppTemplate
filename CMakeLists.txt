cmake_minimum_required(VERSION 3.14...3.22)

project(
    CppTemplate
    VERSION 0.0.1
    LANGUAGES CXX
)

if (PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
  message(
      FATAL_ERROR
      "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there."
  )
endif ()

include(cmake/options.cmake)
# --------------------
# version.h file
# --------------------
message(STATUS "The version.h file is in ${PROJECT_SOURCE_DIR}/include/${INCLUDE_DIR}/version.h")
configure_file(${PROJECT_SOURCE_DIR}/version.h.in ${PROJECT_SOURCE_DIR}/include/${INCLUDE_DIR}/version.h)

# --------------------
# source files
# --------------------
file(GLOB_RECURSE headers CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")
file(GLOB_RECURSE sources CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/source/*.cc")

add_library(${PROJECT_NAME} ${headers} ${sources})
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_STANDARD 17)

# include headers
include_directories(${PROJECT_SOURCE_DIR}/include)

# --------------------
# enable/disable unittests
# --------------------
message(STATUS "Whether the current project compiles unit tests: ${BUILD_TEST}")
IF (BUILD_TEST)
  add_subdirectory(test)
endif (BUILD_TEST)