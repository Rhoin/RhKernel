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
#ifndef _COMMON_H_
#define _COMMON_H_

#include <stdint.h>
#include <stdarg.h>

#define RHAPI extern

#define RHKERNEL_MAJOR_VER              0
#define RHKERNEL_MINOR_VER              0
#define RHKERNEL_REVISION_VER           1
#define RHKERNEL_VERSION_STRING         "0.0.1"
#define RHKERNEL_VERSION_EXT_STRING     "RhKernel v0.0.1"
//Common functions for kernel
static uint8_t inportb(uint8_t _port)
{
	uint8_t ret;
	__asm__ __volatile__ ("inb %1, %0" : "=a"(ret) : "dN"(_port));
	return ret; 
}

static uint16_t inportw(uint16_t _port)
{
	uint16_t ret;
	__asm__ __volatile__ ("inw %1, %0" : "=a"(ret) : "dN"(_port));
	return ret; 
}

static uint32_t inportd(uint32_t _port)
{
	uint32_t ret;
	__asm__ __volatile__ ("ind %1, %0" : "=a"(ret) : "dN"(_port));
	return ret; 
}

static void outportb(uint8_t _port, uint8_t data)
{
	__asm__ __volatile__ ("outb %1, %0" : : "dN"(_port) : "a"(_data));
}

static void outportw(uint16_t _port, uint16_t _data)
{
	__asm__ __volatile__ ("outw %1, %0" : : "dN"(_port) : "a"(_data));
}

static void outportd(uint32_t _port, uint32_t _data)
{
	__asm__ __volatile__ ("outd %1, %0" : : "dN"(_port) : "a"(_data));
}

static void halt()
{
	asm("cli");
	asm("hlt");
}

//Basic boolean
typedef enum
{
	FALSE 	= 0x0,
	TRUE	= 0x1
}rhkbool; 

#endif /*_COMMON_H_*/
