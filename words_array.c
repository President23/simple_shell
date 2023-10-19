#include "shell.h"
#include <string.h>
#include <stdio.h>

#define MAX_ARGS 10

/**
 * words_array - splits str into array
 * @input: in
 * Return: change
 */

int words_array(char *input)
{
	char *ar[MAX_ARGS];
	int c = 0;
	int a;

	char *token = strtok(input, " ");

	while (token != NULL)
	{
		ar[c] = token;
		c++;

		if (c >= MAX_ARGS)
		{
			printf("Too many args.\n");
			return (0);
		}
		token = strtok(NULL, " ");
	}

	for (a = 0; a < c; a++)
	{
		printf("ar %d: %s\n", a, ar[a]);
	}

	return (0);
}
