/*
Copyright (C) 2013  Sefer Ergün <rhoin@yandex.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef _IRQ_H_
#define _IRQ_H_

#include <rhKernel/common.h>
#include <rhKernel/isr.h>

#define IRQ0	0
#define IRQ1	1
#define IRQ2	2
#define IRQ3	3
#define IRQ4	4
#define IRQ5	5
#define IRQ6	6
#define IRQ7	7
#define IRQ8	8
#define IRQ9	9
#define IRQ10	10
#define IRQ11	11
#define IRQ12	12
#define IRQ13	13
#define IRQ14	14
#define IRQ015	15

//Ports
#define PIC_MASTER_PORT 0x20
#define PIC_SLAVE_PORT  0xA0

//Signals
#define PIC_EOI			0x20

RHAPI void irq0();
RHAPI void irq1();
RHAPI void irq2();
RHAPI void irq3();
RHAPI void irq4();
RHAPI void irq5();
RHAPI void irq6();
RHAPI void irq7();
RHAPI void irq8();
RHAPI void irq9();
RHAPI void irq10();
RHAPI void irq11();
RHAPI void irq12();
RHAPI void irq13();
RHAPI void irq14();
RHAPI void irq15();

void *irq_handlers[] = {
	0, 0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0 };
	
typedef void (*irq_handler)(regs_t *r);

/*
 * 
 * irq_init : Remaps IRQs and sets IRQs
 * 
 */
RHAPI void irq_init();

/*
 * 
 * irq_handle : Handles IRQs
 * 
 */
RHAPI void irq_handle(regs_t *r);

/*
 * 
 * irq_handle : Remaps IRQ.Because IRQ0 to IRQ7 mapped to IDT8-15.8 is Double Fault.So we have to remap it.
 * 
 */
RHAPI void irq_remap();

/*
 * 
 * irq_installHandler : Install handler to irq_handlers
 * @num :  Index of irq_handlers 
 * 
 */
RHAPI void irq_installHandler(int8_t num, irq_handler hand);

/*
 * 
 * irq_uninstallHandler : Uninstalls handler from irq_handlers
 * 
 */
RHAPI void irq_uninstallHandler(int8_t num);
#endif /*_IRQ_H_*/
