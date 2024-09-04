    #include "stdint.h"

    // these will end up in the .data section
    volatile uint32_t dummy1 = 0x12345678;
    // these will end up in the .rodata section becuase they are constant
    const  uint32_t dummy2 = 0x87654321;
    const  float pi = 3.14159;
    const  char msg[] = "Hello, World!";

    // these will end up in the .bss section because they are uninitialized
    volatile uint32_t counter;
    volatile uint32_t data[10];


    // main function will end up in the .text section
    void main(void)
    {
        char msgCopy[sizeof(msg)];
        // Infinite loop
        while(1){
            counter++;
            // Copy the message to another array
            for (uint32_t i = 0; i < sizeof(msg); i++)
            {
                msgCopy[i] = msg[i];
            }
            
            
        }
    }