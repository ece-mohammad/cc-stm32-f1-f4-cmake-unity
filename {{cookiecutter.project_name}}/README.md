# {{cookiecutter.project_title}}

{{cookiecutter.project_description}}

## Features

- Core library layout under `{{cookiecutter.project_name}}/`
- Platform backends for `linux`, `windows`, `stm32f103xx`, and `stm32f401xx`
- STM32 HAL integration for the supported MCU targets
- Unity-based test harness under `test/`
- CMake presets for host and MCU builds
- Makefile wrapper for build, clean, flash, reset, and docs tasks
- Doxygen configuration under `docs/`

## Repository Structure

- `{{cookiecutter.project_name}}/`
  - `inc/`: public headers
  - `src/`: core library implementation
- `platform/`
  - `linux/`: Linux backend and toolchain settings
  - `windows/`: Windows backend and toolchain settings
  - `stm32f103xx/`: STM32F103 backend, HAL drivers, and ARM GCC toolchain
  - `stm32f401xx/`: STM32F401 backend, HAL drivers, and ARM GCC toolchain
- `middleware/`: middleware components
- `examples/`: sample application sources
- `test/`: Unity test runner, test sources, and submodule
- `docs/`: Doxygen configuration
- `CMakeLists.txt`: root build entry point
- `CMakePresets.json`: preset definitions for host and MCU builds
- `Makefile`: convenience wrapper around CMake and flashing commands

## Requirements

- CMake `>= 3.22`
- Ninja
- Git
- Host compiler:
  - Linux: GCC
  - Windows: MinGW or MinGW-w64
- For STM32 targets:
  - ARM GCC toolchain such as `arm-none-eabi-gcc`
  - STM32CubeProgrammer CLI as `STM32_Programmer_CLI`
  - ST-LINK or another supported debug probe
- For documentation:
  - Doxygen

Before building, initialize the Unity submodule:

```sh
git submodule update --init --recursive
```

## Environment Setup

If your compilers or flashing tools are not already available on `PATH`, copy `env.template.json` to `env.json` and update it with your local toolchain paths.

```sh
cp env.template.json env.json
```

The generated `env.json` file provides values for:

- `WIN_GCC_TOOLCHAIN_PATH`
- `WIN_GCC_TOOLCHAIN_PREFIX`
- `LINUX_GCC_TOOLCHAIN_PATH`
- `LINUX_GCC_TOOLCHAIN_PREFIX`
- `ARM_GCC_TOOLCHAIN_PATH`
- `ARM_GCC_TOOLCHAIN_PREFIX`
- `TOOLCHAIN_SUFFIX`

See `env.template.json` for the full format.

## Build Presets

Available configure and build presets:

- `linux-debug`
- `linux-release`
- `windows-debug`
- `windows-release`
- `stm32f103-debug`
- `stm32f103-release`
- `stm32f401-debug`
- `stm32f401-release`

Host test presets are available for:

- `linux-debug`
- `linux-release`
- `windows-debug`
- `windows-release`

## Building

### Using CMake Directly

Host build example:

```sh
cmake --preset linux-debug
cmake --build --preset linux-debug
```

STM32F103 build example:

```sh
cmake --preset stm32f103-debug
cmake --build --preset stm32f103-debug
```

STM32F401 build example:

```sh
cmake --preset stm32f401-debug
cmake --build --preset stm32f401-debug
```

### Using The Makefile Wrapper

The Makefile defaults to `PRESET=windows-debug`.

```sh
make PRESET=linux-debug build
make PRESET=windows-debug build
make PRESET=stm32f103-debug build
make PRESET=stm32f401-debug build
```

Cleaning:

```sh
make PRESET=linux-debug clean
make clean-all
```

## Running Tests

Host-side tests are integrated with CTest.

```sh
ctest --preset linux-debug --output-on-failure
```

or:

```sh
ctest --preset windows-debug --output-on-failure
```

