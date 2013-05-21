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
#ifndef _ISR_H_
#define _ISR_H_

#include <rhKernel/common.h>

#define ISR0 			0
#define ISR1 			1
#define ISR2 			2
#define ISR3 			3
#define ISR4 			4
#define ISR5 			5
#define ISR6 			6
#define ISR7 			7
#define ISR8 			8
#define ISR9 			9
#define ISR10 			10
#define ISR11 			11
#define ISR12 			12
#define ISR13 			13
#define ISR14 			14
#define ISR15 			15
#define ISR16 			16
#define ISR17 			17
#define ISR18 			18
#define ISR19 			19
#define ISR20 			20
#define ISR21 			21
#define ISR22 			22
#define ISR23 			23
#define ISR24 			24
#define ISR25 			25
#define ISR26 			26
#define ISR27 			27
#define ISR28 			28
#define ISR29 			29
#define ISR30 			30
#define ISR31 			31

#define ISR_SELECTOR 	0x08
#define ISR_TYPE_ATTRIB 0x8E

//Theese are defined in start.asm
RHAPI void isr0();
RHAPI void isr1();
RHAPI void isr2();
RHAPI void isr3();
RHAPI void isr4();
RHAPI void isr5();
RHAPI void isr6();
RHAPI void isr7();
RHAPI void isr8();
RHAPI void isr9();
RHAPI void isr10();
RHAPI void isr11();
RHAPI void isr12();
RHAPI void isr13();
RHAPI void isr14();
RHAPI void isr15();
RHAPI void isr16();
RHAPI void isr17();
RHAPI void isr18();
RHAPI void isr19();
RHAPI void isr20();
RHAPI void isr21();
RHAPI void isr22();
RHAPI void isr23();
RHAPI void isr24();
RHAPI void isr25();
RHAPI void isr26();
RHAPI void isr27();
RHAPI void isr28();
RHAPI void isr29();
RHAPI void isr30();
RHAPI void isr31();

typedef struct
{
	uint32_t gs, fs, es, ds;
	uint32_t edi, esi, ebp, esp, ebx, edx, ecx, eax;
	uint32_t int_no, err_code;
	uint32_t eip, cs, eflags, useresp, ss;
}regs_t;


const char *isr_messages[] =
{
	"Division by Zero",
	"Debug",
	"Non-Maskable Interrupt",
	"Breakpoint",
	"Into Detected Overflow",
	"Out of Bounds",
	"Invalid Opcode",
	"No Coprocessor",
	"Double Fault",
	"Coprocessor Segment Overrun",
	"Bad TSS",
	"Segment Not Present",
	"Stack Fault",
	"General Protection Fault",
	"Page Fault",
	"Unknown Interrupt",
	"Coprocessor Fault",
	"Alignment Check",
	"Machine Check",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
	"Reserved",
};
	
void *isr_handlers[32] = { NULL };
typedef void (*isr_handler)(regs_t *r);

/*
 * 
 * isr_init : Sets ISRs.Called in idt_init
 * 
 */
RHAPI void isr_init();

/*
 * 
 * isr_handle : Handles ISRs
 * 
 */
RHAPI void isr_handle(regs_t *r);

/*
 * 
 * isr_installHandler : Installs ISR handler
 * 
 */
RHAPI void isr_installHandler(int8_t num, isr_handler hand);

/*
 * 
 * isr_uninstallHandler : Uninstall ISR Handler
 * 
 */
RHAPI void isr_uninstallHandler(int8_t num);

#endif /*_ISR_H_*/
