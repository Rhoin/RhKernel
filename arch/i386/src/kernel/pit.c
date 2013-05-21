#include <rhKernel/pit.h>

uint32_t ticks, count;

void pit_init()
{
	int32_t div = 1193180 / 10;
	outportb(PIT_CMD, PIT_BINARY|PIT_MODE3|PIT_RW_BOTH|PIT_COUNTER0);
	outportb(PIT_CHANNEL0, div & 0xFF);
	outportb(PIT_CHANNEL0, div >> 8);
	irq_installHandler(IRQ0, &pit_handler);
}

void pit_sleep(uint32_t ms)
{
	uint32_t tmp = ticks + ms;
	
	while(ticks < tmp) ; 
}

void pit_handler(regs_t *r)
{
	count++;
	
	if(ticks % 18 == 0)
	{
		ticks++
	}
}
