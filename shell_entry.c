#include <stdio.h>
#include <unistd.h>

/**
 * creates_object - my checking
 * Return: sth
 */

int creates_object()
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
