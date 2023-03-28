#include "main.h"
#include <stdio.h>
#include <unistd.h>

int print_char(va_list);
int print_str(va_list);
int _strlen(char *);
int _putchar(char);

/**
 * print_char - print a character
 * @args: a list of arguments
 * Return: int length
 */
int print_char(va_list args)
{
	return (_putchar(va_arg(args, int)));
}

/**
 * print_str - print a string of characters
 * @args: a list of arguments
 * Return: length int
 */
int print_str(va_list args)
{
	int len = 0;
	char *str = va_arg(args, char *);

	if (str == NULL)
		str = "(nil)";
	if (*str == '\0')
		return (-1);

	while (str[len])
	{
		_putchar(str[len]);
		len++;
	}
	return (len);
}

/**
 * _strlen - calculate the length of the string
 * @str: string of characters
 * Return: length int
 */
int _strlen(char *str)
{
	int len = 0;

	if (str == NULL)
		return (len);
	while (str[len] != '\0')
		len++;
	return (len);
}

/**
 * _putchar - print a character
 *@ch: chracter to print
 * Return: int
 */
int _putchar(char ch)
{
	return (write(1, &ch, 1));
}

