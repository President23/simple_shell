#include "shell.h"

/**
 * _erratoi - cnvrts
 * @str: str
 * Return: change
 */
int _erratoi(char *str)
{
	int a = 0;
	unsigned long int result = 0;

	if (*str == '+')
		str++;  /* TODO: why does this make main return 255? */
	for (a = 0;  str[a] != '\0'; a++)
	{
		if (str[a] >= '0' && str[a] <= '9')
		{
			result *= 10;
			result += (str[a] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * print_error - print
 * @check: the par
 * @str: str in
 * Return: change
 */
void print_error(true_t *check, char *str)
{
	_eputs(check->fname);
	_eputs(": ");
	print_d(check->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(check->argv[0]);
	_eputs(": ");
	_eputs(str);
}

/**
 * print_d - funct ctr
 * @input: the input
 * @hd: the file d
 *
 * Return: numb
 */
int print_d(int input, int hd)
{
	int (*__putchar)(char) = _putchar;
	int a, count = 0;
	unsigned int _abs_, current;

	if (hd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (a = 1000000000; a > 1; a /= 10)
	{
		if (_abs_ / a)
		{
			__putchar('0' + current / a);
			count++;
		}
		current %= a;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 * convert_number - cnvrts
 * @num: numb
 * @base: base
 * @flags: argument flags
 *
 * Return: string
 */
char *convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
 * remove_comments - rmv com
 * @buf: in
 *
 * Return: Any
 */
void remove_comments(char *buf)
{
	int a;

	for (a = 0; buf[a] != '\0'; a++)
		if (buf[a] == '#' && (!a || buf[a - 1] == ' '))
		{
			buf[a] = '\0';
			break;
		}
}
