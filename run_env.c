#include "shell.h"

/**
 * get_environ - make return
 * @check: Structr made
 * Return: change
 */
char **get_environ(true_t *check)
{
	if (check->environ || check->env_changed)
	{
		check->environ = list_to_strings(check->env);
		check->env_changed = 0;
	}

	return (check->environ);
}

/**
 * _unsetenv - Rmv shit
 * @check: strectr mad
 * @var: str in
 *  Return: change
 */
int _unsetenv(true_t *check, char *var)
{
	list_t *node = check->env;
	size_t a = 0;
	char *q;

	if (!node || !var)
		return (0);

	while (node)
	{
		q = starts_with(node->str, var);
		if (q && *q == '=')
		{
			check->env_changed = delete_node_at_index(&(check->env), a);
			a = 0;
			node = check->env;
			continue;
		}
		node = node->next;
		a++;
	}
	return (check->env_changed);
}

/**
 * _setenv - Init
 * @check: in
 * @var: str in
 * @valuer: infound
 *  Return: change
 */
int _setenv(true_t *check, char *var, char *valuer)
{
	char *buf = NULL;
	list_t *node;
	char *q;

	if (!var || !valuer)
		return (0);

	buf = malloc(_strlen(var) + _strlen(valuer) + 2);
	if (!buf)
		return (1);
	_strcpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, valuer);
	node = check->env;
	while (node)
	{
		q = starts_with(node->str, var);
		if (q && *q == '=')
		{
			free(node->str);
			node->str = buf;
			check->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(check->env), buf, 0);
	free(buf);
	check->env_changed = 1;
	return (0);
}
