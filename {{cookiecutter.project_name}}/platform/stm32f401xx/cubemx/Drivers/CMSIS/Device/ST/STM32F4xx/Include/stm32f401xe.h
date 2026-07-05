/**
  ******************************************************************************
  * @file    stm32f401xe.h
  * @author  MCD Application Team
  * @brief   CMSIS Cortex-M4 Device Peripheral Access Layer Header File.
  *          This file contains all the peripheral register's definitions, bits
  *          definitions and memory mapping for STM32F401xE devices.
  *
  *          This file contains:
  *           - Data structures and the address mapping for all peripherals
  *           - Peripheral's registers declarations and bits definition
  *           - Macros to access peripheral's registers hardware
  *
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2017-2021 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */

#ifndef __STM32F401xE_H
#define __STM32F401xE_H

#ifdef __cplusplus
 extern "C" {
#endif

/** @addtogroup Configuration_section_for_CMSIS
  * @{
  */
#define __CM4_REV                 0x0001U
#define __MPU_PRESENT             1U
#define __NVIC_PRIO_BITS          4U
#define __Vendor_SysTickConfig    0U
#define __FPU_PRESENT             1U
/**
  * @}
  */

/** @addtogroup Peripheral_interrupt_number_definition
  * @{
  */

typedef enum
{
/******  Cortex-M4 Processor Exceptions Numbers ***************************************************/
  NonMaskableInt_IRQn         = -14,
  HardFault_IRQn              = -13,
  MemoryManagement_IRQn       = -12,
  BusFault_IRQn               = -11,
  UsageFault_IRQn             = -10,
  SVCall_IRQn                 = -5,
  DebugMonitor_IRQn           = -4,
  PendSV_IRQn                 = -2,
  SysTick_IRQn                = -1,

/******  STM32 specific Interrupt Numbers *********************************************************/
  WWDG_IRQn                   = 0,
  PVD_IRQn                    = 1,
  TAMP_STAMP_IRQn             = 2,
  RTC_WKUP_IRQn               = 3,
  FLASH_IRQn                  = 4,
  RCC_IRQn                    = 5,
  EXTI0_IRQn                  = 6,
  EXTI1_IRQn                  = 7,
  EXTI2_IRQn                  = 8,
  EXTI3_IRQn                  = 9,
  EXTI4_IRQn                  = 10,
  DMA1_Stream0_IRQn           = 11,
  DMA1_Stream1_IRQn           = 12,
  DMA1_Stream2_IRQn           = 13,
  DMA1_Stream3_IRQn           = 14,
  DMA1_Stream4_IRQn           = 15,
  DMA1_Stream5_IRQn           = 16,
  DMA1_Stream6_IRQn           = 17,
  ADC_IRQn                    = 18,
  EXTI9_5_IRQn                = 23,
  TIM1_BRK_TIM9_IRQn          = 24,
  TIM1_UP_TIM10_IRQn          = 25,
  TIM1_TRG_COM_TIM11_IRQn     = 26,
  TIM1_CC_IRQn                = 27,
  TIM2_IRQn                   = 28,
  TIM3_IRQn                   = 29,
  TIM4_IRQn                   = 30,
  I2C1_EV_IRQn                = 31,
  I2C1_ER_IRQn                = 32,
  I2C2_EV_IRQn                = 33,
  I2C2_ER_IRQn                = 34,
  SPI1_IRQn                   = 35,
  SPI2_IRQn                   = 36,
  USART1_IRQn                 = 37,
  USART2_IRQn                 = 38,
  EXTI15_10_IRQn              = 40,
  RTC_Alarm_IRQn              = 41,
  OTG_FS_WKUP_IRQn            = 42,
  DMA1_Stream7_IRQn           = 47,
  SDIO_IRQn                   = 49,
  TIM5_IRQn                   = 50,
  SPI3_IRQn                   = 51,
  DMA2_Stream0_IRQn           = 56,
  DMA2_Stream1_IRQn           = 57,
  DMA2_Stream2_IRQn           = 58,
  DMA2_Stream3_IRQn           = 59,
  DMA2_Stream4_IRQn           = 60,
  OTG_FS_IRQn                 = 67,
  DMA2_Stream5_IRQn           = 68,
  DMA2_Stream6_IRQn           = 69,
  DMA2_Stream7_IRQn           = 70,
  USART6_IRQn                 = 71,
  I2C3_EV_IRQn                = 72,
  I2C3_ER_IRQn                = 73,
  FPU_IRQn                    = 81,
} IRQn_Type;

/**
  * @}
  */

#include "core_cm4.h"
#include "system_stm32f4xx.h"
#include <stdint.h>

/** @addtogroup Peripheral_registers_structures
  * @{
  */

typedef struct
{
  __IO uint32_t DR;
  __IO uint8_t  IDR;
  uint8_t       RESERVED0;
  uint16_t      RESERVED1;
  __IO uint32_t CR;
  __IO uint32_t INIT;
  uint32_t      RESERVED2;
  __IO uint32_t POL;
} CRC_TypeDef;

typedef struct
{
  __IO uint32_t CR;
  __IO uint32_t CSR;
} PWR_TypeDef;

typedef struct
{
  __IO uint32_t CR;
  __IO uint32_t PLLCFGR;
  __IO uint32_t CFGR;
  __IO uint32_t CIR;
  __IO uint32_t AHB1RSTR;
  __IO uint32_t AHB2RSTR;
  __IO uint32_t AHB3RSTR;
  uint32_t  RESERVED0;
  __IO uint32_t APB1RSTR;
  __IO uint32_t APB2RSTR;
  uint32_t  RESERVED1[2];
  __IO uint32_t AHB1ENR;
  __IO uint32_t AHB2ENR;
  __IO uint32_t AHB3ENR;
  uint32_t  RESERVED2;
  __IO uint32_t APB1ENR;
  __IO uint32_t APB2ENR;
  uint32_t  RESERVED3[2];
  __IO uint32_t AHB1LPENR;
  __IO uint32_t AHB2LPENR;
  __IO uint32_t AHB3LPENR;
  uint32_t  RESERVED4;
  __IO uint32_t APB1LPENR;
  __IO uint32_t APB2LPENR;
  uint32_t  RESERVED5[2];
  __IO uint32_t BDCR;
  __IO uint32_t CSR;
  uint32_t  RESERVED6[2];
  __IO uint32_t SSCGR;
  __IO uint32_t PLLI2SCFGR;
  uint32_t  RESERVED7;
  __IO uint32_t DCKCFGR;
} RCC_TypeDef;

typedef struct
{
  __IO uint32_t MODER;
  __IO uint32_t OTYPER;
  __IO uint32_t OSPEEDR;
  __IO uint32_t PUPDR;
  __IO uint32_t IDR;
  __IO uint32_t ODR;
  __IO uint32_t BSRR;
  __IO uint32_t LCKR;
  __IO uint32_t AFR[2];
} GPIO_TypeDef;

typedef struct
{
  __IO uint32_t SR;
  __IO uint32_t DR;
  __IO uint32_t BRR;
  __IO uint32_t CR1;
  __IO uint32_t CR2;
  __IO uint32_t CR3;
  __IO uint32_t GTPR;
} USART_TypeDef;

typedef struct
{
  __IO uint32_t ACR;
  __IO uint32_t KEYR;
  __IO uint32_t OPTKEYR;
  __IO uint32_t SR;
  __IO uint32_t CR;
  __IO uint32_t OPTCR;
} FLASH_TypeDef;

typedef struct
{
  __IO uint32_t CR;
  __IO uint32_t FIFOCR;
  __IO uint32_t MUXR;
} DMA_BitBang_TypeDef;

/**
  * @}
  */

/** @addtogroup Peripheral_memory_map
  * @{
  */

#define FLASH_BASE            0x08000000UL
#define SRAM_BASE             0x20000000UL
#define PERIPH_BASE           0x40000000UL

#define SRAM_BB_BASE          0x22000000UL
#define PERIPH_BB_BASE        0x42000000UL

#define APB1PERIPH_BASE       PERIPH_BASE
#define APB2PERIPH_BASE       (PERIPH_BASE + 0x00010000UL)
#define AHB1PERIPH_BASE       (PERIPH_BASE + 0x00020000UL)
#define AHB2PERIPH_BASE       (PERIPH_BASE + 0x10000000UL)

#define GPIOA_BASE            (AHB1PERIPH_BASE + 0x0000UL)
#define GPIOB_BASE            (AHB1PERIPH_BASE + 0x0400UL)
#define GPIOC_BASE            (AHB1PERIPH_BASE + 0x0800UL)
#define GPIOD_BASE            (AHB1PERIPH_BASE + 0x0C00UL)
#define GPIOE_BASE            (AHB1PERIPH_BASE + 0x1000UL)
#define GPIOF_BASE            (AHB1PERIPH_BASE + 0x1400UL)
#define GPIOG_BASE            (AHB1PERIPH_BASE + 0x1800UL)
#define GPIOH_BASE            (AHB1PERIPH_BASE + 0x1C00UL)

#define CRC_BASE              (AHB1PERIPH_BASE + 0x3000UL)
#define RCC_BASE              (AHB1PERIPH_BASE + 0x3800UL)
#define FLASH_R_BASE          (AHB1PERIPH_BASE + 0x3C00UL)

#define DMA1_BASE             (AHB1PERIPH_BASE + 0x6000UL)
#define DMA2_BASE             (AHB1PERIPH_BASE + 0x6400UL)

#define USART1_BASE           (APB2PERIPH_BASE + 0x1000UL)
#define USART6_BASE           (APB2PERIPH_BASE + 0x1400UL)

#define PWR_BASE              (APB1PERIPH_BASE + 0x7000UL)

#define USART2_BASE           (APB1PERIPH_BASE + 0x4400UL)

#define SPI1_BASE             (APB2PERIPH_BASE + 0x3000UL)
#define SPI2_BASE             (APB1PERIPH_BASE + 0x3800UL)
#define SPI3_BASE             (APB1PERIPH_BASE + 0x3C00UL)

#define I2C1_BASE             (APB1PERIPH_BASE + 0x5400UL)
#define I2C2_BASE             (APB1PERIPH_BASE + 0x5800UL)
#define I2C3_BASE             (APB1PERIPH_BASE + 0x5C00UL)

/**
  * @}
  */

/** @addtogroup Peripheral_declaration
  * @{
  */

#define GPIOA                 ((GPIO_TypeDef *)GPIOA_BASE)
#define GPIOB                 ((GPIO_TypeDef *)GPIOB_BASE)
#define GPIOC                 ((GPIO_TypeDef *)GPIOC_BASE)
#define GPIOD                 ((GPIO_TypeDef *)GPIOD_BASE)
#define GPIOE                 ((GPIO_TypeDef *)GPIOE_BASE)
#define GPIOF                 ((GPIO_TypeDef *)GPIOF_BASE)
#define GPIOG                 ((GPIO_TypeDef *)GPIOG_BASE)
#define GPIOH                 ((GPIO_TypeDef *)GPIOH_BASE)

#define CRC                   ((CRC_TypeDef *)CRC_BASE)
#define RCC                   ((RCC_TypeDef *)RCC_BASE)
#define FLASH                 ((FLASH_TypeDef *)FLASH_R_BASE)
#define PWR                   ((PWR_TypeDef *)PWR_BASE)

#define USART1                ((USART_TypeDef *)USART1_BASE)
#define USART2                ((USART_TypeDef *)USART2_BASE)
#define USART6                ((USART_TypeDef *)USART6_BASE)

#define SPI1                  ((SPI_TypeDef *)SPI1_BASE)
#define SPI2                  ((SPI_TypeDef *)SPI2_BASE)
#define SPI3                  ((SPI_TypeDef *)SPI3_BASE)

#define I2C1                  ((I2C_TypeDef *)I2C1_BASE)
#define I2C2                  ((I2C_TypeDef *)I2C2_BASE)
#define I2C3                  ((I2C_TypeDef *)I2C3_BASE)

/**
  * @}
  */

/** @addtogroup Peripheral_Registers_Bits_Definition
  * @{
  */

/******************************************************************************/
/*                         CRC calculation unit (CRC)                         */
/******************************************************************************/

#define CRC_DR_DR_Pos                     (0U)
#define CRC_DR_DR_Msk                     (0xFFFFFFFFUL << CRC_DR_DR_Pos)
#define CRC_DR_DR                         CRC_DR_DR_Msk

#define CRC_IDR_IDR_Pos                   (0U)
#define CRC_IDR_IDR_Msk                   (0xFFUL << CRC_IDR_IDR_Pos)
#define CRC_IDR_IDR                       CRC_IDR_IDR_Msk

#define CRC_CR_RESET_Pos                  (0U)
#define CRC_CR_RESET_Msk                  (0x1UL << CRC_CR_RESET_Pos)
#define CRC_CR_RESET                      CRC_CR_RESET_Msk

#define CRC_CR_POLYSIZE_Pos               (3U)
#define CRC_CR_POLYSIZE_Msk               (0x3UL << CRC_CR_POLYSIZE_Pos)
#define CRC_CR_POLYSIZE                   CRC_CR_POLYSIZE_Msk
#define CRC_CR_POLYSIZE_0                 (0x1UL << CRC_CR_POLYSIZE_Pos)
#define CRC_CR_POLYSIZE_1                 (0x2UL << CRC_CR_POLYSIZE_Pos)

#define CRC_CR_REV_IN_Pos                 (5U)
#define CRC_CR_REV_IN_Msk                 (0x3UL << CRC_CR_REV_IN_Pos)
#define CRC_CR_REV_IN                     CRC_CR_REV_IN_Msk
#define CRC_CR_REV_IN_0                  (0x1UL << CRC_CR_REV_IN_Pos)
#define CRC_CR_REV_IN_1                  (0x2UL << CRC_CR_REV_IN_Pos)

#define CRC_CR_REV_OUT_Pos                (7U)
#define CRC_CR_REV_OUT_Msk                (0x1UL << CRC_CR_REV_OUT_Pos)
#define CRC_CR_REV_OUT                    CRC_CR_REV_OUT_Msk

/******************************************************************************/
/*                         Power Control (PWR)                                */
/******************************************************************************/

#define PWR_CR_LPDS_Pos                   (0U)
#define PWR_CR_LPDS_Msk                   (0x1UL << PWR_CR_LPDS_Pos)
#define PWR_CR_LPDS                       PWR_CR_LPDS_Msk

#define PWR_CR_PDDS_Pos                   (1U)
#define PWR_CR_PDDS_Msk                   (0x1UL << PWR_CR_PDDS_Pos)
#define PWR_CR_PDDS                       PWR_CR_PDDS_Msk

#define PWR_CR_CWUF_Pos                   (2U)
#define PWR_CR_CWUF_Msk                   (0x1UL << PWR_CR_CWUF_Pos)
#define PWR_CR_CWUF                       PWR_CR_CWUF_Msk

#define PWR_CR_CSBF_Pos                   (3U)
#define PWR_CR_CSBF_Msk                   (0x1UL << PWR_CR_CSBF_Pos)
#define PWR_CR_CSBF                       PWR_CR_CSBF_Msk

#define PWR_CR_PVDE_Pos                   (4U)
#define PWR_CR_PVDE_Msk                   (0x1UL << PWR_CR_PVDE_Pos)
#define PWR_CR_PVDE                       PWR_CR_PVDE_Msk

#define PWR_CR_DBP_Pos                    (8U)
#define PWR_CR_DBP_Msk                    (0x1UL << PWR_CR_DBP_Pos)
#define PWR_CR_DBP                        PWR_CR_DBP_Msk

#define PWR_CSR_WUF_Pos                   (0U)
#define PWR_CSR_WUF_Msk                   (0x1UL << PWR_CSR_WUF_Pos)
#define PWR_CSR_WUF                       PWR_CSR_WUF_Msk

#define PWR_CSR_SBF_Pos                   (1U)
#define PWR_CSR_SBF_Msk                   (0x1UL << PWR_CSR_SBF_Pos)
#define PWR_CSR_SBF                       PWR_CSR_SBF_Msk

#define PWR_CSR_PVDO_Pos                  (2U)
#define PWR_CSR_PVDO_Msk                  (0x1UL << PWR_CSR_PVDO_Pos)
#define PWR_CSR_PVDO                      PWR_CSR_PVDO_Msk

#define PWR_CSR_EWUP_Pos                  (8U)
#define PWR_CSR_EWUP_Msk                  (0x1UL << PWR_CSR_EWUP_Pos)
#define PWR_CSR_EWUP                      PWR_CSR_EWUP_Msk

/******************************************************************************/
/*                        Reset and Clock Control (RCC)                        */
/******************************************************************************/

/* RCC_AHB1ENR */
#define RCC_AHB1ENR_GPIOAEN_Pos           (0U)
#define RCC_AHB1ENR_GPIOAEN_Msk           (0x1UL << RCC_AHB1ENR_GPIOAEN_Pos)
#define RCC_AHB1ENR_GPIOAEN               RCC_AHB1ENR_GPIOAEN_Msk

#define RCC_AHB1ENR_GPIOBEN_Pos           (1U)
#define RCC_AHB1ENR_GPIOBEN_Msk           (0x1UL << RCC_AHB1ENR_GPIOBEN_Pos)
#define RCC_AHB1ENR_GPIOBEN               RCC_AHB1ENR_GPIOBEN_Msk

#define RCC_AHB1ENR_GPIOCEN_Pos           (2U)
#define RCC_AHB1ENR_GPIOCEN_Msk           (0x1UL << RCC_AHB1ENR_GPIOCEN_Pos)
#define RCC_AHB1ENR_GPIOCEN               RCC_AHB1ENR_GPIOCEN_Msk

#define RCC_AHB1ENR_CRCEN_Pos             (12U)
#define RCC_AHB1ENR_CRCEN_Msk             (0x1UL << RCC_AHB1ENR_CRCEN_Pos)
#define RCC_AHB1ENR_CRCEN                 RCC_AHB1ENR_CRCEN_Msk

#define RCC_AHB1ENR_DMA1EN_Pos            (21U)
#define RCC_AHB1ENR_DMA1EN_Msk            (0x1UL << RCC_AHB1ENR_DMA1EN_Pos)
#define RCC_AHB1ENR_DMA1EN                RCC_AHB1ENR_DMA1EN_Msk

#define RCC_AHB1ENR_DMA2EN_Pos            (22U)
#define RCC_AHB1ENR_DMA2EN_Msk            (0x1UL << RCC_AHB1ENR_DMA2EN_Pos)
#define RCC_AHB1ENR_DMA2EN                RCC_AHB1ENR_DMA2EN_Msk

/* RCC_APB1ENR */
#define RCC_APB1ENR_USART2EN_Pos          (17U)
#define RCC_APB1ENR_USART2EN_Msk          (0x1UL << RCC_APB1ENR_USART2EN_Pos)
#define RCC_APB1ENR_USART2EN              RCC_APB1ENR_USART2EN_Msk

#define RCC_APB1ENR_PWREN_Pos             (28U)
#define RCC_APB1ENR_PWREN_Msk             (0x1UL << RCC_APB1ENR_PWREN_Pos)
#define RCC_APB1ENR_PWREN                 RCC_APB1ENR_PWREN_Msk

/* RCC_APB2ENR */
#define RCC_APB2ENR_USART1EN_Pos          (4U)
#define RCC_APB2ENR_USART1EN_Msk          (0x1UL << RCC_APB2ENR_USART1EN_Pos)
#define RCC_APB2ENR_USART1EN              RCC_APB2ENR_USART1EN_Msk

#define RCC_APB2ENR_USART6EN_Pos          (5U)
#define RCC_APB2ENR_USART6EN_Msk          (0x1UL << RCC_APB2ENR_USART6EN_Pos)
#define RCC_APB2ENR_USART6EN              RCC_APB2ENR_USART6EN_Msk

#define RCC_APB2ENR_SPI1EN_Pos            (12U)
#define RCC_APB2ENR_SPI1EN_Msk            (0x1UL << RCC_APB2ENR_SPI1EN_Pos)
#define RCC_APB2ENR_SPI1EN                RCC_APB2ENR_SPI1EN_Msk

#define RCC_APB2ENR_SYSCFGEN_Pos          (14U)
#define RCC_APB2ENR_SYSCFGEN_Msk          (0x1UL << RCC_APB2ENR_SYSCFGEN_Pos)
#define RCC_APB2ENR_SYSCFGEN              RCC_APB2ENR_SYSCFGEN_Msk

/******************************************************************************/
/*                                     FLASH                                  */
/******************************************************************************/

#define FLASH_ACR_LATENCY_Pos             (0U)
#define FLASH_ACR_LATENCY_Msk             (0x7UL << FLASH_ACR_LATENCY_Pos)
#define FLASH_ACR_LATENCY                 FLASH_ACR_LATENCY_Msk
#define FLASH_ACR_LATENCY_0WS             0x00000000U
#define FLASH_ACR_LATENCY_1WS             0x00000001U
#define FLASH_ACR_LATENCY_2WS             0x00000002U
#define FLASH_ACR_LATENCY_3WS             0x00000003U
#define FLASH_ACR_LATENCY_4WS             0x00000004U
#define FLASH_ACR_LATENCY_5WS             0x00000005U
#define FLASH_ACR_LATENCY_6WS             0x00000006U
#define FLASH_ACR_LATENCY_7WS             0x00000007U

#define FLASH_ACR_PRFTEN_Pos              (8U)
#define FLASH_ACR_PRFTEN_Msk              (0x1UL << FLASH_ACR_PRFTEN_Pos)
#define FLASH_ACR_PRFTEN                  FLASH_ACR_PRFTEN_Msk

#define FLASH_ACR_ICEN_Pos                (9U)
#define FLASH_ACR_ICEN_Msk                (0x1UL << FLASH_ACR_ICEN_Pos)
#define FLASH_ACR_ICEN                    FLASH_ACR_ICEN_Msk

#define FLASH_ACR_DCEN_Pos                (10U)
#define FLASH_ACR_DCEN_Msk                (0x1UL << FLASH_ACR_DCEN_Pos)
#define FLASH_ACR_DCEN                    FLASH_ACR_DCEN_Msk

/******************************************************************************/
/*                              USART                                         */
/******************************************************************************/

#define USART_SR_PE_Pos                   (0U)
#define USART_SR_PE_Msk                   (0x1UL << USART_SR_PE_Pos)
#define USART_SR_PE                       USART_SR_PE_Msk

#define USART_SR_FE_Pos                   (1U)
#define USART_SR_FE_Msk                   (0x1UL << USART_SR_FE_Pos)
#define USART_SR_FE                       USART_SR_FE_Msk

#define USART_SR_NE_Pos                   (2U)
#define USART_SR_NE_Msk                   (0x1UL << USART_SR_NE_Pos)
#define USART_SR_NE                       USART_SR_NE_Msk

#define USART_SR_ORE_Pos                  (3U)
#define USART_SR_ORE_Msk                  (0x1UL << USART_SR_ORE_Pos)
#define USART_SR_ORE                      USART_SR_ORE_Msk

#define USART_SR_IDLE_Pos                 (4U)
#define USART_SR_IDLE_Msk                 (0x1UL << USART_SR_IDLE_Pos)
#define USART_SR_IDLE                     USART_SR_IDLE_Msk

#define USART_SR_RXNE_Pos                 (5U)
#define USART_SR_RXNE_Msk                 (0x1UL << USART_SR_RXNE_Pos)
#define USART_SR_RXNE                     USART_SR_RXNE_Msk

#define USART_SR_TC_Pos                   (6U)
#define USART_SR_TC_Msk                   (0x1UL << USART_SR_TC_Pos)
#define USART_SR_TC                       USART_SR_TC_Msk

#define USART_SR_TXE_Pos                  (7U)
#define USART_SR_TXE_Msk                  (0x1UL << USART_SR_TXE_Pos)
#define USART_SR_TXE                      USART_SR_TXE_Msk

#define USART_SR_LBD_Pos                  (8U)
#define USART_SR_LBD_Msk                  (0x1UL << USART_SR_LBD_Pos)
#define USART_SR_LBD                      USART_SR_LBD_Msk

#define USART_SR_CTS_Pos                  (9U)
#define USART_SR_CTS_Msk                  (0x1UL << USART_SR_CTS_Pos)
#define USART_SR_CTS                      USART_SR_CTS_Msk

#define USART_CR1_SBK_Pos                 (0U)
#define USART_CR1_SBK_Msk                 (0x1UL << USART_CR1_SBK_Pos)
#define USART_CR1_SBK                     USART_CR1_SBK_Msk

#define USART_CR1_RWU_Pos                 (1U)
#define USART_CR1_RWU_Msk                 (0x1UL << USART_CR1_RWU_Pos)
#define USART_CR1_RWU                     USART_CR1_RWU_Msk

#define USART_CR1_RE_Pos                  (2U)
#define USART_CR1_RE_Msk                  (0x1UL << USART_CR1_RE_Pos)
#define USART_CR1_RE                      USART_CR1_RE_Msk

#define USART_CR1_TE_Pos                  (3U)
#define USART_CR1_TE_Msk                  (0x1UL << USART_CR1_TE_Pos)
#define USART_CR1_TE                      USART_CR1_TE_Msk

#define USART_CR1_IDLEIE_Pos              (4U)
#define USART_CR1_IDLEIE_Msk              (0x1UL << USART_CR1_IDLEIE_Pos)
#define USART_CR1_IDLEIE                  USART_CR1_IDLEIE_Msk

#define USART_CR1_RXNEIE_Pos              (5U)
#define USART_CR1_RXNEIE_Msk              (0x1UL << USART_CR1_RXNEIE_Pos)
#define USART_CR1_RXNEIE                  USART_CR1_RXNEIE_Msk

#define USART_CR1_TCIE_Pos                (6U)
#define USART_CR1_TCIE_Msk                (0x1UL << USART_CR1_TCIE_Pos)
#define USART_CR1_TCIE                    USART_CR1_TCIE_Msk

#define USART_CR1_TXEIE_Pos               (7U)
#define USART_CR1_TXEIE_Msk               (0x1UL << USART_CR1_TXEIE_Pos)
#define USART_CR1_TXEIE                   USART_CR1_TXEIE_Msk

#define USART_CR1_PEIE_Pos                (8U)
#define USART_CR1_PEIE_Msk                (0x1UL << USART_CR1_PEIE_Pos)
#define USART_CR1_PEIE                    USART_CR1_PEIE_Msk

#define USART_CR1_PS_Pos                  (9U)
#define USART_CR1_PS_Msk                  (0x1UL << USART_CR1_PS_Pos)
#define USART_CR1_PS                      USART_CR1_PS_Msk

#define USART_CR1_PCE_Pos                 (10U)
#define USART_CR1_PCE_Msk                 (0x1UL << USART_CR1_PCE_Pos)
#define USART_CR1_PCE                     USART_CR1_PCE_Msk

#define USART_CR1_WAKE_Pos                (11U)
#define USART_CR1_WAKE_Msk                (0x1UL << USART_CR1_WAKE_Pos)
#define USART_CR1_WAKE                    USART_CR1_WAKE_Msk

#define USART_CR1_M_Pos                   (12U)
#define USART_CR1_M_Msk                   (0x1UL << USART_CR1_M_Pos)
#define USART_CR1_M                       USART_CR1_M_Msk

#define USART_CR1_UE_Pos                  (13U)
#define USART_CR1_UE_Msk                  (0x1UL << USART_CR1_UE_Pos)
#define USART_CR1_UE                      USART_CR1_UE_Msk

#define USART_CR1_OVER8_Pos               (15U)
#define USART_CR1_OVER8_Msk               (0x1UL << USART_CR1_OVER8_Pos)
#define USART_CR1_OVER8                   USART_CR1_OVER8_Msk

#define USART_CR2_STOP_Pos                (12U)
#define USART_CR2_STOP_Msk                (0x3UL << USART_CR2_STOP_Pos)
#define USART_CR2_STOP                    USART_CR2_STOP_Msk
#define USART_CR2_STOP_0                  (0x1UL << USART_CR2_STOP_Pos)
#define USART_CR2_STOP_1                  (0x2UL << USART_CR2_STOP_Pos)

#define USART_CR3_EIE_Pos                 (0U)
#define USART_CR3_EIE_Msk                 (0x1UL << USART_CR3_EIE_Pos)
#define USART_CR3_EIE                     USART_CR3_EIE_Msk

#define USART_CR3_IREN_Pos                (1U)
#define USART_CR3_IREN_Msk                (0x1UL << USART_CR3_IREN_Pos)
#define USART_CR3_IREN                    USART_CR3_IREN_Msk

#define USART_CR3_IRLP_Pos                (2U)
#define USART_CR3_IRLP_Msk                (0x1UL << USART_CR3_IRLP_Pos)
#define USART_CR3_IRLP                    USART_CR3_IRLP_Msk

#define USART_CR3_HDSEL_Pos               (3U)
#define USART_CR3_HDSEL_Msk               (0x1UL << USART_CR3_HDSEL_Pos)
#define USART_CR3_HDSEL                   USART_CR3_HDSEL_Msk

#define USART_CR3_DMAT_Pos                (7U)
#define USART_CR3_DMAT_Msk                (0x1UL << USART_CR3_DMAT_Pos)
#define USART_CR3_DMAT                    USART_CR3_DMAT_Msk

#define USART_CR3_DMAR_Pos                (6U)
#define USART_CR3_DMAR_Msk                (0x1UL << USART_CR3_DMAR_Pos)
#define USART_CR3_DMAR                    USART_CR3_DMAR_Msk

#define USART_CR3_RTSE_Pos                (8U)
#define USART_CR3_RTSE_Msk                (0x1UL << USART_CR3_RTSE_Pos)
#define USART_CR3_RTSE                    USART_CR3_RTSE_Msk

#define USART_CR3_CTSE_Pos                (9U)
#define USART_CR3_CTSE_Msk                (0x1UL << USART_CR3_CTSE_Pos)
#define USART_CR3_CTSE                    USART_CR3_CTSE_Msk

#define USART_CR3_CTSIE_Pos               (10U)
#define USART_CR3_CTSIE_Msk               (0x1UL << USART_CR3_CTSIE_Pos)
#define USART_CR3_CTSIE                   USART_CR3_CTSIE_Msk

/******************************************************************************/
/*                              GPIO                                          */
/******************************************************************************/

#define GPIO_MODER_MODER0_Pos             (0U)

/*
 * CMSIS-compliant standard peripheral register bit definition macros.
 * Minimal set for GPIO alternate function modes.
 */
#define GPIO_PIN_9                        ((uint16_t)0x0200)
#define GPIO_PIN_10                       ((uint16_t)0x0400)
#define GPIO_PIN_2                        ((uint16_t)0x0004)
#define GPIO_PIN_3                        ((uint16_t)0x0008)

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __STM32F401xE_H */
