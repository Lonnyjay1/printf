#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdlib.h>
#include <stdarg.h>

#define BUFFSIZE 1024

/**
 * struct formatter - Struct op
 *
 * @op: The operator
 * @f: The function associated
 */
typedef struct formatter
{
	char *op;
	int (*f)(unsigned int n, char *p, int k);
} formatter_t;

int _printf(const char *format, ...);
int format_handler(char *f, va_list ap, char *p, int k);
int str_len(char *s, char *p, int k);
int str_addint(int n, char *p, int k);
int str_addbit(unsigned int n, char *p, int k);
int str_addunsignedint(unsigned int n, char *p, int k);
int str_addhexa_x(unsigned int n, char *p, int k);
int str_addhexa_X(unsigned int n, char *p, int k);
int str_octa(unsigned int n, char *p, int k);
int (*get_formatter(char *s))(unsigned int n, char *p, int k);
int print_buff(char *p, int k);

#endif
