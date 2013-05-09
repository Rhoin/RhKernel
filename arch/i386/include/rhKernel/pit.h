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
#ifndef _PIT_H_
#define _PIT_H_

#include <rhKernel/irq.h>

#define PIT_CHANNEL0 			0x40
#define PIT_CMD		 		0x43

// BCD
#define PIT_BINARY                      0x00    // Use Binary counter values
#define PIT_BCD                         0x01    // Use Binary Coded Decimal counter values

// Mode
#define PIT_MODE0                       0x00    // Interrupt on Terminal Count
#define PIT_MODE1                       0x02    // Hardware Retriggerable One-Shot
#define PIT_MODE2                       0x04    // Rate Generator
#define PIT_MODE3                       0x06    // Square Wave
#define PIT_MODE4                       0x08    // Software Trigerred Strobe
#define PIT_MODE5                       0x0a    // Hardware Trigerred Strobe

// Read/Write
#define PIT_LATCH                       0x00
#define PIT_RW_LOW                      0x10    // Least Significant Byte
#define PIT_RW_HI                       0x20    // Most Significant Byte
#define PIT_RW_BOTH                     0x30    // Least followed by Most Significant Byte

// Counter Select
#define PIT_COUNTER0                    0x00
#define PIT_COUNTER1                    0x40
#define PIT_COUNTER2                    0x80
#define PIT_READBACK                    0xc0

/*
 *
 * pit_init : Initiates PIT
 *
 */
RHAPI void pit_init();

/*
 *
 * pit_sleep : Sleeps amount ms
 *
 */
RHAPI void pit_sleep(uint32_t ms);
#endif /*_PIT_H_*/
