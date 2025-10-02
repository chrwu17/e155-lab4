// Christian Wu
// chrwu@g.hmc.edu
// 09/19/25

// Taken from E155 Course Website

// STM32L432KC_FLASH.c
// Source code for FLASH functions

#include "../lib/STM32L432KC_FLASH.h"

void configureFlash() {
    FLASH->ACR |= (0b100); // Set to 4 waitstates
    FLASH->ACR |= (1 << 8); // Turn on the ART
}