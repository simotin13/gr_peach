/************************************************************************/
/*    File Version: V1.00                                               */
/*    Date Generated: 19/04/2019                                        */
/************************************************************************/


@==================================================================
@ Entry point for the Reset handler
@==================================================================
    .section    .fvectors, #execinstr, #alloc
    .arm

    .extern  _PowerON_Reset
    .global Start

Start:

vector_table:
    LDR pc, =_PowerON_Reset            @ +0x0000_0000 : Reset exception

Literals:
    .LTORG

    .END
