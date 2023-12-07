#include "main.h"
#include <stdarg.h>
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
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					count +=f_char(args);
					break;
				case 's':
					count += f_string(args);
					break;
				case 'd':
				case 'i':
					count += f_integer(args);
					break;
				case 'b':
					count += f_binary(args);
					break;
				case '%':
					count += f_write('%');
					break;
				case 'r':
					count += f_reverse(args);
					break;
				default:
					count += f_write('%');
					count += f_write(*format);
					break;
			}
		}
		else
		{
			count += f_write(*format);
		}
		format++;
	}
	va_end(args);
	return count;
}
