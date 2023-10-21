#include "shell.h"

/**
 * _strlen - returns len
 * @str: to be checked
 *
 * Return: change
 */
int _strlen(char *str)
{
	int a = 0;

	if (!str)
		return (0);

	while (*str++)
		a++;
	return (a);
}

/**
 * _strcmp - performs
 * @s1: in
 * @s2: in
 *
 * Return: change
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - checker
 * @haystack: str search
 * @needle: the in str
 *
 * Return: changer
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - conc str
 * @dest: buf
 * @sc: sc buf
 *
 * Return: point
 */
char *_strcat(char *dest, char *sc)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*sc)
		*dest++ = *sc++;
	*dest = *sc;
	return (ret);
}
