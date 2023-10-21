#include "shell.h"

/**
 * input_buf - put shit
 * @check: ad
 * @buf: buf ad
 * @length: len of shit
 *
 * Return: rd byt
 */
ssize_t input_buf(true_t *check, char **buf, size_t *length)
{
	ssize_t s = 0;
	size_t len_p = 0;

	if (!*length) /* if nothing left in the buffer, fill it */
	{
		/*bfree((void **)info->cmd_buf);*/
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigintHandler);

		s = getline(buf, &len_p, stdin);

		s = _getline(check, buf, &len_p);

		if (s > 0)
		{
			if ((*buf)[s - 1] == '\n')
			{
				(*buf)[s - 1] = '\0'; /* remove trailing newline */
				s--;
			}
			check->linecount_flag = 1;
			remove_comments(*buf);
			build_history_list(check, *buf, check->histcount++);
			/* if (_strchr(*buf, ';')) is this a command chain? */
			{
				*length = s;
				check->cmd_buf = buf;
			}
		}
	}
	return (s);
}

/**
 * get_input - get line
 * @check: par
 *
 * Return: by r
 */
ssize_t get_input(true_t *check)
{
	static char *buf; /* the ';' command chain buffer */
	static size_t a, d, length;
	ssize_t s = 0;
	char **buf_p = &(check->arg), *q;

	_putchar(BUF_FLUSH);
	s = input_buf(check, &buf, &length);
	if (s == -1) /* EOF */
		return (-1);
	if (length)	/* we have commands left in the chain buffer */
	{
		d = a; /* init new iterator to current buf position */
		q = buf + a; /* get pointer for return */

		check_chain(check, buf, &d, a, length);
		while (d < length) /* iterate to semicolon or end */
		{
			if (is_chain(check, buf, &d))
				break;
			d++;
		}

		a = d + 1; /* increment past nulled ';'' */
		if (a >= length) /* reached end of buffer? */
		{
			a = length = 0; /* reset position and length */
		}

		*buf_p = q; /* pass back pointer to current command position */
		return (_strlen(q)); /* return length of current command */
	}

	*buf_p = buf; /* else not a chain, pass back buffer from _getline() */
	return (s); /* return length of buffer from _getline() */
}

/**
 * read_buf - buff r
 * @check: par in
 * @buf: buffer
 * @i: size
 *
 * Return: r
 */
ssize_t read_buf(true_t *check, char *buf, size_t *i)
{
	ssize_t s = 0;

	if (*i)
		return (0);
	s = read(check->readfd, buf, READ_BUF_SIZE);
	if (s >= 0)
		*i = s;
	return (s);
}

/**
 * _getline - get l
 * @check: in
 * @ptr: ad
 * @len: inp
 *
 * Return: change
 */
int _getline(true_t *check, char **ptr, size_t *len)
{
	static char buf[READ_BUF_SIZE];
	static size_t a, length;
	size_t k;
	ssize_t s = 0, r = 0;
	char *q = NULL, *new_p = NULL, *c;

	q = *ptr;
	if (q && len)
		r = *len;
	if (a == length)
		a = length = 0;

	s = read_buf(check, buf, &length);
	if (s == -1 || (s == 0 && length == 0))
		return (-1);

	c = _strchr(buf + a, '\n');
	k = c ? 1 + (unsigned int)(c - buf) : length;
	new_p = _realloc(q, r, r ? r + k : k + 1);
	if (!new_p) /* MALLOC FAILURE! */
		return (q ? free(q), -1 : -1);

	if (r)
		_strncat(new_p, buf + a, k - a);
	else
		_strncpy(new_p, buf + a, k - a + 1);

	r += k - a;
	a = k;
	q = new_p;

	if (len)
		*len = r;
	*ptr = q;
	return (r);
}

/**
 * sigintHandler - blcks sth
 * @sig_num: in
 *
 * Return: void
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}
