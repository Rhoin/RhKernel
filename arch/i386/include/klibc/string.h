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

#ifndef _STRING_H_
#define _STRING_H_

#include "kernel/common.h"

//Basic libc functions
RHAPI void *memset(void *_src, int _val, size_t _count);
RHAPI void *memcpy(void *_dst, const void *_src, size_t _count);
RHAPI void *memchr(const void *_src, char chr, size_t _count);
RHAPI void *memmove(void *_dst, const void *_src, size_t _count);
RHAPI char *strtok(char **_str, const char *_delim);
RHAPI size_t strlen(const char *_str);
RHAPI char *strcpy(char *_dst, const char *_src);
RHAPI char *strncpy(char *_dst, const char *_src, size_t _count);
RHAPI char *strcat(char *_dst, const char *_src);
RHAPI char *strncat(char *_dst, const char *_src, size_t _count);
RHAPI int strcmp(const char *_str1, const char *_str2);
RHAPI int strncmp(const char *_str1, const char *_str2, size_t _count);
RHAPI char *strchr(const char *_str, char _chr);
RHAPI size_t strspn(const char *_str, const char *_accept);
RHAPI size_t strcspn(const char *_str, const char *_reject);
RHAPI char *strpbrk(const char *_str, const char *_accept);
RHAPI char *strstr(const char *_str1, const char *_str2);

#endif /*_STRING_H_*/

