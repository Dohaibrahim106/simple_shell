#include "main.h"

/**
 * zdexcute_notFound - function check ststus
 *
 * @lineptr: pointer to the string
 *
 * @command_argv: argument vector
 *
 * @envi: environment variable
 *
 * @stat: status
 *
 * Return: Function returns void
 *
*/

void zdexcute_notFound(char *lineptr,
		char **command_argv,
		char *envi[], int *stat)
{
	int x;
	int d;

	d = fork();
	if (d == -1)
		perror("ERROR IN FORK");
	if (d == 0)
	{
		x = execve(lineptr, command_argv, envi);
		if (x == -1)
		{
			exit(127);
		}
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(stat);
		*stat = WEXITSTATUS(*stat);
	}
}
