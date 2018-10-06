/*
 * Danfoss MSK linker script for STM32F205ZET7 MCU
 */
__main_stack_size__ = 0x400;
__process_stack_size__ = 0x200;
__stacks_total_size__ = __main_stack_size__ + __process_stack_size__;

/* Memory Spaces Definitions */

MEMORY
{
  VECTORTABLERAM (xrw)    : ORIGIN = 0x20000000, LENGTH = 0x00400
  BOOTSHAREDRAM (xrw)     : ORIGIN = 0x20000400, LENGTH = 0x00040
  SECBOOTSHAREDRAM (xrw)  : ORIGIN = 0x20000440, LENGTH = 0x00040
  RAM (xrw)               : ORIGIN = 0x20000480, LENGTH = 0x1F580 
  STACK (xrw)             : ORIGIN = (0x20000480 + LENGTH(RAM)), LENGTH = 0x00600

  KRNVECTORTABLEFLASH (rx): ORIGIN = 0x08004000, LENGTH = 0x00040
  KRNVALIDAPPFLASH (rx)   : ORIGIN = 0x08004040, LENGTH = 0x00004
  KRNCRCTABLEFLASH (rx)   : ORIGIN = 0x08004044, LENGTH = 0x00014   /* changing this field requires update of _HEXRANGE */
  RSVDFORSECONDBOOT(rx)   : ORIGIN = 0x08004058, LENGTH = 0x00008    
  KRNFLASH_I(rx)          : ORIGIN = 0x08004060, LENGTH = 0x03FA0   /* just to satisfy GUIDE tool chain to calculate ROM usage */ 
  KRNFLASH (rx)           : ORIGIN = 0x08008000, LENGTH = 0x78000
  
  KRNSERFLASH (rx)        : ORIGIN = 0x01000000, LENGTH = 0x10000	/* physical ORIGIN = 0xC0000000, LENGTH = 0x10000 */
  SERFLASH (rx)           : ORIGIN = (0x01000000 + LENGTH(KRNSERFLASH)), LENGTH = 0x3F0000	/* physical ORIGIN = (0xC0000000 + LENGTH(KRNSERFLASH)), LENGTH = 0x3F0000 */
}

__ram_start__           = ORIGIN(RAM);
__ram_size__            = LENGTH(RAM);
__ram_end__             = __ram_start__ + __ram_size__;
__process_stack_start__ = ORIGIN(STACK) + __process_stack_size__;
__main_stack_start__    = ORIGIN(STACK) + __stacks_total_size__;
_validData_size         = LENGTH(KRNVALIDAPPFLASH);

/* Sections Definitions */
/* In case of changes in RAM / ROM defintion, the file 'memnames.txt' has to be modified! */

