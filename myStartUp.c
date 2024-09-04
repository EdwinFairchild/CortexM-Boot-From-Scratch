#include <stdint.h>

// Linker symbols that are used to prepare the vector table
extern uint32_t _top_of_ram_stack_start;
extern uint32_t _data;
extern uint32_t _edata;
extern uint32_t _sidata;
extern uint32_t _bss;
extern uint32_t _ebss;

extern void main(void);
void Reset_Handler(void);
void Default_Handler(void);


// All handlers will default to Default_Handler until they are reimplemented in the application code
void NMI_Handler(void)                          __attribute__((weak, alias("Default_Handler")));
void HardFault_Handler(void)                    __attribute__((weak, alias("Default_Handler")));
void MemManage_Handler(void)                    __attribute__((weak, alias("Default_Handler")));
void BusFault_Handler(void)                     __attribute__((weak, alias("Default_Handler")));
void UsageFault_Handler(void)                   __attribute__((weak, alias("Default_Handler")));
void SVC_Handler(void)                          __attribute__((weak, alias("Default_Handler")));
void DebugMon_Handler(void)                     __attribute__((weak, alias("Default_Handler")));
void PendSV_Handler(void)                       __attribute__((weak, alias("Default_Handler")));
void SysTick_Handler(void)                      __attribute__((weak, alias("Default_Handler")));
//----------------------------------------------------------------------------------------------
void WWDG_IRQHandler(void)                      __attribute__((weak, alias("Default_Handler")));
void PVD_IRQHandler(void)                       __attribute__((weak, alias("Default_Handler")));
void RTC_TAMP_IRQHandler(void)                  __attribute__((weak, alias("Default_Handler")));
void FLASH_IRQHandler(void)                     __attribute__((weak, alias("Default_Handler")));
void RCC_IRQHandler(void)                       __attribute__((weak, alias("Default_Handler")));
void EXTI0_1_IRQHandler(void)                   __attribute__((weak, alias("Default_Handler")));
void EXTI2_3_IRQHandler(void)                   __attribute__((weak, alias("Default_Handler")));
void EXTI4_15_IRQHandler(void)                  __attribute__((weak, alias("Default_Handler")));
void UCPD1_2_IRQHandler(void)                   __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel1_IRQHandler(void)             __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel2_3_IRQHandler(void)           __attribute__((weak, alias("Default_Handler")));
void DMA1_Ch4_7_DMAMUX1_OVR_IRQHandler(void)    __attribute__((weak, alias("Default_Handler")));
void ADC1_COMP_IRQHandler(void)                 __attribute__((weak, alias("Default_Handler")));
void TIM1_BRK_UP_TRG_COM_IRQHandler(void)       __attribute__((weak, alias("Default_Handler")));
void TIM1_CC_IRQHandler(void)                   __attribute__((weak, alias("Default_Handler")));
void TIM2_IRQHandler(void)                      __attribute__((weak, alias("Default_Handler")));
void TIM3_IRQHandler(void)                      __attribute__((weak, alias("Default_Handler")));
void TIM6_DAC_LPTIM1_IRQHandler(void)           __attribute__((weak, alias("Default_Handler")));
void TIM7_LPTIM2_IRQHandler(void)               __attribute__((weak, alias("Default_Handler")));  
void TIM14_IRQHandler(void)                     __attribute__((weak, alias("Default_Handler")));
void TIM15_IRQHandler(void)                     __attribute__((weak, alias("Default_Handler")));
void TIM16_IRQHandler(void)                     __attribute__((weak, alias("Default_Handler")));
void TIM17_IRQHandler(void)                     __attribute__((weak, alias("Default_Handler")));
void I2C1_IRQHandler(void)                      __attribute__((weak, alias("Default_Handler")));
void I2C2_IRQHandler(void)                      __attribute__((weak, alias("Default_Handler")));
void SPI1_IRQHandler(void)                      __attribute__((weak, alias("Default_Handler")));
void SPI2_IRQHandler(void)                      __attribute__((weak, alias("Default_Handler")));
void USART1_IRQHandler(void)                    __attribute__((weak, alias("Default_Handler")));
void USART2_IRQHandler(void)                    __attribute__((weak, alias("Default_Handler")));
void USART3_4_LPUART1_IRQHandler(void)          __attribute__((weak, alias("Default_Handler")));
void CEC_IRQHandler(void)                       __attribute__((weak, alias("Default_Handler")));



