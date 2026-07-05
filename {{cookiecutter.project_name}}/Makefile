.PHONY: all clean clean-all flash reset erase

RM = rm

PRESET ?= windows-debug

TARGET ?= all

.PHONY: docs clean clean-all clean-docs flash-test-stm32f103 flash-example-stm32f103 flash-test-stm32f401 flash-example-stm32f401

configure:
	cmake --preset $(PRESET) -G Ninja

build: configure
	cmake --build --preset $(PRESET) --target $(TARGET)

flash-test-stm32f103: build
	STM32_Programmer_CLI.exe --connect port=SWD --write build/stm32f103xx/stm32f103-debug/test/test_{{cookiecutter.project_name}}.bin 0x08000000 incremental --verify fast

flash-example-stm32f103: build
	STM32_Programmer_CLI.exe --connect port=SWD --write build/stm32f103xx/stm32f103-debug/examples/{{cookiecutter.project_name}}_example.bin 0x08000000 incremental --verify fast

flash-test-stm32f401: build
	STM32_Programmer_CLI.exe --connect port=SWD --write build/stm32f401xx/stm32f401-debug/test/test_{{cookiecutter.project_name}}.bin 0x08000000 incremental --verify fast

flash-example-stm32f401: build
	STM32_Programmer_CLI.exe --connect port=SWD --write build/stm32f401xx/stm32f401-debug/examples/{{cookiecutter.project_name}}_example.bin 0x08000000 incremental --verify fast

mcu-reset:
	STM32_Programmer_CLI.exe --connect port=SWD -hardRst

mcu-erase:
	STM32_Programmer_CLI.exe --connect port=SWD --erase all

clean:
	cmake --build --preset $(PRESET) --target clean

clean-all:
	$(RM) -rf build

clean-docs:
	$(RM) -rf docs/html

docs:
	@which doxygen >/dev/null 2>&1 || { echo "doxygen not found in PATH; install doxygen or run it manually"; exit 1; }
	@doxygen docs/Doxyfile
