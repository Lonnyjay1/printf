#include "main.h"
#include <unistd.h>

/**
 * _printf- Entry point
 * Description: 'the program's description'
 * @format: First operand
 *
 * Return: A pointer of type char
 */
int _printf(const char *format, ...)
{
	int i = 0;
	char *f, p[BUFFSIZE];
	va_list ap;

	va_start(ap, format);
	f = (char *)format;
	if (f == NULL)
		return (-1);
	for (i = 0; *f; f++, i++)
	{
		if (*f != '%')
			p[i] = *f;
		else
		{
			f++;
			if (*f == '%')
				p[i] = *f;
			else
			{
				i += format_handler(f, ap, p, i);
				i--;
			}
		}
		va_end(ap);
	}
	write(1, p, i);
	return (i);
}

/**
 * format_handler- Entry point
 * Description: 'the program's description'
 * @f: First operand
 * @ap: Second operand
 * @p: Third operand
 * @k: Fourth operand
 *
 * Return: A pointer of type char
 */
int format_handler(char *f, va_list ap, char *p, int k)
{
	int i = 0;
	char *n, c;
	unsigned int j;

	switch (*f)
	{
		case 's':
			n = va_arg(ap, char *);
			i = str_len(n, p, k);
			break;
		case 'c':
			c = va_arg(ap, int);
			p[k + i] = c;
			i = 1;
			break;
		case 'i':
		case 'd':
			i = va_arg(ap, int);
			i = str_addint(i, p, k);
			break;
		case 'b':
		case 'u':
		case 'x':
		case 'X':
		case 'o':
			j = va_arg(ap, unsigned int);
			i = (get_formatter(f)(j, p, k));
			break;
		default:
			break;
	}
	return (i);
}

/**
 * str_len - returns the length of a string.
 * @s: First operand.
 * @p: Second operand.
 * @k: Third operand.
 *
 * Return: length of a string.
 */
int str_len(char *s, char *p, int k)
{
	int count = 0;
	char nill[] = "(null)";

	if (s == NULL)
	{
		for (count = 0; nill[count]; count++)
			p[k + count] = nill[count];
		return (6);
	}

	while (*(s + count) != '\0')
	{
		p[k + count] = s[count];
		count++;
	}
	return (count);
}

/**
 * str_addint - returns the length of a string.
 * @n: First operand.
 * @p: Second operand.
 * @k: Third operand.
 *
 * Return: length of a string.
 */
int str_addint(int n, char *p, int k)
{
	int m, d, count, i = 0;

	if (n < 0)
	{
		p[k + i] = '-';
		m = n * -1;
		i++;
	}
	else
		m = n;

	d = m;
	count = 1;

	while (d > 9)
	{
		d /= 10;
		count *= 10;
	}
	for (; count >= 1; count /= 10, i++)
	{
		p[k + i] = (((m / count) % 10) + '0');
	}
	return (i);
}

/**
 * str_addbit - returns the length of a string.
 * @n: First operand.
 * @p: Second operand.
 * @k: Third operand.
 *
 * Return: length of a string.
 */

int str_addbit(unsigned int n, char *p, int k)
{
	unsigned int d, count, i = 0;

	d = n;
	count = 1;
	while (d > 1)
	{
		d /= 2;
		count *= 2;
	}
	for (; count >= 1; count /= 2, i++)
		p[k + i] = (((n / count) % 2) + '0');
	return ((int) i);
}
