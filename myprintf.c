#include <unistd.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	int count = 0;
	const char *p = format;

	while (*p != '\0') {
		if (*p == '%') {
			p++; 
			if (*p == 'c') {
				int ch = va_arg(args, int);
				count += write(1, &ch, sizeof(ch));
			} else if (*p == 's') {
				char *str = va_arg(args, char *);
				int len = 0;
				while (str[len] != '\0')
					len++;
				count += write(1, str, len);
			} else if (*p == '%') {
				char percent = '%';
				count += write(1, &percent, sizeof(percent));
			}
		} else {
			count += write(1, p, 1);
		}
		p++;
	}

	va_end(args);

	return count;
}
