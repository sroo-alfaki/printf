#include "main.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
/**
 * _printf - function my printf
 * @format: list of type
 * Return: number of chars that print
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%' && *(++format))
		{
			count += (*(format) == 'c') ? f_char(args) :
				(*(format) == 's') ? f_string(args) :
				(*(format) == 'd' || *(format) == 'i') ? f_integer(args) :
				(*(format) == 'b') ? f_binary(args) :
				(*(format) == 'p') ? f_pointer(args) :
				(*(format) == 'u') ? f_unsig(args) :
				(*(format) == 'S') ? f_sstring(args) :
				(*(format) == 'x') ? f_hex_lower(args) :
				(*(format) == 'X') ? f_hex_upper(args) :
				(*(format) == 'o') ? f_octal(args) :
				(*(format) == 'R') ? f_rot13(args) :
				f_write(*format);
		}
		else
		{
			count += f_write(*format);
		}
		format++;
	}
	va_end(args);
	return (count);
}
