#include "shell.h"

/**
 * memory_free - frees ptr
 * @ptr: adr ptr
 *
 * Return: change
 */
int memory_free(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
