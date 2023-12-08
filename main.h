#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdint.h>

int f_write(char c);
int _printf(const char *format, ...);
int f_char(va_list args);
int f_string(va_list args);
int f_integer(va_list args);
int f_binary(va_list args);
int f_reverse(va_list args);
int f_pointer(va_list args);
int f_rot13(va_list args);
#endif
