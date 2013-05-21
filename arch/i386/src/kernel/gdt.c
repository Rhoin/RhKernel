#include <rhKernel/common.h>

void gdt_init()
{
    gp.limit = (sizeof(gdt_entry_t) * 3) - 1;
    gp.base = &gdte;

    gdt_setGate(0, 0, 0, 0, 0); //Null
    gdt_setGate(1, 0, 0xFFFFFFFF, 0x9A, 0xCF); //Code segment
    gdt_setGate(2, 0, 0xFFFFFFFF, 0x92, 0xCF); //Data Segment

    gdt_flush(&gp);
}

void gdt_setGate(int32_t num, uint64_t base, uint64_t limit,
uint8_t acces, uint8_t gran)
{
    gdte[num].limit_low         = limit & 0xFFFF;
    gdte[num].base_low          = base & 0xFFFF;
    gdte[num].base_middle       = base >> 16 & 0xFFFF;
    gdte[num].base_high         = base >> 24 & 0xFFFF;
    gdte[num].flags             = ((acces << 8) & 0xFF00) | ((gran & 0x0F) | ((limit >> 16) & 0xF0) );
}


