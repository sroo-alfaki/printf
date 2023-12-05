#include "main.h"
/**
 *print_binary - returns the sum of a and b
 *@num: first number
 *@*printed_chars: char
 *Return: always 0
 */
void print_binary(int num, int *printed_chars)
{
	int num_bits = 0;
	int temp = num;

	if (num == 0)
	{
		num_bits = 1;
	}
	else
	{
		while (temp != 0)
		{
			temp /= 2;
			num_bits++;
		}
	}
	char buffer[num_bits + 1];
	int j = num_bits - 1;

	while (num != 0)
	{
		int bit = num % 2;

		buffer[j] = '0' + bit;
		num /= 2;
		j--;
	}
	buffer[num_bits] = '\0';

	write(1, buffer, num_bits);
	*printed_chars += num_bits;
}
