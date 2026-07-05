# STM32 Embedded Project Cookiecutter Template

Cookiecutter template for bootstrapping embedded C projects with STM32 HAL support, layered drivers, Unity-based testing, CMake builds, Makefile flashing helpers, and Doxygen documentation generation.

This repository is the template source. Running Cookiecutter against it generates a new project scaffold that already includes support for `stm32f103xx` and `stm32f401xx` targets, host-side builds, tests, examples, and API documentation.

## Why Use This Template

- Start new embedded projects with a repeatable structure instead of rebuilding boilerplate each time.
- Build for host and STM32 targets from the same CMake-based workflow.
- Keep application logic, drivers, and platform backends separated from the start.
- Include Unity test scaffolding from day one.
- Generate API documentation with Doxygen using the provided docs target.
- Flash firmware with a small Makefile wrapper around the generated build outputs.

## What The Generated Project Includes

The generated project contains:

- STM32 HAL-based backends for `stm32f103xx` and `stm32f401xx`
- host backends for local builds
- a core module/library layout
- `platform/` for target-specific code
- `middleware/` for reusable middleware components
- `examples/` for sample applications
- `test/` with Unity integration
- `docs/` with a Doxygen configuration
- root `CMakeLists.txt` and a convenience `Makefile`

## Quick Start

### 1. Install Cookiecutter

```sh
pip install cookiecutter
```

### 2. Generate A New Project

From GitHub:

```sh
cookiecutter gh:<owner>/<repo>
```

From a local clone:

```sh
cookiecutter .
```

Cookiecutter will prompt you for values such as:

- `project_name`
- `project_title`
- `project_version`
- `project_description`
- `author`
- `email`
- `project_url`
- `git_init_local`

### 3. Enter The Generated Project

```sh
cd <generated-project-directory>
```

### 4. Initialize Submodules

The generated project uses Unity as a git submodule.

```sh
git submodule update --init --recursive
```

## Prerequisites

### To Generate A Project

- Python
- `pip`
- `cookiecutter`
- `git`

### To Build The Generated Project

- CMake `>= 3.22`
- Ninja
- Git submodules
- Host compiler:
  - Linux: GCC
  - Windows: MinGW or MinGW-w64
- For STM32 targets:
  - ARM GCC toolchain such as `arm-none-eabi-gcc`
  - STM32CubeProgrammer CLI as `STM32_Programmer_CLI`
  - ST-LINK or another supported debug probe
- For documentation:
  - Doxygen

## Generated Project Workflow

After generating a project, the normal workflow is:

1. Initialize submodules.
2. Create `env.json` from `env.template.json` if your compilers or STM32 tools are not already available on `PATH`.
3. Choose a CMake preset for host or MCU builds.
4. Build using CMake directly or through the provided Makefile wrapper.
5. Run host tests with CTest.
6. Flash STM32 firmware with the Makefile helper targets when targeting hardware.
7. Generate API documentation with Doxygen when needed.

## Minimal Usage Example

After generating a project:

```sh
git submodule update --init --recursive
cp env.template.json env.json
cmake --preset linux-debug
cmake --build --preset linux-debug
ctest --preset linux-debug --output-on-failure
```

STM32 build example:

```sh
cmake --preset stm32f103-debug
cmake --build --preset stm32f103-debug
make PRESET=stm32f103-debug flash-example-stm32f103
```

## Supported Targets In Generated Projects

Current target support in the generated scaffold:

- `stm32f103xx`
- `stm32f401xx`
- host builds for local development and testing

The STM32 targets use HAL-based platform backends that are already wired into the generated CMake layout.

## Repository Structure

This repository contains the template source, not a ready-to-build application at the root.

- `cookiecutter.json`: template variables and default values
- `hooks/`: optional Cookiecutter hooks
- `{{cookiecutter.project_name}}/`: generated project skeleton
- `{{cookiecutter.project_name}}/README.md`: README for generated projects

Inside the generated project skeleton:

- `{{cookiecutter.project_name}}/`: core library/module source
- `platform/`: platform-specific implementations and toolchains
- `middleware/`: reusable middleware components
- `examples/`: sample applications
- `test/`: Unity test harness and test cases
- `docs/`: Doxygen configuration
- `CMakeLists.txt`: root build entry point
- `Makefile`: convenience wrapper for build and flash tasks

## What Is Templated

Cookiecutter replaces placeholders such as:

- `{{cookiecutter.project_name}}`
- `{{cookiecutter.project_title}}`
- `{{cookiecutter.project_version}}`
- `{{cookiecutter.project_description}}`
- `{{cookiecutter.project_url}}`

These values are used across generated directory names, project metadata, and documentation files. The overall project structure stays the same unless you change the template itself.

## Build, Test, Flash, And Docs Support

Generated projects include:

- CMake presets for host and STM32 builds
- a Makefile wrapper around the generated CMake workflow
- Unity-based tests under `test/`
- flash helper targets that use `STM32_Programmer_CLI`
- Doxygen configuration under `docs/`

Typical generated project capabilities include:

- host builds such as `linux-debug` and `windows-debug`
- MCU builds such as `stm32f103-debug` and `stm32f401-debug`
- host-side test execution with `ctest`
- Doxygen generation through `make docs` or the `docs` CMake target

## When This Template Fits

Use this template when you want:

- a new STM32 embedded C project scaffold
- CMake-based builds instead of IDE-only project files
- a structured separation between core logic and platform code
- test support included from the beginning
- Doxygen documentation generation built into the project layout

This template is a weaker fit if you need:

- out-of-the-box support for non-STM32 targets only
- a vendor-IDE-only workflow with no CMake integration
- a highly opinionated RTOS or middleware stack pre-integrated

## For Template Maintainers

The root README explains how to consume the template. The generated project README lives at `{{cookiecutter.project_name}}/README.md` and should document day-to-day build, test, flash, and integration details for users after generation.
