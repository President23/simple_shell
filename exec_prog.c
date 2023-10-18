#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stddef.h>

/**
 * exec_prog - executes program
 * Return: changes
 */

int exec_prog(void)
{
	int five = 5;

	for (int a = 0; a < five; a++)
	{
		pid_t f  = fake();

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
			printf("child process %d exited with ststus %d\n", a, WEXITSTATU);
		}
	}

	return (0);
}
