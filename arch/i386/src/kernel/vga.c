#include <rhKernel/vga.h>

#define VGA_COLOR_MEM_ADDR 			0xB8000
#define VGA_COLUMN_MAX 				80
#define VGA_ROW_MAX					25
#define VGA_ROW_INDEX(pos) 			((pos) * VGA_COLUMN_MAX)
#define VGA_COL_INDEX(posx,posy)	(((posy) * VGA_COLUMN_MAX) + posx)
#define VGA_BLANK()                 (' ' | (g_VgaAttrib << 8))
uint16_t *g_VgaVideoMemAddr;
int32_t csr_x, csr_y;
uint16_t g_VgaAttrib;

void vga_init()
{
	g_VgaVideoMemAddr = (uint16_t*)VGA_COLOR_MEM_ADDR;
    vga_clearScreen();
}

void vga_scroll()
{
	if(csr_y >= VGA_ROW_MAX)
	{
		int8_t tmp = (csr_y - VGA_ROW_MAX) + 1;
		
		//We move every line up one.
        memcpy(g_VgaVideoMemAddr, g_VgaVideoMemAddr + VGA_ROW_INDEX(tmp),
               (VGA_ROW_MAX - tmp + 1) * VGA_COLUMN_MAX * 2);
		
		uint16_t blank = ' ' | (g_VgaAttrib << 8);
		
		//Now clear last line
        memsetw(g_VgaVideoMemAddr + VGA_ROW_INDEX(VGA_ROW_MAX - tmp),
                VGA_BLANK(), VGA_COLUMN_MAX);
		csr_y = VGA_ROW_MAX - 1;
	}
}

void vga_updateCursor()
{
    uint16_t pos = VGA_COL_INDEX(csr_x, csr_y);

	//Hardware cursor low bits
	outportb(0x3D4, 0x0E);
	outportb(0x3D5, ((pos >> 8) & 0xFF));

	//Hardware curosr high bits
    outportb(0x3D4, 0x0F);
	outportb(0x3D5, (pos & 0xFF));
}

void vga_setColor(int8_t backColor, int8_t foreColor)
{
    g_VgaAttrib = (backColor << 4) & (foreColor & 0x0F);
}

void vga_clearScreen()
{
    //Fill screen with blank
    memsetw(g_VgaVideoMemAddr, VGA_BLANK(), VGA_COLUMN_MAX * VGA_ROW_MAX);
    csr_x = csr_y = 0;
    vga_updateCursor();
    uint16_t tmp = g_VgaAttrib;
    //Print header
    vga_setColor(DGRAY, WHITE);
    printf(RHKERNEL_VERSION_EXT_STRING);
    memsetw(g_VgaVideoMemAddr + VGA_COL_INDEX(csr_x, csr_y),
            VGA_BLANK(), VGA_COLUMN_MAX - strlen(RHKERNEL_VERSION_EXT_STRING) + 1);
    csr_x = 0;
    csr_y = 1;
    //Point to start of console
    g_VgaVideoMemAddr = g_VgaVideoMemAddr + VGA_COL_INDEX(csr_x, csr_y);
    vga_updateCursor();
    g_VgaAttrib = tmp;
}

int32_t getX()
{
    return csr_x;
}

int32_t getY()
{
    return csr_y - 1;
}

void getCursorPos(int32_t *x, int32_t *y)
{
    *x = csr_x;
    *y = csr_y - 1;
}

void setCursorPos(int32_t x, int32_t y)
{
    if(x > VGA_COLUMN_MAX)
    {
        csr_x = VGA_COLUMN_MAX;
    }
    else if(x < 0)
    {
        csr_x = 0;
    }
    else
    {
        csr_x = x;
    }

    if(csr_y > VGA_ROW_MAX)
    {
        csr_y = VGA_ROW_MAX;
    }
    else if(csr_y <= 0)
    {
        csr_y = 1;
    }
    else
    {
        csr_y = y;
    }

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
    else if(ch == '\r')
    {
        csr_x = 0;
    }
    else if(ch == '\n')
    {
        csr_x = 0;
        csr_y++;
    }
    else if(ch >= ' ')
    {
        uint16_t *where = g_VgaVideoMemAddr + VGA_COL_INDEX(csr_x, csr_y);
        *where = ch | g_VgaAttrib << 8;
        csr_x++;
    }

    if(csr_x >= 80)
    {
        csr_x = 0;
        csr_y++;
    }

    vga_scroll();
    vga_updateCursor();
}



