#include "shell.h"

/**
 * hsh - to be determined
 * @check: the par used
 * @av: the arg in shell
 *
 * Return: any
 */
int hsh(true_t *check, char **av)
{
	ssize_t s = 0;
	int builtin_ret = 0;

	while (s != -1 && builtin_ret != -2)
	{
		clear_info(check);
		if (interactive(check))
			_puts("$ ");
		_eputchar(BUF_FLUSH);
		s = get_input(check);
		if (s != -1)
		{
			set_info(check, av);
			builtin_ret = find_builtin(check);
			if (builtin_ret == -1)
				find_cmd(check);
		}
		else if (interactive(check))
			_putchar('\n');
		free_info(check, 0);
	}
	write_history(check);
	free_info(check, 1);
	if (!interactive(check) && check->status)
		exit(check->status);
	if (builtin_ret == -2)
	{
		if (check->err_num == -1)
			exit(check->status);
		exit(check->err_num);
	}
	return (builtin_ret);
}

/**
 * find_builtin - finds cmd
 * @check: par in
 *
 * Return: change
 */
int find_builtin(true_t *check)
{
	int a, built_in_ret = -1;
	builtin_table builtintbl[] = {
		{"exit", _myexit},
		{"env", _myenv},
		{"help", _myhelp},
		{"history", _myhistory},
		{"setenv", _mysetenv},
		{"unsetenv", _myunsetenv},
		{"cd", _mycd},
		{"alias", _myalias},
		{NULL, NULL}
	};

	for (a = 0; builtintbl[a].type; a++)
		if (_strcmp(check->argv[0], builtintbl[a].type) == 0)
		{
			check->line_count++;
			built_in_ret = builtintbl[a].func(check);
			break;
		}
	return (built_in_ret);
}

/**
 * find_cmd - finds cmd
 * @check: the par in
 *
 * Return: void
 */
void find_cmd(true_t *check)
{
	char *path = NULL;
	int a, k;

	check->path = check->argv[0];
	if (check->linecount_flag == 1)
	{
		check->line_count++;
		check->linecount_flag = 0;
	}
	for (a = 0, k = 0; check->arg[a]; a++)
		if (!is_delim(check->arg[a], " \t\n"))
			k++;
	if (!k)
		return;

	path = find_path(check, _getenv(check, "PATH="), check->argv[0]);
	if (path)
	{
		check->path = path;
		fork_cmd(check);
	}
	else
	{
		if ((interactive(check) || _getenv(check, "PATH=")
			|| check->argv[0][0] == '/') && is_cmd(check, check->argv[0]))
			fork_cmd(check);
		else if (*(check->arg) != '\n')
		{
			check->status = 127;
			print_error(check, "not found\n");
		}
	}
}

/**
 * fork_cmd - run exec
 * @check: the par in
 *
 * Return: void
 */
void fork_cmd(true_t *check)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		/* TODO: PUT ERROR FUNCTION */
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(check->path, check->argv, get_environ(check)) == -1)
		{
			free_info(check, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
		/* TODO: PUT ERROR FUNCTION */
	}
	else
	{
		wait(&(check->status));
		if (WIFEXITED(check->status))
		{
			check->status = WEXITSTATUS(check->status);
			if (check->status == 126)
				print_error(check, "Permission denied\n");
		}
	}
}
