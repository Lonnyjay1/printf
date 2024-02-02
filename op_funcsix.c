#include "main.h"

/**
 * print_prg - writes the character c to stdout
 * @a: input char
 * @buf: buffer pointer
 * @i: index for buffer pointer
 * Return: On success 1.
 */
int print_prg(va_list a __attribute__((unused)), char *buf, unsigned int i)
{
	handl_buf(buf, '%', i);

	return (1);
}

/**
 * fill_hex_array - writes the character c to stdout
 *
 * @bnr: array where is stored the binary.
 * @hex: array where is stored the hexadecimal.
 * @isupp: integer that determines if the hexadecimal array is
 * in uppercase or lowercase letter.
 * @limit: size of hex
 * Return: binary array.
 */
char *fill_hex_array(char *bnr, char *hex, int isupp, int limit)
{
	int op, i, j, toletter;

	hex[limit] = '\0';
	if (isupp)
		toletter = 55;
	else
		toletter = 87;
	for (i = (limit * 4) - 1; i >= 0; i--)
	{
		for (op = 0, j = 1; j <= 8; j *= 2, i--)
			op = ((bnr[i] - '0') * j) + op;
		i++;
		if (op < 10)
			hex[i / 4] = op + 48;
		else
			hex[i / 4] = op + toletter;
	}
	return (hex);
}

/**
 * fill_long_oct_array - calculates a long octal number
 *
 * @bnr: array where is stored the binary.
 * @oct: array where is stored the octal.
 *
 * Return: binary array.
 */
char *fill_long_oct_array(char *bnr, char *oct)
{
	int op, i, j, ioct, limit;

	oct[22] = '\0';
	for (i = 63, ioct = 21; i >= 0; i--, ioct--)
	{
		if (i > 0)
			limit = 4;
		else
			limit = 1;
		for (op = 0, j = 1; j <= limit; j *= 2, i--)
			op = ((bnr[i] - '0') * j) + op;
		i++;
		oct[ioct] = op + '0';
	}
	return (oct);
}

/**
 * fill_oct_array - writes the character c to stdout
 *
 * @bnr: array where is stored the binary.
 * @oct: array where is stored the octal.
 *
 * Return: binary array.
 */
char *fill_oct_array(char *bnr, char *oct)
{
	int op, i, j, ioct, limit;

	oct[11] = '\0';
	for (i = 31, ioct = 10; i >= 0; i--, ioct--)
	{
		if (i > 1)
			limit = 4;
		else
			limit = 2;
		for (op = 0, j = 1; j <= limit; j *= 2, i--)
			op = ((bnr[i] - '0') * j) + op;
		i++;
		oct[ioct] = op + '0';
	}
	return (oct);
}

/**
 * fill_short_oct_array - calculates a short octal number
 *
 * @bnr: array where is stored the binary.
 * @oct: array where is stored the octal.
 *
 * Return: binary array.
 */
char *fill_short_oct_array(char *bnr, char *oct)
{
	int op, i, j, ioct, limit;

	oct[6] = '\0';
	for (i = 15, ioct = 5; i >= 0; i--, ioct--)
	{
		if (i > 0)
			limit = 4;
		else
			limit = 1;
		for (op = 0, j = 1; j <= limit; j *= 2, i--)
			op = ((bnr[i] - '0') * j) + op;
		i++;
		oct[ioct] = op + '0';
	}
	return (oct);
}
