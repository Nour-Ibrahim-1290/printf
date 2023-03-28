#include "main.h"

int print_int(va_list);
void to_binary(unsigned int, int*);
int print_b(va_list);

/**
 *print_int - function that print an integer
 *@args: va_list of variables
 *Return: length of int in chars
 */

int print_int(va_list args)
{
	int len, po, j, digit, n, count = 0, num;

	n = va_arg(args, int);

	if (n != 0)
	{
		if (n < 0)
		{
			_putchar('-');
			count++;
		}
		num = n;
		len = 0;
		while (num != 0)
		{
			num /= 10;
			len++;
		}
		po = 1;
		for (j = 1; j <= len - 1; j++)
			po *= 10;
		for (j = 1; j <= len; j++)
		{
			digit = n / po;
			if (n < 0)
				_putchar((digit * -1) + 48);
			else
				_putchar(digit + '0');
			count++;
			n -= digit * po;
			po /= 10;
		}
	}
	else
	{
		_putchar('0');
		return (1);
	}
	return (count);
}

/**
 * to_binary - convert unsigned int into binary and print it
 * @n: unsigned int to convert into binary
 * @len: pointer to counter for printing length
 * Return: void.
 */
void to_binary(unsigned int n, int *len)
{
	if (n > 1)
	{
		*len += 1;
		to_binary(n >> 1, len);
	}
	_putchar((n & 1) + '0');
}

/**
 * print_b - print unsigned int in binary format
 * @args: va_list to get arg from
 * Return: length of printed binary
 */
int print_b(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int len;
	int *p_len;

	p_len = &len;
	to_binary(n, p_len);
	return (len);
}
