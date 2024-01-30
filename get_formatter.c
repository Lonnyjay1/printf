#include "main.h"
/**
 * array_iterator- Entry point
 * Description: 'the program's description'
 * @array: First operand
 * @size : Second operand
 * @action: Third operand
 * 
 * Return: A pointer of type char
 */
int (*get_formatter(char *s))(unsigned int n, char *p, int k)
{
	formatter_t ops [] = {
		{"b", str_addbit_all},
		{"u", str_addunsignedint_all},
		{"x", str_addhexa_x_all},
		{"X", str_addhexa_X_all},
		{"o", str_octa_all}
};
	int i = 0;
	while (i <5)
	{
		if (*s == *(ops [i].op))
			return (*(ops[i].f));
		i++;

	};

	int i = 0;
	while (i <5)
{
	if (*s == *(ops[i].op))
		return (*(ops[i].f));
	i++;
}
return (NULL);
