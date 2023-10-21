#include "shell.h"

/**
 * get_history_file - gets th shit
 * @check: par in
 *
 * Return: change
 */

char *get_history_file(true_t *check)
{
	char *buf, *dir;

	dir = _getenv(check, "HOME=");
	if (!dir)
		return (NULL);
	buf = malloc(sizeof(char) * (_strlen(dir) + _strlen(HIST_FILE) + 2));
	if (!buf)
		return (NULL);
	buf[0] = 0;
	_strcpy(buf, dir);
	_strcat(buf, "/");
	_strcat(buf, HIST_FILE);
	return (buf);
}

/**
 * write_history - creates sth
 * @check: par in
 *
 * Return: change
 */
int write_history(true_t *check)
{
	ssize_t hd;
	char *filename = get_history_file(check);
	list_t *node = NULL;

	if (!filename)
		return (-1);

	hd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	if (hd == -1)
		return (-1);
	for (node = check->history; node; node = node->next)
	{
		_putsfd(node->str, hd);
		_putfd('\n', hd);
	}
	_putfd(BUF_FLUSH, hd);
	close(hd);
	return (1);
}

/**
 * read_history - read sth
 * @check: in par
 *
 * Return: change
 */
int read_history(true_t *check)
{
	int a, last = 0, linecount = 0;
	ssize_t hd, rdlen, fsize = 0;
	struct stat st;
	char *buf = NULL, *filename = get_history_file(check);

	if (!filename)
		return (0);

	hd = open(filename, O_RDONLY);
	free(filename);
	if (hd == -1)
		return (0);
	if (!fstat(hd, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	buf = malloc(sizeof(char) * (fsize + 1));
	if (!buf)
		return (0);
	rdlen = read(hd, buf, fsize);
	buf[fsize] = 0;
	if (rdlen <= 0)
		return (free(buf), 0);
	close(hd);
	for (a = 0; a < fsize; a++)
		if (buf[a] == '\n')
		{
			buf[a] = 0;
			build_history_list(check, buf + last, linecount++);
			last = a + 1;
		}
	if (last != a)
		build_history_list(check, buf + last, linecount++);
	free(buf);
	check->histcount = linecount;
	while (check->histcount-- >= HIST_MAX)
		delete_node_at_index(&(check->history), 0);
	renumber_history(check);
	return (check->histcount);
}

/**
 * build_history_list - adds
 * @check: str in
 * @buf: buffer
 * @linecount: count
 *
 * Return: Always 0
 */
int build_history_list(true_t *check, char *buf, int linecount)
{
	list_t *node = NULL;

	if (check->history)
		node = check->history;
	add_node_end(&node, buf, linecount);

	if (!check->history)
		check->history = node;
	return (0);
}

/**
 * renumber_history - renum
 * @check: shit in
 *
 * Return: change
 */
int renumber_history(true_t *check)
{
	list_t *node = check->history;
	int a = 0;

	while (node)
	{
		node->num = a++;
		node = node->next;
	}
	return (check->histcount = a);
}
