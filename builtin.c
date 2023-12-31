#include "shell.h"

/**
 * _myexit - exits the shell
 * @check: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: exits with a given exit status
 *         (0) if info.argv[0] != "exit"
 */
int _myexit(true_t *check)
{
	int exitcheck;

	if (check->argv[1])  /* If there is an exit arguement */
	{
		exitcheck = _erratoi(check->argv[1]);
		if (exitcheck == -1)
		{
			check->status = 2;
			print_error(check, "Illegal number: ");
			_eputs(check->argv[1]);
			_eputchar('\n');
			return (1);
		}
		check->err_num = _erratoi(check->argv[1]);
		return (-2);
	}
	check->err_num = -1;
	return (-2);
}

/**
 * _mycd - changes the current directory of the process
 * @check: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _mycd(true_t *check)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!check->argv[1])
	{
		dir = _getenv(check, "HOME=");
		if (!dir)
			chdir_ret = /* TODO: what should this be? */
				chdir((dir = _getenv(check, "PWD=")) ? dir : "/");
		else
			chdir_ret = chdir(dir);
	}
	else if (_strcmp(check->argv[1], "-") == 0)
	{
		if (!_getenv(check, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(check, "OLDPWD=")), _putchar('\n');
		chdir_ret = /* TODO: what should this be? */
			chdir((dir = _getenv(check, "OLDPWD=")) ? dir : "/");
	}
	else
		chdir_ret = chdir(check->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(check, "can't cd to ");
		_eputs(check->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(check, "OLDPWD", _getenv(check, "PWD="));
		_setenv(check, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _myhelp - changes the current directory of the process
 * @check: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _myhelp(true_t *check)
{
	char **arg_array;

	arg_array = check->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_array); /* temp att_unused workaround */
	return (0);
}
