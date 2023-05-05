    .section    .fvectors, #execinstr, #alloc
    .arm
    .extern  _PowerON_Reset

vector_table:
    LDR pc, =_PowerON_Reset            @ +0x0000_0000 : Reset exception