The test sources are located under `test/src/`.

For STM32 targets, the test runner binary is built as firmware and can be flashed to hardware. Unity output is routed through USART1 at `115200` baud.

## Flashing Firmware

The Makefile provides flash targets that call `STM32_Programmer_CLI.exe` with the generated `.bin` artifacts.

The current flash targets write the debug build outputs under `build/stm32f103xx/stm32f103-debug/` and `build/stm32f401xx/stm32f401-debug/`.

STM32F103:

```sh
make flash-test-stm32f103
make flash-example-stm32f103
```

STM32F401:

```sh
make flash-test-stm32f401
make flash-example-stm32f401
```

Reset and erase helpers:

```sh
make mcu-reset
make mcu-erase
```

Generated binaries are written under the preset-specific build directories, for example:

- `build/stm32f103xx/stm32f103-debug/test/`
- `build/stm32f103xx/stm32f103-debug/examples/`
- `build/stm32f401xx/stm32f401-debug/test/`
- `build/stm32f401xx/stm32f401-debug/examples/`

## Running Examples

The example application source is located at:

- `examples/src/{{cookiecutter.project_name}}.c`

The example target name is:

- `{{cookiecutter.project_name}}_example`

On host builds, run the generated executable from the build directory after building.

On STM32 targets, `.bin` and `.hex` artifacts are generated automatically and can be flashed using the Makefile targets shown above.

## API Usage

Include the public header and link the `{{cookiecutter.project_name}}` library together with `platform_interface`.

```c
#include <{{cookiecutter.project_name}}.h>

int main(void) {
    return 0;
}
```

Primary public header:

- `{{cookiecutter.project_name}}/inc/{{cookiecutter.project_name}}.h`

## Integrating Into Another Project

### Option A: Add As CMake Subdirectories

Set `TARGET_PLATFORM` before adding the project directories:

```cmake
set(TARGET_PLATFORM linux)

add_subdirectory(external/{{cookiecutter.project_name}}/{{cookiecutter.project_name}})
add_subdirectory(external/{{cookiecutter.project_name}}/platform)

add_executable(my_app main.c)
target_link_libraries(my_app PRIVATE {{cookiecutter.project_name}} platform_interface)
target_include_directories(my_app PRIVATE external/{{cookiecutter.project_name}}/{{cookiecutter.project_name}}/inc)
```

### Option B: Vendor The Core Library

- Copy `{{cookiecutter.project_name}}/` into your project.
- Provide a backend implementation for your target.
- Link the core library together with your platform backend.

## Adding A New Platform Backend

To support a new platform:

1. Create a new directory under `platform/` following the existing layout.
2. Implement the required backend functions in a platform-specific source file.
3. Add platform build logic and a toolchain file if needed.
4. Update `platform/CMakeLists.txt` so `TARGET_PLATFORM` selects the new backend.
5. Add tests or examples where practical.

Reference implementations:

- Software backends: `platform/linux/` and `platform/windows/`
- HAL-based MCU backends: `platform/stm32f103xx/` and `platform/stm32f401xx/`

## Documentation

API documentation is generated with Doxygen using `docs/Doxyfile`.

Using the Makefile:

```sh
make docs
```

Using Doxygen directly:

```sh
doxygen docs/Doxyfile
```

Using the CMake target:

```sh
cmake --build --preset linux-debug --target docs
```

Generated HTML output is written under `docs/html`.

## Where To Look Next

- Core library header: `{{cookiecutter.project_name}}/inc/{{cookiecutter.project_name}}.h`
- Core library source: `{{cookiecutter.project_name}}/src/{{cookiecutter.project_name}}.c`
- Platform selection: `platform/CMakeLists.txt`
- Example source: `examples/src/{{cookiecutter.project_name}}.c`
- Test sources: `test/src/test_{{cookiecutter.project_name}}.c`
- Doxygen configuration: `docs/Doxyfile`
