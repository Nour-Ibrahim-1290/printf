#include "main.h"

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
 * print_dec - prints out a decimal
 * @args: va_list of variables
 * Return: size of output
 */
int print_dec(va_list args)
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
