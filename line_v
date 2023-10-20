#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "shell.h"
/**
 * line_vibe - pro tto print $
 * Return: change
 */

int line_vibe(void)
{
	char *line = NULL;
	size_t length = 0;
	ssize_t rd;

	printf("$  ");
	rd = getline(&line, &length, stdin);

	if (rd != -1)
	{
		printf("Vibe: %s", line);
	}

	free(line);
	return (0);
}
