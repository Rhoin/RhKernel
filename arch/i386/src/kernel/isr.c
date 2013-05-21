#include <rhKernel/isr.h>


void isr_init()
{
    idt_setGate(ISR0,   &isr0,      ISR_SELECTOR,   ISR_TYPE_ATTRIB);
    idt_setGate(ISR1,   &isr1,      ISR_SELECTOR,   ISR_TYPE_ATTRIB);
    idt_setGate(ISR2,   &isr2,      ISR_SELECTOR,   ISR_TYPE_ATTRIB);
    idt_setGate(ISR3,   &isr3,      ISR_SELECTOR,   ISR_TYPE_ATTRIB);
    idt_setGate(ISR4,   &isr4,      ISR_SELECTOR,   ISR_TYPE_ATTRIB);
    idt_setGate(ISR5,   &isr5,      ISR_SELECTOR,   ISR_TYPE_ATTRIB);
    idt_setGate(ISR6,   &isr6,      ISR_SELECTOR,   ISR_TYPE_ATTRIB);
    idt_setGate(ISR7,   &isr7,      ISR_SELECTOR,   ISR_TYPE_ATTRIB);
    idt_setGate(ISR8,   &isr8,      ISR_SELECTOR,   ISR_TYPE_ATTRIB);
    idt_setGate(ISR9,   &isr9,      ISR_SELECTOR,   ISR_TYPE_ATTRIB);
    idt_setGate(ISR10,  &isr10,     ISR_SELECTOR,   ISR_TYPE_ATTRIB);
    idt_setGate(ISR11,  &isr11,     ISR_SELECTOR,   ISR_TYPE_ATTRIB);
    idt_setGate(ISR12,  &isr12,     ISR_SELECTOR,   ISR_TYPE_ATTRIB);
    idt_setGate(ISR13,  &isr13,     ISR_SELECTOR,   ISR_TYPE_ATTRIB);
    idt_setGate(ISR14,  &isr14,     ISR_SELECTOR,   ISR_TYPE_ATTRIB);
    idt_setGate(ISR15,  &isr15,     ISR_SELECTOR,   ISR_TYPE_ATTRIB);
    idt_setGate(ISR16,  &isr16,     ISR_SELECTOR,   ISR_TYPE_ATTRIB);
    idt_setGate(ISR17,  &isr17,     ISR_SELECTOR,   ISR_TYPE_ATTRIB);
    idt_setGate(ISR18,  &isr18,     ISR_SELECTOR,   ISR_TYPE_ATTRIB);
    idt_setGate(ISR19,  &isr19,     ISR_SELECTOR,   ISR_TYPE_ATTRIB);
    idt_setGate(ISR20,  &isr20,     ISR_SELECTOR,   ISR_TYPE_ATTRIB);
    idt_setGate(ISR21,  &isr21,     ISR_SELECTOR,   ISR_TYPE_ATTRIB);
    idt_setGate(ISR22,  &isr22,     ISR_SELECTOR,   ISR_TYPE_ATTRIB);
    idt_setGate(ISR23,  &isr23,     ISR_SELECTOR,   ISR_TYPE_ATTRIB);
    idt_setGate(ISR24,  &isr24,     ISR_SELECTOR,   ISR_TYPE_ATTRIB);
    idt_setGate(ISR25,  &isr25,     ISR_SELECTOR,   ISR_TYPE_ATTRIB);
    idt_setGate(ISR26,  &isr26,     ISR_SELECTOR,   ISR_TYPE_ATTRIB);
    idt_setGate(ISR27,  &isr27,     ISR_SELECTOR,   ISR_TYPE_ATTRIB);
    idt_setGate(ISR28,  &isr28,     ISR_SELECTOR,   ISR_TYPE_ATTRIB);
    idt_setGate(ISR29,  &isr29,     ISR_SELECTOR,   ISR_TYPE_ATTRIB);
    idt_setGate(ISR30,  &isr30,     ISR_SELECTOR,   ISR_TYPE_ATTRIB);
    idt_setGate(ISR31,  &isr31,     ISR_SELECTOR,   ISR_TYPE_ATTRIB);

}

void isr_handle(regs_t *r)
{
    if(r->int_no < 32)
    {
		isr_handler *h = isr_handlers[r->int_no];
		
		if(h)
		{
			h(r);
		}
		else
		{
			panic("Unhandle exception: %s", isr_messages[r->int_no]);
		}
    }
}

void isr_installHandler(int8_t num, isr_handler *hand)
{
	isr_handlers[num] = hand;
}

void isr_uninstallHandler(int8_t num)
{
	isr_handlers[num] = 0;
}
