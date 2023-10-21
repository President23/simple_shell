#include "shell.h"

/**
 * main - entry point
 * @ac: args in
 * @av: arrays in
 *
 * Return: change
 */
int main(int ac, char **av)
{
	true_t check[] = { CHECK_INIT };
	int hd = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (hd)
		: "r" (hd));

	if (ac == 2)
	{
		hd = open(av[1], O_RDONLY);
		if (hd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(av[0]);
				_eputs(": 0: Can't open ");
				_eputs(av[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		check->readfd = hd;
	}
	populate_env_list(check);
	read_history(check);
	hsh(check, av);
	return (EXIT_SUCCESS);
}
