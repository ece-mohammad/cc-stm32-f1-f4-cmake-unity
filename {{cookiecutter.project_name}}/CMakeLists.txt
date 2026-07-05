cmake_minimum_required(VERSION 3.22)

project(
  "{{cookiecutter.project_title}}"
  VERSION {{cookiecutter.project_version}}
  DESCRIPTION "{{cookiecutter.project_description}}"
  HOMEPAGE_URL "{{cookiecutter.project_url}}"
  LANGUAGES C CXX ASM)

configure_file("${CMAKE_CURRENT_SOURCE_DIR}/VERSION.in"
               "${CMAKE_CURRENT_SOURCE_DIR}/VERSION")

enable_testing()
include(CTest)

find_program(CCACHE_PROGRAM ccache)
if(CCACHE_PROGRAM)
  set(CMAKE_C_COMPILER_LAUNCHER "${CCACHE_PROGRAM}")
  set(CMAKE_CXX_COMPILER_LAUNCHER "${CCACHE_PROGRAM}")
  message(STATUS "Using ccache")
endif(CCACHE_PROGRAM)

if(NOT DEFINED TARGET_PLATFORM)
  if(WIN32)
    set(TARGET_PLATFORM "windows")
  else()
    set(TARGET_PLATFORM "linux")
  endif()
endif()

message(STATUS "Building for platofrm: ${TARGET_PLATFORM}")

add_subdirectory({{cookiecutter.project_name}})
add_subdirectory(platform)
add_subdirectory(middleware)
add_subdirectory(examples)
add_subdirectory(test)
add_subdirectory(docs)

