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

#ifndef _PMM_H_
#define _PMM_H_

#include <mem/vmm.h>
#include <multiboot.h>
/*
 *
 * pmm_init : Initiates Physical Memory Manager.Sets up linked list of physical pages.
 *
 */
RHAPI void pmm_init(multiboot_info_t *mbi);

/*
 *
 * pmm_alloc : Returns adress of free page(4 KiB).If out of memory panic occurs.
 *
 */
RHAPI void *pmm_alloc();

/*
 *
 * pmm_free : Frees pointer and adds It to linked list.
 *
 */
RHAPI void pmm_free(void *p);

#endif /*_PMM_H_*/
