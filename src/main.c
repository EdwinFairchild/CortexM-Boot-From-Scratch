#include "stdint.h"

// these will end up in the .rodata section
const volatile uint32_t dummy1 = 0x12345678;
const volatile uint32_t dummy2 = 0x87654321;
const volatile float pi = 3.14159;
const volatile char msg[] = "Hello, World!";

// these will end up in the .bss section
volatile uint32_t counter;
volatile uint32_t data[10];


// main function will end up in the .text section
void main(void)
{
    // Infinite loop
    while(1);
}