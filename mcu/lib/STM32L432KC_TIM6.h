// Christian Wu
// chrwu@g.hmc.edu
// 09/19/25

// STM32L432KC_TIM6.h
// Header for TIM6 functions

#ifndef STM32L4_TIM6_H
#define STM32L4_TIM6_H

#include <stdint.h>

///////////////////////////////////////////////////////////////////////////////
// Definitions
///////////////////////////////////////////////////////////////////////////////

#define __IO volatile

// Base addresses for GPIO ports
#define TIM6_BASE (0x40001000UL) // base address of TIM6

///////////////////////////////////////////////////////////////////////////////
// Bitfield struct for GPIO
///////////////////////////////////////////////////////////////////////////////

typedef struct {
  __IO uint32_t TIM6_CR1;       /*!< TIM6 control register 1,               Address offset: 0x00 */
  __IO uint32_t TIM6_CR2;       /*!< TIM6 control register 2,               Address offset: 0x04 */
  uint32_t      RESERVED0;      /*!< Reserved,                              Address offset: 0x08 */
  __IO uint32_t TIM6_DIER;      /*!< TIM6 DMA/Interrupt Enable Register,    Address offset: 0x0C */
  __IO uint32_t TIM6_SR;        /*!< TIM6 Status Register,                  Address offset: 0x10 */
  __IO uint32_t TIM6_EGR;       /*!< TIM6 Event Generation Register,        Address offset: 0x14 */
  uint32_t      RESERVED1;      /*!< Reserved,                              Address offset: 0x18 */
  uint32_t      RESERVED2;      /*!< Reserved,                              Address offset: 0x1C */
  uint32_t      RESERVED3;      /*!< Reserved,                              Address offset: 0x20 */
  __IO uint32_t TIM6_CNT;       /*!< TIM6 Counter,                          Address offset: 0x24 */
  __IO uint32_t TIM6_PSC;       /*!< TIM6 Prescaler,                        Address offset: 0x28 */
  __IO uint32_t TIM6_ARR;       /*!< TIM6 Auto-Reload Register,             Address offset: 0x2C */
  
} TIM6_TypeDef;

#define TIM6 ((TIM6_TypeDef *) TIM6_BASE)

///////////////////////////////////////////////////////////////////////////////
// Function prototypes
///////////////////////////////////////////////////////////////////////////////

void configureTIM6();

void setDelay(int ms);

#endif