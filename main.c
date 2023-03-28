#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Alawys 0.
 */
int main(void)
{
	int len1;
	int len2;
	/*unsigned int ui;
	*void *addr;*/

	len1 = _printf("Let's try to printf a simple sentence.\n");
	len2 = printf("Let's try to printf a simple sentence.\n");
	/*ui = (unsigned int)INT_MAX + 1024;
	*addr = (void *)0x7ffe637541f0;*/
	_printf("Length:[%d, %i]\n", len1, len2);
	printf("Length:[%d, %i]\n", len1, len2);
	_printf("Negative:[%d]\n", -762534);
	printf("Negative:[%d]\n", -762534);
	_printf("Unsigned:[%u]\n", 345);
	printf("Unsigned:[%u]\n", 345);
	/*_printf("Unsigned octal:[%o]\n");
	printf("Unsigned octal:[%o]\n");*/
	_printf("Unsugned hexadecimal:[%x, %X]\n", 30, 30);
	 printf("Unsugned hexadecimal:[%x, %X]\n", 30, 30);

	len1 = _printf("String [%s]  %s  %c %% \n", "", "Nour", 'K');
	len2 = printf("String [%s]  %s  %c %% \n", "", "Nour", 'K');
	printf("%d == %d\n", len1, len2);
	_printf("Chracter:[%c], and String:[%s]\n", 'H', "Team");
	/*printf("Chracter:[%c]\n", 'H');*/
	_printf("String:[%s]\n", NULL);
	printf("String:[%s]\n", "");
	/*_printf("Address:[%p]\n", addr);
	*printf("Address:[%p]\n", addr);
	*len = _printf("Percent:[%%]\n");
	*len2 = printf("Percent:[%%]\n");
	*_printf("Len:[%d]\n", len);
	*printf("Len:[%d]\n", len);
	*_printf("Unknown:[%r]\n");
	*printf("Unknown:[%r]\n");
	*/
	return (0);
}
