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

#ifndef _VGA_H_
#define _VGA_H_

#include <rhKernel/common.h>

//Colors
#define BLACK		0x0
#define BLUE		0x1
#define GREEN    	0x2
#define CYAN    	0x3
#define RED    		0x4
#define MAGENTA    	0x5
#define BROWN    	0x6
#define LGRAY   	0x7
#define DGRAY    	0x8
#define LBLUE    	0x9
#define LGREEN    	0xA
#define LCYAN   	0xB
#define LRED    	0xC
#define LMAGNETA    0xD
#define YELLOW    	0xE
#define WHITE    	0xF

/*
 * 
 * vga_init : Initiates vga system. 
 * 
 */
RHAPI void 		vga_init();

/*
 * 
 * vga_putch : Print char to vga console.
 * @__ch : the char will be printed.
 * 
 */
RHAPI void 		vga_putch(char ch);

/*
 * 
 * vga_scroll : Scrolls vga console.
 * 
 */
RHAPI void 		vga_scroll();

/*
 *
 * vga_setColor : Sets back and fore color
 *
 */
RHAPI void      vga_setColor(int8_t backColor, int8_t foreColor);

/*
 * 
 * vga_updateCursor : Updates vga cursor position.
 * 
 */
RHAPI void 		vga_updateCursor();

/*
 * 
 * vga_getCursorPos : Gives vga cursor current position.
 * @__x : x input which will be setted to vga console cursors x.
 * @__y : y input which will be setted to vga console cursors y.
 * 
 */
RHAPI void 		vga_getCursorPos(int32_t *x, int32_t *y);

/*
 * 
 * vga_getX : Gives vga console cursor current X position.
 * @return : It returns X position
 * 
 */
RHAPI int32_t 	vga_getX();

/*
 * 
 * vga_getY : Gives vga console cursor current Y position.
 * @return : It returns Y position
 * 
 */
RHAPI int32_t 	vga_getY();

/*
 * 
 * vga_setCursorPos : Sets vga console cursor current position.
 * @__x : x input which will set to vga console cursors x.
 * @__y : y input which will set to vga console cursors y.
 * 
 */
RHAPI void 		vga_setCursorPos(int32_t x, int32_t y);
#endif /*_VGA_H_*/
