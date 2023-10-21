#include "shell.h"

/**
 * clear_info - retrieve
 * @check: adrs
 */
void clear_info(true_t *check)
{
	check->arg = NULL;
	check->argv = NULL;
	check->path = NULL;
	check->argc = 0;
}

/**
 * set_info - init
 * @check: ad
 * @av: args
 */
void set_info(true_t *check, char **av)
{
	int a = 0;

	check->fname = av[0];
	if (check->arg)
	{
		check->argv = strtow(check->arg, " \t");
		if (!check->argv)
		{

			check->argv = malloc(sizeof(char *) * 2);
			if (check->argv)
			{
				check->argv[0] = _strdup(check->arg);
				check->argv[1] = NULL;
			}
		}
		for (a = 0; check->argv && check->argv[a]; a++)
			;
		check->argc = a;

		replace_alias(check);
		replace_vars(check);
	}
}

/**
 * free_info - retrieve
 * @check: adrs
 * @all: in
 */
void free_info(true_t *check, int all)
{
	ffree(check->argv);
	check->argv = NULL;
	check->path = NULL;
	if (all)
	{
		if (!check->cmd_buf)
			free(check->arg);
		if (check->env)
			free_list(&(check->env));
		if (check->history)
			free_list(&(check->history));
		if (check->alias)
			free_list(&(check->alias));
		ffree(check->environ);
			check->environ = NULL;
		bfree((void **)check->cmd_buf);
		if (check->readfd > 2)
			close(check->readfd);
		_putchar(BUF_FLUSH);
	}
}
