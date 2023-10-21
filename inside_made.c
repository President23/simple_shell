#include "shell.h"

/**
 * _myexit - exits the shell
 * @check: in
 *
 *  Return: exits
 *
 */
int _myexit(true_t *check)
{
	int ex;

	if (check->argv[1])  /* If there is an exit arguement */
	{
		ex = _erratoi(check->argv[1]);
		if (ex == -1)
		{
			check->status = 2;
			print_error(check, "Illegal number: ");
			_eputs(check->argv[1]);
			_eputchar('\n');
			return (1);
		}
		check->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	check->err_num = -1;
	return (-2);
}

/**
 * _mycd - change dr
 * @check: Strtr
 *  Return: Always 0
 */
int _mycd(true_t *check)
{
	char *a, *dr, buffer[1024];
	int chng;

	a = getcwd(buffer, 1024);
	if (!a)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!check->argv[1])
	{
		dr = _getenv(check, "HOME=");
		if (!dr)
			chng = /* TODO: what should this be? */
				chdir((dr = _getenv(check, "PWD=")) ? dr : "/");
		else
			chng = chdir(dr);
	}
	else if (_strcmp(check->argv[1], "-") == 0)
	{
		if (!_getenv(check, "OLDPWD="))
		{
			_puts(a);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(check, "OLDPWD=")), _putchar('\n');
		chng = /* TODO: what should this be? */
			chdir((dr = _getenv(info, "OLDPWD=")) ? dr : "/");
	}
	else
		chng = chdir(check->argv[1]);
	if (chng == -1)
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
 * @check: Structr
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
