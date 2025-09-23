// Christian Wu
// chrwu@g.hmc.edu
// 09/19/25

// STM32L432KC_TIM16.h
// Header for TIM16 functions

#ifndef STM32L4_TIM16_H
#define STM32L4_TIM16_H

#include <stdint.h>

///////////////////////////////////////////////////////////////////////////////
// Definitions
///////////////////////////////////////////////////////////////////////////////

#define __IO volatile

// Base addresses for GPIO ports
#define TIM16_BASE (0x40014400) // base address of TIM16

///////////////////////////////////////////////////////////////////////////////
// Bitfield struct for GPIO
///////////////////////////////////////////////////////////////////////////////

typedef struct {
  __IO uint32_t TIM16_CR1;      /*!< TIM16 control register 1,              Address offset: 0x00 */
  __IO uint32_t TIM16_CR2;      /*!< TIM16 control register 2,              Address offset: 0x04 */
  uint32_t      RESERVED0;      /*!< Reserved,                              Address offset: 0x08 */
  __IO uint32_t TIM16_DIER;     /*!< TIM16 DMA/Interrupt Enable Register,   Address offset: 0x0C */
  __IO uint32_t TIM16_SR;       /*!< TIM16 Status Register,                 Address offset: 0x10 */
  __IO uint32_t TIM16_EGR;      /*!< TIM16 Event Generation Register,       Address offset: 0x14 */
  __IO uint32_t TIM16_CCMR1;    /*!< TIM16 Capture/Compare Mode Register 1, Address offset: 0x18 */
  uint32_t      RESERVED1;      /*!< Reserved,                              Address offset: 0x1C */
  __IO uint32_t TIM16_CCER;     /*!< TIM16 Capture/Compare Enable Register, Address offset: 0x20 */
  __IO uint32_t TIM16_CNT;      /*!< TIM16 Counter,                         Address offset: 0x24 */
  __IO uint32_t TIM16_PSC;      /*!< TIM16 Prescaler,                       Address offset: 0x28 */
  __IO uint32_t TIM16_ARR;      /*!< TIM16 Auto-Reload Register,            Address offset: 0x2C */
  __IO uint32_t TIM16_RCR;      /*!< TIM16 Repetition Counter Register,     Address offset: 0x30 */
  __IO uint32_t TIM16_CCR1;     /*!< TIM16 Capture/Compare Register 1,      Address offset: 0x34 */
  uint32_t      RESERVED2;      /*!< Reserved,                              Address offset: 0x38 */
  uint32_t      RESERVED3;      /*!< Reserved,                              Address offset: 0x3C */
  uint32_t      RESERVED4;      /*!< Reserved,                              Address offset: 0x40 */
  __IO uint32_t TIM16_BDTR;     /*!< TIM16 Break and Dead-Time Register,    Address offset: 0x44 */
  __IO uint32_t TIM16_DCR;      /*!< TIM16 DMA Control Register,            Address offset: 0x48 */
  __IO uint32_t TIM16_DMAR;     /*!< TIM16 DMA Address For Full Transfer,   Address offset: 0x4C */
  __IO uint32_t TIM16_OR1;      /*!< TIM16 Option Register 1,               Address offset: 0x50 */
  uint32_t      RESERVED5;      /*!< Reserved,                              Address offset: 0x54 */
  uint32_t      RESERVED6;      /*!< Reserved,                              Address offset: 0x58 */
  uint32_t      RESERVED7;      /*!< Reserved,                              Address offset: 0x5C */
  __IO uint32_t TIM16_OR2;      /*!< TIM16 Option Register 2,               Address offset: 0x60 */
} TIM16_TypeDef;

#define TIM16 ((TIM16_TypeDef *) TIM16_BASE)

///////////////////////////////////////////////////////////////////////////////
// Function prototypes
///////////////////////////////////////////////////////////////////////////////

void configureTIM16();

void setPWM(int frequency, int dutyCycle);

#endif