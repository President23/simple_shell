#include "shell.h"

/**
 * is_chain - test
 * @check: th par
 * @buf: the in
 * @p: address of current position in
 * Return: change
 */
int is_chain(true_t *check, char *buf, size_t *p)
{
	size_t d = *p;

	if (buf[d] == '|' && buf[d + 1] == '|')
	{
		buf[d] = 0;
		d++;
		check->cmd_buf_type = CMD_OR;
	}
	else if (buf[d] == '&' && buf[d + 1] == '&')
	{
		buf[d] = 0;
		d++;
		check->cmd_buf_type = CMD_AND;
	}
	else if (buf[d] == ';') /* found end of this command */
	{
		buf[d] = 0; /* replace semicolon with null */
		check->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*p = d;
	return (1);
}

/**
 * check_chain - chck
 * @check: in par
 * @buf: the char buffer
 * @p: addres
 * @i: start
 * @len: length of buf
 *
 * Return: Void
 */
void check_chain(true_t *check, char *buf, size_t *p, size_t i, size_t len)
{
	size_t d = *p;

	if (check->cmd_buf_type == CMD_AND)
	{
		if (check->status)
		{
			buf[i] = 0;
			d = len;
		}
	}
	if (check->cmd_buf_type == CMD_OR)
	{
		if (!check->status)
		{
			buf[i] = 0;
			d = len;
		}
	}

	*p = d;
}

/**
 * replace_alias - repl
 * @check: in par
 *
 * Return: change
 */
int replace_alias(true_t *check)
{
	int a;
	list_t *node;
	char *p;

	for (a = 0; a < 10; a++)
	{
		node = node_starts_with(check->alias, check->argv[0], '=');
		if (!node)
			return (0);
		free(check->argv[0]);
		p = _strchr(node->str, '=');
		if (!p)
			return (0);
		p = _strdup(p + 1);
		if (!p)
			return (0);
		check->argv[0] = p;
	}
	return (1);
}

/**
 * replace_vars - replac
 * @check: in para
 *
 * Return: change
 */
int replace_vars(true_t *check)
{
	int a = 0;
	list_t *node;

	for (a = 0; check->argv[a]; a++)
	{
		if (check->argv[a][0] != '$' || !check->argv[a][1])
			continue;

		if (!_strcmp(check->argv[a], "$?"))
		{
			replace_string(&(check->argv[a]),
				_strdup(convert_number(check->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[a], "$$"))
		{
			replace_string(&(check->argv[a]),
				_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(check->env, &check->argv[a][1], '=');
		if (node)
		{
			replace_string(&(check->argv[a]),
				_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_string(&check->argv[a], _strdup(""));

	}
	return (0);
}

/**
 * replace_string - rep str
 * @old: addre old str
 * @new: new
 *
 * Return: change
 */
int replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}
