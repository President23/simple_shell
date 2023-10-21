#include "shell.h"

/**
 * **strtow - split str
 * @str: the in
 * @d: the de
 * Return: a point
 */

char **strtow(char *str, char *d)
{
	int a, d, k, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (a = 0; str[a] != '\0'; a++)
		if (!is_delim(str[a], e) && (is_delim(str[a + 1], e) || !str[a + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (a = 0, d = 0; d < numwords; d++)
	{
		while (is_delim(str[a], e))
			a++;
		k = 0;
		while (!is_delim(str[a + k], e) && str[a + k])
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[d][m] = str[a++];
		s[d][m] = 0;
	}
	s[d] = NULL;
	return (s);
}

/**
 * **strtow2 - split
 * @str: the in
 * @d: the delimeter
 * Return: a poi
 */
char **strtow2(char *str, char d)
{
	int a, d, k, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (a = 0; str[a] != '\0'; a++)
		if ((str[a] != e && str[a + 1] == e) ||
		    (str[a] != e && !str[a + 1]) || str[a + 1] == e)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (a = 0, e = 0; e < numwords; e++)
	{
		while (str[a] == e && str[a] != e)
			a++;
		k = 0;
		while (str[a + k] != e && str[a + k] && str[a + k] != e)
			k++;
		s[d] = malloc((k + 1) * sizeof(char));
		if (!s[d])
		{
			for (k = 0; k < d; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[d][m] = str[a++];
		s[d][m] = 0;
	}
	s[d] = NULL;
	return (s);
}
