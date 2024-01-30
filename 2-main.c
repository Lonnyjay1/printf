#include <limits.h>
#include <stdio.h>
#include "main.h"
#include <string.h>
#include <limits.h>

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int c, len;
	unsigned int ui;
	ui = (unsigned int)INT_MAX + 1024;
		        
	c = print_all("Let's try to printf a simple sentence.\n");
	printf("Let's try to printf a simple sentence.\n");
	len = strlen("Let's try to printf a simple sentence.\n");
	printf("%d\n", c);
	printf("%d\n", len);
	c = print_all("String:[%s]\n", "I am a string !")
	printf("String:[%s]\n", "I am a string !");
	len = strlen("String:[I am a string !]\n");
	printf("%d\n", c);
	printf("%d\n", len);
	c = print_all("Character:[%c]\n", 'H');
	printf("Character:[%c]\n", 'H');
	len = strlen("Character:[H]\n");
	printf("%d\n", c);
	printf("%d\n", len);
	c = print_all("Length:[%d, %i]\n", -30, 234);
	printf("Length:[%d, %i]\n", -30, 234);
	len = strlen("Length:[-30, 234]\n");
	printf("%d\n", c);
	printf("%d\n", len);
	c = print_all("Negative:[%d]\n", -762534);
	printf("Negative:[%d]\n", -762534);
	len = strlen("Negative:[-762534]\n");
	printf("%d\n", c);
	printf("%d\n", len);
	c = print_all("Percent:[%%]\n");
	len = printf("Percent:[%%]\n");
	printf("%d\n", c);
	printf("%d\n", len);
	c = print_all("%b\n", 98);
	len = printf("1100010\n");
	printf("%d\n", c);
	printf("%d\n", len);
	c = print_all("Unsigned:[%u]\n", ui);
	len = printf("Unsigned:[%u]\n", ui);
	printf("%d\n", c);
	printf("%d\n", len);
	c = print_all("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	len = printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
	printf("%d\n", c);
	printf("%d\n", len);
	c = print_all("Unsigned octal:[%o]\n", ui);
	len = printf("Unsigned octal:[%o]\n", ui);
	printf("%d\n", c);
	printf("%d\n", len);
	return (0);
}
