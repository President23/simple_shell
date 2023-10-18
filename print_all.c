#include "shell.h"
#include <stdio.h>
#include <unistd.h>

/**
 * print_all - prints args
 * @ac: in
 * @av: in
 *
 * Return: change
 */

int print_all(int ac, char **av)
{
	int c = 1;
	(void)ac;

	while (av[c] != NULL)
	{
		printf("%s\n", av[c]);
		c++;
	}

	return (0);
}