uint32_t vector_table[] __attribute__((section(".isr_vector"))) = {
    (uint32_t)&_top_of_ram_stack_start,     // Initial Stack Pointer
    //--------| System Exception Handlers |-----------------------------
    (uint32_t)&Reset_Handler,               // Reset Handler
    (uint32_t)&NMI_Handler,                 // NMI Handler
    (uint32_t)&HardFault_Handler,           // Hard Fault Handler
    (uint32_t)&MemManage_Handler,           // MPU Fault Handler
    (uint32_t)&BusFault_Handler,            // Bus Fault Handler
    (uint32_t)&UsageFault_Handler,          // Usage Fault Handler
    0, 0, 0, 0,                             // Reserved
    (uint32_t)&SVC_Handler,                 // SVCall Handler
    (uint32_t)&DebugMon_Handler,            // Debug Monitor Handler
    0,                                      // Reserved
    (uint32_t)&PendSV_Handler,              // PendSV Handler
    (uint32_t)&SysTick_Handler,             // SysTick Handler
    //--------| Peripheral Interrupts Handlers |--------------------------
    (uint32_t)&WWDG_IRQHandler,                   /* Window WatchDog              */
    (uint32_t)&PVD_IRQHandler,                    /* PVD through EXTI Line detect */
    (uint32_t)&RTC_TAMP_IRQHandler,               /* RTC through the EXTI line    */
    (uint32_t)&FLASH_IRQHandler,                  /* FLASH                        */
    (uint32_t)&RCC_IRQHandler,                    /* RCC                          */
    (uint32_t)&EXTI0_1_IRQHandler,                /* EXTI Line 0 and 1            */
    (uint32_t)&EXTI2_3_IRQHandler,                /* EXTI Line 2 and 3            */
    (uint32_t)&EXTI4_15_IRQHandler,               /* EXTI Line 4 to 15            */
    (uint32_t)&UCPD1_2_IRQHandler,                /* UCPD1, UCPD2                 */
    (uint32_t)&DMA1_Channel1_IRQHandler,          /* DMA1 Channel 1               */
    (uint32_t)&DMA1_Channel2_3_IRQHandler,        /* DMA1 Channel 2 and Channel 3 */
    (uint32_t)&DMA1_Ch4_7_DMAMUX1_OVR_IRQHandler, /* DMA1 Channel 4 to Channel 7, DMAMUX1 overrun */
    (uint32_t)&ADC1_COMP_IRQHandler,              /* ADC1, COMP1 and COMP2         */
    (uint32_t)&TIM1_BRK_UP_TRG_COM_IRQHandler,    /* TIM1 Break, Update, Trigger and Commutation */
    (uint32_t)&TIM1_CC_IRQHandler,                /* TIM1 Capture Compare         */
    (uint32_t)&TIM2_IRQHandler,                   /* TIM2                         */
    (uint32_t)&TIM3_IRQHandler,                   /* TIM3                         */
    (uint32_t)&TIM6_DAC_LPTIM1_IRQHandler,        /* TIM6, DAC and LPTIM1         */
    (uint32_t)&TIM7_LPTIM2_IRQHandler,            /* TIM7 and LPTIM2              */
    (uint32_t)&TIM14_IRQHandler,                  /* TIM14                        */
    (uint32_t)&TIM15_IRQHandler,                  /* TIM15                        */
    (uint32_t)&TIM16_IRQHandler,                  /* TIM16                        */
    (uint32_t)&TIM17_IRQHandler,                  /* TIM17                        */
    (uint32_t)&I2C1_IRQHandler,                   /* I2C1                         */
    (uint32_t)&I2C2_IRQHandler,                   /* I2C2                         */
    (uint32_t)&SPI1_IRQHandler,                   /* SPI1                         */
    (uint32_t)&SPI2_IRQHandler,                   /* SPI2                         */
    (uint32_t)&USART1_IRQHandler,                 /* USART1                       */
    (uint32_t)&USART2_IRQHandler,                 /* USART2                       */
    (uint32_t)&USART3_4_LPUART1_IRQHandler,       /* USART3, USART4 and LPUART1   */
    (uint32_t)&CEC_IRQHandler                     /* CEC                          */
};

    void Reset_Handler(void)
    {
        // Copy .data section from Flash to RAM
        uint32_t size = (uint32_t)&_edata - (uint32_t)&_data;
        uint8_t *pDst = (uint8_t *)&_data; // pointer to start of RAM
        uint8_t *pSrc = (uint8_t *)&_sidata; // pointer to start of Flash

        for (uint32_t i = 0; i < size; i++)
        {
            *pDst++ = *pSrc++;
        }

        // Initialize the .bss section to zero in RAM
        size = (uint32_t)&_ebss - (uint32_t)&_bss;
        pDst = (uint8_t *)&_bss;

        for (uint32_t i = 0; i < size; i++)
        {
            *pDst++ = 0;
        }

        // do other initialization if your application requires it before you get to main
        // typically bootloader stuff, other checks, etc.

        // Call main() function
        main();

        while (1)
        {
            //should never get here unless something went wrong
        }
    }

    void Default_Handler(void)
    {
        // handle this how ever you want
        while (1)
        {
        }
    }

