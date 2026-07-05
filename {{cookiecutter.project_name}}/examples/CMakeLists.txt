include_guard(GLOBAL)
include(${CMAKE_CURRENT_SOURCE_DIR}/../cmake/stm32_utils.cmake)

set(EXAMPLE_NAME {{cookiecutter.project_name}}_example)

add_executable(${EXAMPLE_NAME})

set(EXAMPLE_SOURCE ${CMAKE_CURRENT_SOURCE_DIR}/src/{{cookiecutter.project_name}}.c)
set(EXAMPLE_LINK_LIBRARIES {{cookiecutter.project_name}} platform_interface)

if(TARGET_PLATFORM STREQUAL "stm32f103xx")
  list(APPEND EXAMPLE_SOURCE $<TARGET_OBJECTS:STM32_Drivers>)
  generate_bin_hex(${EXAMPLE_NAME})

elseif(TARGET_PLATFORM STREQUAL "stm32f401xx")
  list(APPEND EXAMPLE_SOURCE $<TARGET_OBJECTS:STM32_Drivers>)
  generate_bin_hex(${EXAMPLE_NAME})

endif()


target_sources(${EXAMPLE_NAME}
  PRIVATE
  ${EXAMPLE_SOURCE}
  $<TARGET_OBJECTS:platform>
)

target_link_libraries(${EXAMPLE_NAME} ${EXAMPLE_LINK_LIBRARIES})