SECTIONS
{
    . = 0;
    
    /* for Cortex devices, the beginning of the startup code is stored in the .isr_vector section, which goes to FLASH */
    .isr_vector :
    {
       . = ALIGN(4);
       __krn_vector_table_start = .;
       KEEP(*(.isr_vector))       /* NVIC */
       . = ALIGN(4);
       __krn_vector_table_end = .;
    } >KRNVECTORTABLEFLASH
    
    .validApp :
    {
        . = ALIGN(4);
        _validData = .;
        KEEP(*(.validApp))        /* valid flag code */
    } >KRNVALIDAPPFLASH

    .CRCField :                   /* changing this field requires update of _HEXRANGE */
    {
	    . = ALIGN(4);
        PROVIDE(_CRCSTART = .);
        KEEP(*(.CRCField))        /* CRC field code */
        . = ALIGN(4);
    } >KRNCRCTABLEFLASH

    .textKrnl : ALIGN(4)
    {
         *AppLayer.a:vector.o(.text.*)
         *AppLayer.a:chmempools.o(.text.*)
         *AppLayer.a:chheap.o(.text.*)
         *AppLayer.a:KWP2kSocket.o(.text.*)
         *AppLayer.a:chcore_v7m.o(.text.*)
         *AppLayer.a:chschd.o(.text.*)
         *AppLayer.a:EEPROMdrv.o(.text.*)
         *AppLayer.a:chsys.o(.text.*)
         *AppLayer.a:chmtx.o(.text.*)
         *AppLayer.a:system.o(.text.*)
         *AppLayer.a:chthreads.o(.text.*)
         *AppLayer.a:History.o(.text.*)
         *AppLayer.a:CanSTM32f2xx.o(.text.*) 
         *AppLayer.a:RTOS_Chibios.o(.text.*) 
         cstart.o(.text.*)
         *AppLayer.a:CAN.o(.text.*) 
         *AppLayer.a:core_cm3.o(.text.*)
         *AppLayer.a:chmemcore.o(.text.*) 
         *AppLayer.a:chvt.o(.text.*)
         *AppLayer.a:SerialDriver.o(.text.*) 
         *AppLayer.a:SPI.o(.text.*) 
         *AppLayer.a:CalcProgramCrc.o(.text.*)
    } > KRNFLASH_I
    
	.HexRange :                  /* This section needs to be prior the .text section so */
    							 /* HexRange is placed in the very beginning of the KRNFLASH sector */
    {
	. = ALIGN(4);
        PROVIDE(_text = .);
        KEEP(*(.HexRange))        /* HexRange field code */
        . = ALIGN(4);
    } >KRNFLASH


    .text : ALIGN(4)
    {
        _text = .;
        *(.text)
        *(.text.*)
        *(.rodata)
        *(.rodata.*)
        *(.glue_7t)
        *(.glue_7)
        *(.gcc*)
    } > KRNFLASH

    .ctors : ALIGN(4) 
    {
        PROVIDE(_ctors_start_ = .);
        KEEP(*(SORT(.ctors.*)))
        KEEP(*(.ctors))
        PROVIDE(_ctors_end_ = .);
    } > KRNFLASH

    .dtors : ALIGN(4)
    {
        PROVIDE(_dtors_start_ = .);
        KEEP(*(SORT(.dtors.*)))
        KEEP(*(.dtors))
        PROVIDE(_dtors_end_ = .);
    } > KRNFLASH

    .ARM.extab : ALIGN(4)
    {
        *(.ARM.extab* .gnu.linkonce.armextab.*)
    }

    __exidx_start = .;
    .ARM.exidx : ALIGN(4)
    {
        *(.ARM.exidx* .gnu.linkonce.armexidx.*)
    } > KRNFLASH
    __exidx_end = .;

    .eh_frame_hdr : {*(.eh_frame_hdr)}

    .eh_frame : ONLY_IF_RO {*(.eh_frame)}

    . = ALIGN(4);
    _sidata = .;
    _textdata = _sidata;
    
    /* locate the shared memory in the beginning of RAM */
    .isr_vector_RAM  (NOLOAD):
    {
    . = ALIGN(4);
	    __ram_vector_table_start = .;
        *(.isr_vector_RAM)            /* NVIC RAM table */
    . = ALIGN(4);
    } >VECTORTABLERAM
    
    /* locate the shared memory in the beginning of RAM */
    .SharedMemory  (NOLOAD):
    {
    . = ALIGN(4);
        *(.SharedMemory)            /* Shared ram memory between bootloader and kernel */
    . = ALIGN(4);
    } >BOOTSHAREDRAM

    .CommRAMbss (NOLOAD) : ALIGN(4)
    {
        _CommRAMbss_start = .;
        . = ALIGN(4);
        *(.CommRAMbss)            /* Shared ram memory between bootloader and kernel */
        . = ALIGN(4);
        _CommRAMbss_end = .;
    } > RAM 
  
  .AppLayerbss (NOLOAD) : ALIGN(4)
    {
        _AppLayerbss_start = .;
        *AppLayer.a(.bss)
        . = ALIGN(4);
        *AppLayer.a(.bss.*)
        . = ALIGN(4);
        *AppLayer.a(COMMON)
        . = ALIGN(4);
        _AppLayerbss_end = .;
    } > RAM

    .UserNVRAMbss (NOLOAD):
    {
        _UserNVRAMbss_start = .;
        . = ALIGN(4);
        *(.UserNVRAMbss)            /* Ram memory for User Non Volatile Working Copies */
        . = ALIGN(4);
        _UserNVRAMbss_end = .;
    } > RAM 

    .bss (NOLOAD) : ALIGN(4)
    {
        _bss_start = .;
        *(.bss)
        . = ALIGN(4);
        *(.bss.*)
        . = ALIGN(4);
        *(COMMON)
        . = ALIGN(4);
        _bss_end = .;
    } > RAM

  /* serial FLASH section, code must be located here explicitly            */
  /* Example: extern int foo(void) __attribute__ ((section (".ksf_diagconst"))); */
  .krn_sf_diagc : ALIGN(4)
  {
    *(.ksf_diagconst)
    . = ALIGN(4);
    *(.ksf_diagconst.*)
	. = ALIGN(4);
  } > KRNSERFLASH


  /* serial FLASH section, code must be located here explicitly            */
  /* Example: extern int foo(void) __attribute__ ((section (".sf_text"))); */
  .ser_flash_text : ALIGN(4)
  {
	*(.sf_text)
	. = ALIGN(4);
    *(.sf_text.*)
	. = ALIGN(4);
    *(.sf_rodata)
	. = ALIGN(4);
    *(.sf_rodata.*)
	. = ALIGN(4);
  }  > SERFLASH

  /* serial FLASH section, code must be located here explicitly            */
  /* Example: extern int foo(void) __attribute__ ((section (".ksf_text"))); */
  .krn_sf_text : ALIGN(4)
  {
	*(.ksf_text)
	. = ALIGN(4);
    *(.ksf_text.*)
	. = ALIGN(4);
    *(.ksf_rodata)
	. = ALIGN(4);
    *(.ksf_rodata.*)
	. = ALIGN(4);
  } > RAM AT > KRNSERFLASH

	.data : ALIGN(4)
    {
        _sdata = .;
        *(.data)
        . = ALIGN(4);
        *(.data.*)
        . = ALIGN(4);
        *(.ramtext)
        . = ALIGN(4);
        _edata = .;
    } > RAM AT > KRNFLASH

    PROVIDE(end = .);
    _end            = .;
}

__heap_base__   = _end;
__heap_end__    = __ram_end__;

__krn_vector_table_size = __krn_vector_table_end - __krn_vector_table_start;
