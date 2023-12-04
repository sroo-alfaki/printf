#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	int count = 0;
	const char *p = format;

	while (*p != '\0') {
		if (*p == '%') {
			p++;  // انتقل إلى المحول التالي
			if (*p == 's') {
				char *str = va_arg(args, char *);
				int len = 0;
				while (str[len] != '\0')
					len++;

				char *temp = (char *)malloc((len + 1) * sizeof(char));
				if (temp == NULL) {
					// إدارة حالة فشل الحجز
					return -1;
				}

				for (int i = 0; i < len; i++) {
					temp[i] = str[i];
				}
				temp[len] = '\0';

				count += write(1, temp, len);

				free(temp);
			}
		} else {
			count += write(1, p, 1);
		}
		p++;
	}

	va_end(args);

	return count;
}
