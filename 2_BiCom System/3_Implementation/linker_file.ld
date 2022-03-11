ENTRY(Reset_Handler)
 
MEMORY
{
    FLASH(rx):ORIGIN =0x08000000,LENGTH =1024k
    SRAM(rwx):ORIGIN =0x20000000,LENGTH =128k
}
SECTIONS
{
    .text :
    {   /* Here starting it's not necessary to mention because .isr_vector is the start itself */
        *(.isr_vector)
        *(.text)
        *(.rodata)
        _etext = .; /*This is used to tell its end of text (locator.;) */
    }> FLASH /*Both source and Drain are FLASH*/
    _la_data = LOADADDR(.data); /* load data */

    .data :
    {   _sdata = .; /* start of data */
        *(.data)
        _edata = .; /* end of data */
    }> SRAM AT> FLASH /*">(vma) AT> (lma)"vma is like where to load (drain) lma is like from where to load (source)*/

    .bss :
    {
        _sbss = .; /* start of bss */
        *(.bss)
        _ebss = .; /* end of bss */
    }> SRAM /*Both source and Drain are FLASH*/
}