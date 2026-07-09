#!/usr/bin/env pythhon3
# -*- coding: utf-8 -*-

import sys
import subprocess


def git_init_repo():
    try:
        subprocess.run(
            ["git", "init"],
            check=True,
        )
        subprocess.run(
            ["git", "config", "--local", "core.autocrlf", "true"],
            check=True,
        )
        subprocess.run(
            [
                "git",
                "submodule",
                "add",
                "https://github.com/ThrowTheSwitch/Unity",
                "test/common/unity",
            ],
            check=True,
        )
        subprocess.run(
            [
                "git",
                "submodule",
                "add",
                "https://github.com/STMicroelectronics/stm32f1xx-hal-driver.git",
                "platform/stm32f103xx/cubemx/Drivers/STM32F1xx_HAL_Driver",
            ],
            check=True,
        )
        subprocess.run(
            [
                "git",
                "submodule",
                "add",
                "https://github.com/STMicroelectronics/stm32f4xx-hal-driver.git",
                "platform/stm32f401xx/cubemx/Drivers/STM32F4xx_HAL_Driver",
            ],
            check=True,
        )
        subprocess.run(["git", "add", "."], check=True)
        subprocess.run(
            [
                "git",
                "commit",
                "-m",
                "initial commit via Cookiecutter",
            ],
            check=True,
        )
        subprocess.run(
            ["git", "branch", "-m", "main"],
            check=True,
        )
        print("git repository successfully initialized")

    except subprocess.CalledProcessError as err:
        print(f"Failed to initialize git repository, error: {err}")
        sys.exit(-1)

    except FileNotFoundError:
        print(
            f"git is not installed, or is not in system PATH, skipping git initialization"
        )


if __name__ == "__main__":
    git_init_repo()
