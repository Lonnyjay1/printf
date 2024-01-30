#include "main.h"
#include <unistd.h>

/**
 * str_addunsignedint - returns the length of a string.
 * @n: First operand.
 * @p: Second operand.
 * @k: Third operand.
 *
 * Return: length of a string.
 */
int str_addunsignedint(unsigned int n, char *p, int k)
{
	unsigned int d;
	int count, i = 0;

	d = n;
	count = 1;

	while (d > 9)
	{
		d /= 10;
		count *= 10;
	}

	for (; count >= 1; count /= 10, i++)
		p[k + i] = (((n / count) % 10) + '0');
	return (i);
}

/**
 * str_addhexa_x - returns the length of a string.
 * @n: First operand.
 * @p: Second operand.
 * @k: Third operand.
 *
 * Return: length of a string.
 */
int str_addhexa_x(unsigned int n, char *p, int k)
{
	char m;
	unsigned int d;
	int count, i = 0;

	d = n;
	count = 1;

	while (d > 15)
	{
		d /= 16;
		count *= 16;
	}

	for (; count >= 1; count /= 16, i++)
	{
		m = (n / count) % 16;
		if (m >= 10 && m <= 15)
			m = 'a' + (m - 10);
		else
			m += '0';
		p[k + i] = m;
	}
	return (i);
}

/**
 * str_addhexa_X - returns the length of a string.
 * @n: First operand.
 * @p: Second operand.
 * @k: Third operand.
 *
 * Return: length of a string.
 */
int str_addhexa_X(unsigned int n, char *p, int k)
{
	char m;
	unsigned int d;
	int count, i = 0;

	d = n;
	count = 1;

	while (d > 15)
	{
		d /= 16;
		count *= 16;
	}

	for (; count >= 1; count /= 16, i++)
	{
		m = (n / count) % 16;
		if (m >= 10 && m <= 15)
			m = 'A' + (m - 10);
		else
			m += '0';
		p[k + i] = m;
	}
	return (i);
}

/**
 * str_octa - returns the length of a string.
 * @n: First operand.
 * @p: Second operand.
 * @k: Third operand.
 *
 * Return: length of a string.
 */
int str_octa(unsigned int n, char *p, int k)
{
	char m;
	unsigned int d;
	int count, i = 0;

	d = n;
	count = 1;

	while (d > 7)
	{
		d /= 8;
		count *= 8;
	}

	for (; count >= 1; count /= 8, i++)
	{
		m = (n / count) % 8;
		m += '0';
		p[k + i] = m;
	}
	return (i);
}
