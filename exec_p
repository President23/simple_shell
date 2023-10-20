#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

/**
 * exec_prog - executes program
 * Return: changes
 */

int exec_prog(void)
{
	int five = 5;
	int a;

	for (a = 0; a < five; a++)
	{
		pid_t f  = fork();

		if (f == -1)
		{
			perror("fake f");
			return (1);
		}

		if (f == 0)
		{
			char *args[] = {"ls", "-l", "/tmp", NULL};

			execve("/bin/ls", args, NULL);
			exit(1);
		}
		else
		{
			int status;

			wait(&status);
			printf("child process %d exited with status \n", a);
		}
	}

	return (0);
}
