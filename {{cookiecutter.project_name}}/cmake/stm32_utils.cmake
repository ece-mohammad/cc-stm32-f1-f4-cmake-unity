include_guard(GLOBAL)

find_program(CMAKE_OBJCOPY arm-none-eabi-objcopy REQUIRED)

function(generate_bin_hex TARGET)
  set(BIN_FILE "${CMAKE_CURRENT_BINARY_DIR}/${TARGET}.bin")
  set(HEX_FILE "${CMAKE_CURRENT_BINARY_DIR}/${TARGET}.hex")

  add_custom_command(
        TARGET ${TARGET}
        POST_BUILD
        COMMAND ${CMAKE_OBJCOPY} -O binary "$<TARGET_FILE:${TARGET}>" "${BIN_FILE}"
        COMMAND ${CMAKE_OBJCOPY} -O ihex   "$<TARGET_FILE:${TARGET}>" "${HEX_FILE}"
        COMMENT "Generating ${BIN_FILE} and ${HEX_FILE}"
    )

  set_target_properties(${TARGET}
        PROPERTIES
        ADDITIONAL_CLEAN_FILES "${BIN_FILE};${HEX_FILE}"
    )
endfunction()
