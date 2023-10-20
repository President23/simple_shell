#include "shell.h"
#include <stdio.h>
#include <unistd.h>

/**
 * true_shell - give mode
 * @shell: inside
 *
 * Return: change
 */

int true_shell(true_t *shell)
{
	if (isatty(STDIN_FILENO) && shell->readfd <= 2)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
 * char_check - checks char
 * @a: the char to check
 * @check: to be checked
 * Return: change
 */
int char_check(char a, char *check)
{
	while (*check)
		if (*check++ == a)
			return (1);
	return (0);
}

/**
 * alpha_check - checks for alphabetic
 *@c: The character to input
 *Return: change
 */

int alpha_check(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * pres_pro - converts str
 *@str: the string to be converted
 *Return: 0 if no
 */

int pres_pro(char *str)
{
	int a, inp = 1, glad = 0, outp;
	unsigned int give = 0;

	for (a = 0;  str[a] != '\0' && glad != 2; a++)
	{
		if (str[a] == '-')
			inp *= -1;

		if (str[a] >= '0' && str[a] <= '9')
		{
			glad = 1;
			give *= 10;
			give += (str[a] - '0');
		}
		else if (glad == 1)
			glad = 2;
	}

	if (inp == -1)
		outp = -give;
	else
		outp = give;

	return (outp);
}
