include_guard(GLOBAL)

cmake_minimum_required(VERSION 3.22)

include(../cmake/stm32_utils.cmake)

# build unity ------------------------------------------------
option(UNITY_EXTENSION_FIXTURE "Enable unity fixtures" ON)
add_subdirectory(common/unity unity)

# Test executable ---------------------------------------
set(EXECUTABLE_NAME foo_barTest)
add_executable(${EXECUTABLE_NAME})

set(TEST_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/test_foo_bar.c ${CMAKE_CURRENT_SOURCE_DIR}/src/main.c)
set(TEST_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/inc)
set(TEST_LINK_LIBS unity::framework foo_bar platform_interface)

if(TARGET_PLATFORM STREQUAL "stm32f103xx")
  list(APPEND TEST_SOURCES $<TARGET_OBJECTS:STM32_Drivers>)
  generate_bin_hex(${EXECUTABLE_NAME})

elseif(TARGET_PLATFORM STREQUAL "stm32f401xx")
  list(APPEND TEST_SOURCES $<TARGET_OBJECTS:STM32_Drivers>)
  generate_bin_hex(${EXECUTABLE_NAME})

endif()

target_sources(${EXECUTABLE_NAME} PRIVATE $<TARGET_OBJECTS:platform> ${TEST_SOURCES})
target_include_directories(${EXECUTABLE_NAME} PUBLIC ${TEST_INCLUDE_DIRS})
target_link_libraries(${EXECUTABLE_NAME} PUBLIC ${TEST_LINK_LIBS})

include(${CMAKE_CURRENT_SOURCE_DIR}/../cmake/stm32_utils.cmake)

add_test(NAME test_foo_bar COMMAND test_foo_bar)

