// Christian Wu
// chrwu@g.hmc.edu
// 09/19/25

// Code to utilize TIM6 for delays

#include "../lib/STM32L432KC_TIM6.h"
#include "../lib/STM32L432KC_RCC.h"

void configureTIM6() {

    // Set clock to 4 MHz
    RCC->APB1ENR1 |= (1 << 4);
    
    // Set clock to 1 kHz
    TIM6->TIM6_PSC = 3999;

    // Set the auto-reload preload enable in TIM16_CR1
    TIM6->TIM6_CR1 |= (1 << 7);

    // Set update generation bit in TIM16_EGR
    TIM6->TIM6_EGR |= (1 << 0);
}

void setDelay(int ms) {
    
    // Set auto-reload registers in TIM6_ARR
    TIM6->TIM6_ARR = ms - 1;

    // Set update generation bit in TIM16_EGR
    TIM6->TIM6_EGR |= (1 << 0);

    // Clear UIF in TIM6_SR
    TIM6->TIM6_SR &= ~(1 << 0);

    // Reset Count in TIM6_CNT
    TIM6->TIM6_CNT = 0;

    // Set timer counter enable in TIM16_CR1
    TIM6->TIM6_CR1 |= (1 << 0);

    while(!(TIM6->TIM6_SR & 1)){

    }

    // Clear UIF in TIM6_SR
    TIM6->TIM6_SR &= ~(1 << 0);
}