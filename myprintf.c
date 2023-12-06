#include "main.h"
/**
 * _printf - print result
 *@*format: list of type
 * Return: int
 */
int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);
	int printed_chars = 0;
	int i = 0;

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'i' || format[i] == 'd')
				print_integer(va_arg(args, int), &printed_chars);
			else if (format[i] == 'b')
				print_binary(va_arg(args, int), &printed_chars);
			else if (format[i] == 'c')
			{
				char ch = (char)va_arg(args, int);

				write(1, &ch, 1);
				printed_chars++;
			}
			else if (format[i] == 's' || format[i] == 'S')
			{
				char *str = va_arg(args, char *);
				int len = 0;

				while (str[len] != '\0')
					len++;
				write(1, str, len);
				printed_chars += len;
			}
		}
		else
		{
			write(1, &format[i], 1);
			printed_chars++;
		}
		i++;
	}
	va_end(args);
	return (printed_chars);
}
