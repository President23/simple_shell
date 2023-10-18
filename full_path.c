#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "shell.h"

#define MAX_COMMAND_LENGTH 1024

/**
 * full_path - run commands on own shell path
 * Return: change
 */

int full_path(void)
{
	char in[MAX_COMMAND_LENGTH];
	char args[95];

	while (1)
	{
		printf("#cisfun$ ");

		if (fget(in, MAX_COMMAND_LENGTH, stdin) == NULL)
		{
			break;
		}

		int c = 0;
		char *token = strtok(in, " \n");

		while (token != NULL)
		{
			args[c] = token;
			c++;

			token = strtok(NULL, " \n");
		}

		args[c] = NULL;

		if (c > 0)
		{
			pid_t pid = fork();

			if (pid == -1)
			{
				perror("fake f");
				exit(1);
			}
			else if (pid == 0)
			{
				execv(args[0], args);
				perror("execve failed");
				exit(1);
			}
			else
			{
				int status;

				wait(&status);
			}
		}
	}

	return (0);
}

