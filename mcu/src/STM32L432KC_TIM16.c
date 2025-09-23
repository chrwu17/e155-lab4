// Christian Wu
// chrwu@g.hmc.edu
// 09/19/25

#include "../lib/STM32L432KC_TIM16.h"
#include "../lib/STM32L432KC_RCC.h"

void configureTIM16() {
    
    // Set Clock to 4 MHz
    RCC->AHB2ENR |= (1 << 0);
    RCC->APB2ENR |= (1 << 17);
    RCC->CFGR &= ~(0b1111 << 4);
    RCC->CFGR &= ~(0b111 << 13);

    // Use prescaler to set clock to 100 kHz in TIM16_PSC
    TIM16->TIM16_PSC = 39;

    // Set Auto Reload Register in TIM16_ARR
    TIM16->TIM16_ARR = 0xFFFF;

    // Set the auto-reload preload enable in TIM16_CR1
    TIM16->TIM16_CR1 |= (1 << 7);

    // Set timer counter enable in TIM16_CR1
    TIM16->TIM16_CR1 |= (1 << 0);

    // Set main output enable in TIM16_BDTR
    TIM16->TIM16_BDTR |= (1 << 15);

    // Set output enable in TIM16_CCER
    TIM16->TIM16_CCER |= (1 << 0);

    // Set Capture/compare register in TIM16_CCR1
    TIM16->TIM16_CCR1 = 0;

    // Set PWM Mode in TIM16_CCMR1
    TIM16->TIM16_CCMR1 |= (1 << 3);
    TIM16->TIM16_CCMR1 |= (1 << 5);
    TIM16->TIM16_CCMR1 |= (1 << 6);
    TIM16->TIM16_CCMR1 &= ~(0b11 << 0);

    // Set update generation bit in TIM16_EGR
    TIM16->TIM16_EGR |= (1 << 0);
}

void setPWM(int frequency, int dutyCycle) {
    // Set ARR in TIM16_ARR
    TIM16->TIM16_ARR = 100000/frequency;
    
    // Set Duty Cycle in TIM16_CCR1
    TIM16->TIM16_CCR1 = 100000/frequency * dutyCycle/100;

    // Set update generation bit in TIM16_EGR
    TIM16->TIM16_EGR |= (1 << 0);
}