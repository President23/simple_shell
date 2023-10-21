#include "shell.h"

/**
 * interactive - give mode
 * @shell: inside
 *
 * Return: change
 */

int interactive(true_t *shell)
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
 * is_delim - checks char
 * @a: the char to check
 * @check: to be checked
 * Return: change
 */
int is_delim(char a, char *check)
{
	while (*check)
		if (*check++ == a)
			return (1);
	return (0);
}

/**
 * _isalpha - checks for alphabetic
 *@c: The character to input
 *Return: change
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - converts str
 *@str: the string to be converted
 *Return: 0 if no
 */

int _atoi(char *str)
{
	int a, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0;  s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}
