// Christian Wu
// chrwu@g.hmc.edu
// 09/19/25

#include "../lib/STM32L432KC_TIM16.h"
#include "../lib/STM32L432KC_RCC.h"

void configureTIM16() {
    
    // Set Clock to 4 MHz
    // Enable GPIO A
    RCC->AHB2ENR |= (1 << 0);
    // Enable TIM16
    RCC->APB2ENR |= (1 << 17);

    // Use prescaler to set clock to 1 MHz in TIM16_PSC
    TIM16->TIM16_PSC = 3;

    // Set Auto Reload Register in TIM16_ARR
    TIM16->TIM16_ARR = 0xFFFF;

    // Set PWM Mode in TIM16_CCMR1
    TIM16->TIM16_CCMR1 &= ~(0b111 << 4);  // Clear OC1M[6:4] bits
    TIM16->TIM16_CCMR1 |= (0b110 << 4);   // Set PWM Mode 1 (110)
    TIM16->TIM16_CCMR1 |= (1 << 3);       // Set OC1PE (preload enable)
    TIM16->TIM16_CCMR1 &= ~(0b11 << 0);   // Clear CC1S (output mode)

    // Set the auto-reload preload enable in TIM16_CR1
    TIM16->TIM16_CR1 |= (1 << 7);

    // Set output enable in TIM16_CCER
    TIM16->TIM16_CCER |= (1 << 0);

    // Set main output enable in TIM16_BDTR
    TIM16->TIM16_BDTR |= (1 << 15);

    // Set Capture/compare register in TIM16_CCR1
    TIM16->TIM16_CCR1 = 0;

    // Set update generation bit in TIM16_EGR
    TIM16->TIM16_EGR |= (1 << 0);

    // Set timer counter enable in TIM16_CR1
    TIM16->TIM16_CR1 |= (1 << 0);
}

void setPWM(int frequency, int dutyCycle) {

    if (frequency == 0) {
      TIM16->TIM16_CCER &= ~(1 << 0);
      TIM16->TIM16_CCR1 = 0;
      return;
      }

    // Set ARR values as a variable
    uint32_t arr_value = (1000000 / frequency) - 1;

    // Set ARR in TIM16_ARR
    TIM16->TIM16_ARR = arr_value;
    
    // Set Duty Cycle in TIM16_CCR1
    TIM16->TIM16_CCR1 = (arr_value + 1) * dutyCycle/100;

    // Set update generation bit in TIM16_EGR
    TIM16->TIM16_EGR |= (1 << 0);

}