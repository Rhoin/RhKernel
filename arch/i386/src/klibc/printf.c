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
#include <rhKernel/common.h>
#include <klibc/printf.h>
#include <klibc/stdarg.h>

void puts(const char *_str)
{
	int32_t i = 0;
	while(_str[i])
	{
		putch(_str[i++]);
	}
}

int printf(const char *_fmt, ...)
{
	if(_fmt == NULL)
	{
		return -1;
	}
	
	char *buff;
	memset(buff, 0, strlen(_fmt) + 1);
	
	va_list val;
	va_start(val,_fmt);
	if(vsprintf(buff,_fmt,val) < 0)
	{
		return -1;
	}
	va_end(val);
	puts(buff);
	
	return 1;
}
