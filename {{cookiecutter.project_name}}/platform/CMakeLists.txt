include_guard(GLOBAL)

if(TARGET_PLATFORM STREQUAL "windows")
  add_subdirectory(windows)

elseif(TARGET_PLATFORM STREQUAL "linux")
  add_subdirectory(linux)

elseif(TARGET_PLATFORM STREQUAL "stm32f103xx")
  add_subdirectory(stm32f103xx)

elseif(TARGET_PLATFORM STREQUAL "stm32f401xx")
  add_subdirectory(stm32f401xx)
endif()
