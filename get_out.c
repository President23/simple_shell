#include "shell.h"

/**
 **_strncpy - cpy str
 *@dest: in
 *@sc: sc in
 *@num: in
 *Return: any
 */
char *_strncpy(char *dest, char *sc, int num)
{
	int a, d;
	char *s = dest;

	a = 0;
	while (sc[a] != '\0' && a < num - 1)
	{
		dest[a] = sc[a];
		a++;
	}
	if (a < num)
	{
		d = a;
		while (d < num)
		{
			dest[d] = '\0';
			d++;
		}
	}
	return (s);
}

/**
 **_strncat - mk 2 str
 *@dest: in
 *@sc: in
 *@num: in by
 *Return: chnge
 */
char *_strncat(char *dest, char *sc, int num)
{
	int a, d;
	char *s = dest;

	a = 0;
	d = 0;
	while (dest[a] != '\0')
		a++;
	while (sc[d] != '\0' && d < num)
	{
		dest[a] = sc[d];
		a++;
		d++;
	}
	if (d < num)
		dest[a] = '\0';
	return (s);
}

/**
 **_strchr - loc sth
 *@str: the str in
 *@c: ther in
 *Return: ptr
 */
char *_strchr(char *str, char c)
{
	do {
		if (*str == c)
			return (str);
	} while (*str++ != '\0');

	return (NULL);
}
