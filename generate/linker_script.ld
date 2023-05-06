MEMORY {
    CSx    : ORIGIN = 0x00000000, LENGTH = 0x18000000
    SPIBSC : ORIGIN = 0x18000000, LENGTH = 0x08000000
    RAM    : ORIGIN = 0x20000000, LENGTH = 0x00500000
}
SECTIONS
{
	.fvectors 0x20020000 : AT (0x20020000)
	{
		KEEP(*(.fvectors))
	} > RAM
	.text 0x20020100 : AT (0x20020100)
	{
		*(.text)
	} > RAM
	.rodata : 
	{
		*(.rodata)
		*(.rodata.*)
		_erodata = .;
	} > RAM
	.tors : 
	{
		__CTOR_LIST__ = .;
		. = ALIGN(2);
		__ctors = .;
		*(.ctors)
		__ctors_end = .;
		__CTOR_END__ = .;
		__DTOR_LIST__ = .;
		___dtors = .;
		*(.dtors)
		___dtors_end = .;
		__DTOR_END__ = .;
		. = ALIGN(2);
		_mdata = .;
	} > RAM
	.data 0x20060100 : AT (_mdata)
	{
		_data = .;
		*(.data)
		*(.data.*)
		_edata = .;
	} > RAM
	.bss : 
	{
		PROVIDE(__bss_start__ = .);
		_bss = .;
		*(.bss)
		*(.bss.**)
		*(COMMON)
		PROVIDE(__bss_end__ = .);
		_ebss = .;
		_end = .;
		PROVIDE(end = .);
	} > RAM
	.stack 0x20061100 (NOLOAD)  : AT (0x20061100)
	{
		_stack = .;
	} > RAM
}

ENTRY(_PowerON_Reset)
