#include "shell.h"

/**
 * _myhistory - disp histrys
 * @check: ins
 *  Return: Always 0
 */
int _myhistory(true_t *check)
{
	print_list(check->history);
	return (0);
}

/**
 * unset_alias - str ali set
 * @check: in p
 * @str: the in str
 *
 * Return: change
 */
int unset_alias(true_t *check, char *str)
{
	char *x, y;
	int rm;

	x = _strchr(str, '=');
	if (!x)
		return (1);
	y = *x;
	*x = 0;
	rm = delete_node_at_index(&(check->alias),
		get_node_index(check->alias, node_starts_with(check->alias, str, -1)));
	*x = y;
	return (rm);
}

/**
 * set_alias - sets alia
 * @check: in
 * @str: the str in
 *
 * Return: change
 */
int set_alias(true_t *check, char *str)
{
	char *x;

	x = _strchr(str, '=');
	if (!x)
		return (1);
	if (!*++x)
		return (alia_display(check, str));

	alia_display(check, str);
	return (add_node_end(&(check->alias), str, 0) == NULL);
}

/**
 * print_alias - gaga
 * @node: the alias node
 *
 * Return: change
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
 * _myalias - built in
 * @check: Strucr
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
			inside_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (i = 1; check->argv[i]; i++)
	{
		p = _strchr(check->argv[i], '=');
		if (p)
			alia_display(check, check->argv[i]);
		else
			alias_print(node_starts_with(check->alias, check->argv[i], '='));
	}

	return (0);
}
