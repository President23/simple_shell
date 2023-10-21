#include <stdlib.h>

/**
 * bfree - freeing
 * @ptr:in
 * Return: change
 */
void bfree(void *ptr)
{
	if (ptr != NULL)
	{
		free(ptr);
		
		ptr = NULL;
	}
}
