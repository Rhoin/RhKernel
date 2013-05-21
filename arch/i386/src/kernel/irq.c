#include <rhKernel/irq.g>

void irq_init()
{
	irq_remap();
	
	idt_setGate(IRQ0 +  32, 	&irq0, 	IRQ_SELECTOR, IRQ_TYPE_ATTRIB);
	idt_setGate(IRQ1 +  32, 	&irq1, 	IRQ_SELECTOR, IRQ_TYPE_ATTRIB);
	idt_setGate(IRQ2 +  32, 	&irq2, 	IRQ_SELECTOR, IRQ_TYPE_ATTRIB);
	idt_setGate(IRQ3 +  32, 	&irq3, 	IRQ_SELECTOR, IRQ_TYPE_ATTRIB);
	idt_setGate(IRQ4 +  32, 	&irq4, 	IRQ_SELECTOR, IRQ_TYPE_ATTRIB);
	idt_setGate(IRQ5 +  32, 	&irq5, 	IRQ_SELECTOR, IRQ_TYPE_ATTRIB);
	idt_setGate(IRQ6 +  32, 	&irq6, 	IRQ_SELECTOR, IRQ_TYPE_ATTRIB);
	idt_setGate(IRQ7 +  32, 	&irq7, 	IRQ_SELECTOR, IRQ_TYPE_ATTRIB);
	idt_setGate(IRQ8 +  32, 	&irq8, 	IRQ_SELECTOR, IRQ_TYPE_ATTRIB);
	idt_setGate(IRQ9 +  32, 	&irq9, 	IRQ_SELECTOR, IRQ_TYPE_ATTRIB);
	idt_setGate(IRQ10 + 32, 	&irq10, IRQ_SELECTOR, IRQ_TYPE_ATTRIB);
	idt_setGate(IRQ11 + 32, 	&irq11, IRQ_SELECTOR, IRQ_TYPE_ATTRIB);
	idt_setGate(IRQ12 + 32, 	&irq12, IRQ_SELECTOR, IRQ_TYPE_ATTRIB);
	idt_setGate(IRQ13 + 32, 	&irq13, IRQ_SELECTOR, IRQ_TYPE_ATTRIB);
	idt_setGate(IRQ14 + 32, 	&irq14, IRQ_SELECTOR, IRQ_TYPE_ATTRIB);
	idt_setGate(IRQ15 + 32, 	&irq15, IRQ_SELECTOR, IRQ_TYPE_ATTRIB);
}

void irq_handle(regs_t *r)
{
	irq_handler h = irq_handlers[r->int_no - 32];
	if(h)
	{
		h(r);
	}
	
	if((r->int_no - 32) > 7)
	{
		outportb(IRQ_SLAVE_PORT, IRQ_EOI);
	}
	
	outportb(IRQ_MASTER_PORT, IRQ_EOI);
 }
 
 void irq_installHandler(int8_t num, irq_handler hand)
 {
	 irq_handlers[num] = hand;
 }
 
 void irq_uninstallHandler(int8_t num)
 {
	 irq_handlers[num] = 0;
 }
 
 void irq_remap()
 {
	outportb(0x20, 0x11);
    outportb(0xA0, 0x11);
    outportb(0x21, 0x20);
    outportb(0xA1, 0x28);
    outportb(0x21, 0x04);
    outportb(0xA1, 0x02);
    outportb(0x21, 0x01);
    outportb(0xA1, 0x01);
    outportb(0x21, 0x0);
    outportb(0xA1, 0x0);
}
	
