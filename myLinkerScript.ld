/* Entry Point */
ENTRY(Reset_Handler)

/* Highest address in RAM, which is basically start of stack */
_top_of_ram_stack_start = ORIGIN(RAM) + LENGTH(RAM);

/* Generate a link error if heap and stack don't fit into RAM */
_Min_Heap_Size = 0x200;      /* required amount of heap  */
_Min_Stack_Size = 0x400; /* required amount of stack */

/* Specify the memory areas */
MEMORY
{
RAM(xrw):ORIGIN =0x20000000, LENGTH =36K
FLASH(rx):ORIGIN =0x8000000, LENGTH =128K
}

SECTIONS
{
    /* Vector table */
    .isr_vector :
    {
        . = ALIGN(4);
        KEEP(*(.isr_vector)) /* Startup code */
        . = ALIGN(4);
    } >FLASH
    

    /* Program code */
    .text :
    {
        . = ALIGN(4);
        /* *(.isr_vector) */
        *(.text) /* .text sections (code) */
        *(.text*) /* .text* sections (code) */
        *(.glue_7) /* glue arm to thumb code */
        *(.glue_7t) /* glue thumb to arm code */
        . = ALIGN(4);
    } >FLASH

    /* Read only data (constants) */
    .rodata :
    {
        . = ALIGN(4);
        *(.rodata)   /* Include the .rodata section */
        *(.rodata*)  /* Include all sections that start with .rodata */
        . = ALIGN(4);
    } >FLASH

    /* Data Sections */
    .data :
    {
        . = ALIGN(4);
        _data = .; /* symbol to hold start address */
        *(.data) /* .data sections */
        *(.data*) /* .data* sections */
        . = ALIGN(4);
        _edata = .; /* symbol to hold end address */
    } >RAM AT> FLASH

    /* This symbol points to the start of the data in Flash */
    _sidata = LOADADDR(.data);

    /* BSS Section */
    .bss :
    {
        . = ALIGN(4);
        _bss = .; /* symbol to hold start address */
        *(.bss)
        *(.bss*)
        *(COMMON)
        . = ALIGN(4);
        _ebss = .; /* symbol to hold end address */
    } >RAM

    /* User_heap_stack section, used to check that there is enough RAM left */
    ._user_heap_stack :
    {
        . = ALIGN(8);
        PROVIDE ( end = . );
        PROVIDE ( _end = . );
        . = . + _Min_Heap_Size;
        . = . + _Min_Stack_Size;
        . = ALIGN(8);
    } >RAM

}