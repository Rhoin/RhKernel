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
#ifndef _IDT_H_
#define _IDT_H_

#include <rhKernel/common.h>

typedef struct idt_entry_t
{
	uint16_t base_low;
	uint16_t selector;
	uint8_t zero; //Always zero
	uint8_t type_attrib;
	uint16_t base_high;
}__attribute__((packed));

typedef struct idt_ptr_t
{
	uint16_t limit;
	uint32_t base;
}__attribute__((packed));

idt_entry_t idte[256];
idt_ptr_t 	ip;

/*
 * 
 * idt_init : Sets idt gates and flushes idt_ptr
 * 
 */
RHAPI void idt_init();

/*
 * 
 * idt_setGate : Fills idt entry
 * @num : Index of idt_entry
 * 
 */
RHAPI void idt_setGate(int8_t num, uint32_t base, uint16_t selector, uint8_t type_attrib);

/*
 * 
 * idt_flush : Flushes idt ptr.Declared in start.asm
 * 
 */
RHAPI void idt_flush(idt_ptr_t *ip);
#endif 	/*_IDT_H_*/
