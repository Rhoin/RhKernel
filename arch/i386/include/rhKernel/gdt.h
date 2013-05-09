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

#ifndef _GDT_H_
#define _GDT_H_

#include <rhKernel/common.h>

typedef struct gdt_entry_t
{
	uint16_t limit_low;
	uint16_t base_low;
	uint16_t base_middle;
	uint16_t flags;
	uint8_t base_high;
}__attribute__((packed));

typedef struct gdt_ptr_t
{
	uint16_t limit;
	uint32_t base;
}__attribute__((packed));

gdt_entry_t gdte[3];
gdt_ptr_t   gp;

/*
 * 
 * gdt_init : Sets gdt gates and flushes gdt pointer
 * 
 */
RHAPI void 	gdt_init();

/*
 * 
 * gdt_setGate : Fills gdt entry
 * @num : Index of gdt_entry
 * 
 */
RHAPI void 	gdt_setGate(int32_t num, uint64_t base, uint64_t limit, 
						uint8_t acces, uint8_t gran);
						
/*
 * 
 * gdt_flush : Flushes gp.Declared in start.asm
 * 
 */						
RHAPI void  gdt_flush(gdT_ptr_t *gp);

#endif /*_GDT_H_*/
