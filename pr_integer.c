#include "main.h"

/**
 * print_integer - returns the sum of a and b
 *@num: number
 *@*printed_chars: print char or string
 *Return: always 0
 */
void print_integer(int num, int *printed_chars)
{
	int num_digits = 0;
	int temp = num;

	if (num == 0)
	{
		num_digits = 1;
	}
	else
	{
		while (temp != 0)
		{
			temp /= 10;
			num_digits++;
		}
	}
	char buffer[num_digits + 1];
	int j = num_digits - 1;

	while (num != 0)
	{
		int digit = num % 10;

		buffer[j] = '0' + digit;
		num /= 10;
		j--;
	}
	buffer[num_digits] = '\0';
	write(1, buffer, num_digits);
	*printed_chars += num_digits;
}
