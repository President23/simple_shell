#include <stdio.h>
#include <unistd.h>
#include "shell.h"
/**
 * creates_object - my checking
 * Return: sth
 */

int creates_object(void)
{
	int *myobject = NULL;

	if (myobject != NULL)
	{
		printf("The object exists.\n");
	}
	else
	{
		printf("The object doesn't exist.\n");
	}

	return (0);
}
