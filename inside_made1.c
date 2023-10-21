#include "shell.h"

/**
 * _myhistory - displays
 * @check: Stru
 *  Return: Always 0
 */
int _myhistory(true_t *check)
{
	print_list(check->history);
	return (0);
}

/**
 * unset_alias - sets alias to string
 * @check: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(true_t *check, char *str)
{
	char *p, c;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(check->alias),
		get_node_index(check->alias, node_starts_with(check->alias, str, -1)));
	*p = c;
	return (ret);
}

/**
 * set_alias - sets alias to string
 * @check: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias(true_t *check, char *str)
{
	char *p;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	if (!*++p)
		return (0);

	unset_alias(check, str);
	return (add_node_end(&(check->alias), str, 0) == NULL);
}

/**
 * print_alias - prints an alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
	char *p = NULL, *a = NULL;

	if (node)
	{
		p = _strchr(node->str, '=');
		for (a = node->str; a <= p; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(p + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - mimics the alias builtin (man alias)
 * @check: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _myalias(true_t *check)
{
	int i = 0;
	char *p = NULL;
	list_t *node = NULL;

	if (check->argc == 1)
	{
		node = check->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; check->argv[i]; i++)
	{
		p = _strchr(check->argv[i], '=');
		if (p)
			set_alias(check, check->argv[i]);
		else
			print_alias(node_starts_with(check->alias, check->argv[i], '='));
	}

	return (0);
}
