#include <rhKernel/vga.h>

#define VGA_COLOR_MEM_ADDR 	0xB8000
#define VGA_COLUMN_MAX 		80
#define VGA_ROW_MAX			25
uint16_t *g_VgaVideoMemAddr;
int32_t csr_x, csr_y;
uint8_t attrib = 0x0F;

void vga_init()
{
	g_VgaVideoMemAddr = (uint16_t*)VGA_COLOR_MEM_ADDR;
	x = y = 0;
	updateCursor();
}

void vga_scroll()
{
	if(csr_y >= 25)
	{
		int32_t i;
		for(i = 0; i < 25*80; i++)
		{
			g_VgaVideoMemAddr[i] = g_VgaVideoMemAddr[i + 80];
		}
		
		uint16_t blank = ' ' | (attrib << 8);
		memsetw(g_VgaVideoMemAddr + (25 - ( csr_y - 26)), blank, 80);
		csr_y = 24;
		
	}
}

void vga_updateCursor()
{
	uint32_t tmp = csr_y * VGA_ROW_MAX + crs_x;
	
	outportb(0x3D4, 14);
    outportb(0x3D5, tmp >> 8);
    outportb(0x3D4, 15);
    outportb(0x3D5, tmp);
}

void vga_setCursorPos(int32_t x, int32_t y)
{
	if(x < 0)
	{
		csr_x = 0;
	}
	else if(x > VGA_COLUMN_MAX)
	{
		csr_x = VGA_COLUMN_MAX;
	}
	else
	{
		csr_x = x;
	}
	
	if(y < 0)
	{
		csr_y = 0;
	}
	else if(y > VGA_ROW_MAX)
	{
		csr_y = VGA_ROW_MAX;
	}
	else
	{
		csr_y = y;
	}
	
	vga_scroll();
	vga_updateCursor();
	
}

void vga_getCursorPosition(int32_t *x, int32_t *y)
{
	*x = csr_x;
	*y = csr_y;
}

void vga_getX()
{
	return csr_x;
}

void vga_getY()
{
	return csr_y;
}
		
void vga_putch(char ch)
{
	if(ch == 0x08)
	{
		if(csr_x != 0)
		{
			csr_x--;
		}
	}
	else if(ch == 0x09)
	{
		 csr_x = (csr_x + 8) & ~(8 - 1);
	}
	else if(ch == '\n')
	{
		csr_x = ;
		csr_y++;
	}
	else if(ch == '\r')
	{
		csr_x = 0;
	}
	else if(ch >= ' ')
	{
		uint16_t *ptr = g_VgaVideoMemAddr + ( csr_y * 80 + csr_x);
		*ptr = ch | attrib;
		csr_x++
	}
	
	if(csr_y >= 80)
	{
		csr_x = 0;
		csr_y++;
	}
	
	vga_scroll();
	vga_updateCursor();
}

int32_t vga_getX()
{
	return csr_x;
}

int32_t vga_getY()
{
	return csr_y;
}

