/**
 * @file platform.c
 *
 * @brief Platofrm initialization for stm32f103
 */

#include "gpio.h"
#include "main.h"
#include "usart.h"

#include <platform.h>

/**
 * @brief Pointer to UART handle used for input/output
 *
 */
static UART_HandleTypeDef *huart = &huart6;

/**
 * @brief Initialize system clocks (AHB, APB clocks, CPU clock)
 *
 */
static void SystemClock_Config(void);

/**
 * @brief Initialize stm32f103 core, clocks and peripherals
 *
 */
void platform_init(void) {
  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* Configure the system clock */
  SystemClock_Config();

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART6_UART_Init();
  /*
  MX_UART4_Init();
  MX_USART1_UART_Init();
  MX_USART2_UART_Init();
  MX_USART3_UART_Init();
  */
}

int _write(int file, char *ptr, int len) {
  (void)file;

  HAL_StatusTypeDef err = HAL_UART_Transmit(huart, (uint8_t *)ptr, len, HAL_MAX_DELAY);
  if (err != HAL_OK) {
    return -1;
  }
  return len;
}

int _read(int file, char *ptr, int len) {
  (void)file;

  int count = 0;
  while (count < len) {
    uint8_t ch;

    if (HAL_UART_Receive(huart, &ch, 1, HAL_MAX_DELAY) != HAL_OK) {
      return -1;
    }

    *ptr++ = ch;
    count++;

    if (ch == '\r') {
      *(ptr - 1) = '\n';
      break;
    }

    if (ch == '\n') {
      break;
    }
  }

  return count;
}

void SystemClock_Config(void) {
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
   */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);

  /** Initializes the RCC Oscillators according to the specified parameters
   * in the RCC_OscInitTypeDef structure.
   */
  RCC_OscInitStruct.OscillatorType      = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState            = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState        = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource       = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM            = 16;
  RCC_OscInitStruct.PLL.PLLN            = 168;
  RCC_OscInitStruct.PLL.PLLP            = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ            = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
   */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource   = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider  = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK) {
    Error_Handler();
  }
}

void Error_Handler(void) {
  __disable_irq();
  while (1) {
  }
}
