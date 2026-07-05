include_guard(GLOBAL)

cmake_minimum_required(VERSION 3.22)

add_library({{cookiecutter.project_name}} STATIC)

target_sources({{cookiecutter.project_name}}
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/{{cookiecutter.project_name}}.c
)

target_include_directories(
    {{cookiecutter.project_name}}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
)
