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

//Common functions for kernel
static uint8_t inputb(uint8_t _port)
{
	uint8_t ret;
	__asm__ __volatile__ ("inb %1, %0" : "=a"(ret) : "dN"(_port));
	return ret; 
}

static uint16_t inputw(uint16_t _port)
{
	uint16_t ret;
	__asm__ __volatile__ ("inw %1, %0" : "=a"(ret) : "dN"(_port));
	return ret; 
}

static uint32_t inputd(uint32_t _port)
{
	uint32_t ret;
	__asm__ __volatile__ ("ind %1, %0" : "=a"(ret) : "dN"(_port));
	return ret; 
}

static void outputb(uint8_t _port, uint8_t data)
{
	__asm__ __volatile__ ("outb %1, %0" : : "dN"(_port) : "a"(_data));
}

static void outputw(uint16_t _port, uint16_t _data)
{
	__asm__ __volatile__ ("outw %1, %0" : : "dN"(_port) : "a"(_data));
}

static void outputd(uint32_t _port, uint32_t _data)
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
}rhbool; 

#endif /*_COMMON_H_*/
