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

#define PAGE_MASK 0xFFFFF000
#define PAGE_SIZE 0x1000

RHAPI uint32_t g_KernelEnd;
const uint32_t g_PageEntryDir = ((uint32_t*)g_KernelEnd & PAGE_MASK) + PAGE_SIZE;
const uint32_t g_PageTableDir = g_PageEntryDir + PAGE_SIZE;

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
RHAPI void vmm_map(uint32_t va, uint32_t pa, uint32_t flags);

/*
 *
 * vmm_unmap : Unmaps virtual address
 *
 */
RHAPI void vmm_unmap(uint32_t va);

/*
 *
 * vmm_changePageDir : Changes Page Dir
 *
 */
RHAPI void vmm_changePageDir(uint32_t pd);
#endif /*_VMM_H_*/
