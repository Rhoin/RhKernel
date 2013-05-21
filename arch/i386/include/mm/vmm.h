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
#ifndef _VMM_H_
#define _VMM_H_

#include <rhKernel/common.h>

#define PAGE_MASK 		0xFFFFF000
#define PAGE_FLAG_MASK 	0xFFF
#define PAGE_SIZE 		0x1000

#define PAGE_PRESENT 0x1
#define PAGE_WRITE 0x2
#define PAGE_USER 0x4

RHAPI uint32_t g_KernelEnd;
const uint32_t g_PageEntryDir = ((uint32_t*)g_KernelEnd & PAGE_MASK) + PAGE_SIZE;
const uint32_t g_PageTableDir = g_PageEntryDir + PAGE_SIZE;

#define VMM_PAGE_VAL(page,flags) (page | (flag & PAGE_FLAG_MASK))

typedef struct
{
	rhkbool present:1;
	rhkbool rw:1;
	rhkbool usermode:1;
	uint32_t intel_reserved:2;
	rhkbool access:1;
	rhkbool dirty:1;
	uint32_t reserved:2;
	uint32_t avail:3;
	uint32_t page_addr:20;
}page_t;

typedef struct
{
	page_t entries[1024];
}page_table_t;

typedef struct
{
	rhkbool present:1;
	rhkbool rw:1;
	rhkbool usermode:1;
	rhkbool wrthrg:1;
	rhkbool cache:1;
	rhkbool access:1;
	uint32_t intel_reserved:1;
	rhkbool page_size; //0 for 4kb 1 for 4mb
	uint32_t global:1;//Unused
	uint32_t avail:3;
	uint32_t page_table_addr:20;
}page_dir_t;

typedef struct
{
	page_table_t page_table_entries[1024];
	page_dir_t   page_dir_entries[1024];
}page_entries_t;

/*
 *
 * vmm_init : Initiates Virtual Memory Manager
 *
 */
RHAPI void vmm_init();

/*
 *
 * vmm_map : Maps physical address to virtual address with specified flags
 *
 */
RHAPI void vmm_map(uint32_t *pa, uint32_t *val);

/*
 *
 * vmm_unmap : Unmaps address
 *
 */
RHAPI void vmm_unmap(uint32_t va);

/*
 * 
 * vmm_isMapped : Check if address is mapped to virtual memory
 * 
 */
RHAPI rhkbool vmm_isMapped(uint32_t pa);

/*
 *
 * vmm_changePageDir : Changes Page Dir
 *
 */
RHAPI void vmm_changePageDir(uint32_t pd);
#endif /*_VMM_H_*/
