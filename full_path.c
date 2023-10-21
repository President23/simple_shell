#include "shell.h"

/**
 * is_cmd - inside
 * @check: check strctr
 * @path: i path
 *
 * Return: change
 */
int is_cmd(true_t *check, char *path)
{
	struct stat st;

	(void)check;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
 * dup_chars - dup chars
 * @pathstr: the str pth
 * @start: in
 * @stop: in
 *
 * Return: ptr
 */
char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int a = 0, k = 0;

	for (k = 0, a = start; a < stop; a++)
		if (pathstr[a] != ':')
			buf[k++] = pathstr[a];
	buf[k] = 0;
	return (buf);
}

/**
 * find_path - ind way
 * @check: par in
 * @pathstr: str in
 * @cmd: found
 *
 * Return: changer
 */
char *find_path(true_t *check, char *pathstr, char *cmd)
{
	int a = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(check, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[a] || pathstr[a] == ':')
		{
			path = dup_chars(pathstr, curr_pos, a);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(check, path))
				return (path);
			if (!pathstr[a])
				break;
			curr_pos = a;
		}
		a++;
	}
	return (NULL);
}
