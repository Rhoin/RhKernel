#include <rhKernel/idt.h>

void idt_init()
{
    ip.limit = (sizeof(idt_entry_t) * 256) - 1;
    ip.base  = &idte;

    idt_flush(&ip);
}

void idt_setGate(int8_t num, uint32_t base, uint16_t selector, uint8_t type_attrib)
{
    idte[num].zero          = 0;
    idte[num].selector      = selector;
    idte[num].type_attrib   = type_attrib;
    idte[num].base_low      = base & 0xFFFF;
    idte[num].base_high     = (base >> 16) & 0xFFFF;
}


