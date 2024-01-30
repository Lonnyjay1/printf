#include "main.h"

/**
 * get_formatter- Entry point
 * Description: 'the program's description'
 * @s: First operand
 *
 * Return: A pointer of type char
 */
int (*get_formatter(char *s))(unsigned int n, char *p, int k)
{
	formatter_t ops[] = {
		{"b", str_addbit},
		{"u", str_addunsignedint},
		{"x", str_addhexa_x},
		{"X", str_addhexa_X},
		{"o", str_octa}
	};
	int i = 0;

	while (i < 5)
	{
		if (*s == *(ops[i].op))
			return (*(ops[i].f));
		i++;
	};

	i = 0;
	while (i < 5)
	{
		if (*s == *(ops[i].op))
			return (*(ops[i].f));
		i++;
	}
	return (NULL);
}
