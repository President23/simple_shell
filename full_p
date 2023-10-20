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
	char *args[MAX_COMMAND_LENGTH];
	int ar = 0;
	char *token = strtok(in, " ");

	while (1)
	{
		printf("#cisfun$ ");

		if (fgets(in, MAX_COMMAND_LENGTH, stdin) == NULL)
		{
			break;
		}
		
		in[strlen(in) - 1] = '\0';;


		while (token != NULL)
		{
			args[ar] = token;
			ar++;

			token = strtok(NULL, " \n");
		}

		args[ar] = NULL;

		if (ar > 0)
		{
			pid_t pid = fork();

			if (pid == -1)
			{
				perror("fork failed");
				exit(1);
			}
			else if (pid == 0)
			{
				if (execvp(args[0], args) == -1)
				{
					perror("execve failed");
					exit(1);
				}
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
