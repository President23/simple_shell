#include "shell.h"

/**
 * _myenv - print
 * @check: Structr
 * Return: Any
 */
int _myenv(true_t *check)
{
	print_list_str(check->env);
	return (0);
}

/**
 * _getenv - getit
 * @check: Stuctr
 * @shit: env var name
 *
 * Return: any v
 */
char *_getenv(true_t *check, const char *shit)
{
	list_t *node = check->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - Initialize a new environment variable,
 *             or modify an existing one
 * @check: Structr
 *  Return: ain
 */
int _mysetenv(check_t *check)
{
	if (check->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(check, check->argv[1], check->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - Rmv
 * @check: Structr
 *  Return: any
 */
int _myunsetenv(true_t *check)
{
	int i;

	if (check->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= info->argc; i++)
		_unsetenv(check, check->argv[i]);

	return (0);
}

/**
 * populate_env_list - pop
 * @check: in
 * Return: Always 0
 */
int populate_env_list(true_t *check)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	check->env = node;
	return (0);
}
