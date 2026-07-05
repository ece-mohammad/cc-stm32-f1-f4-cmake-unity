/**
 * @file platform.h
 * @brief Platform initialization abstraction
 *
 * This header exposes a minimal platform initialization entrypoint used by
 * tests and platform-specific startup code. Implementations live under
 * `platform/` (linux, windows, stm32f103xx, stm32f401xx).
 */

#ifndef PLATFORM_H_
#define PLATFORM_H_

/**
 * @brief Initialize platform (Linux, Windows, STM32F103xx, STM32F401xx, etc)
 */
void platform_init(void);

#endif /* PLATFORM_H_ */
