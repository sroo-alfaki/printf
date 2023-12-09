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
			if (*format == 'c')
				count += f_char(args);
			else if (*format == 's')
				count += f_string(args);
			else if (*format == 'd' || *format == 'i')
				count += f_integer(args);
			else if (*format == 'b')
				count += f_binary(args);
			else if (*format == 'p')
				count += f_pointer(args);
			else if (*format == 'R')
				count += f_rot13(args);
			else if (*format == 'S')
				count += f_sstring(args);
			else if (*format == 'u')
				count += f_unsig(args);
			else if (*format == 'o')
				count += f_octal(args);
			else if (*format == 'x')
				count += f_hex_lower(args);
			else if (*format == 'X')
				count += f_hex_upper(args);
			else
				count += f_write(*format);
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
