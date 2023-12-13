#include "main.h"

/**
 * zd_excut - Function executes command line
 *
 * @user_cmd: command line
 *
 * @argv: pointer string of the command.
 *
 * @env: pointer to environment variables
 *
 * @stat: pointer to status
 *
 * Return: function return 0.
 *
*/

int zd_excut(char *user_cmd, char **argv, char *env[], int *stat)
{
	int a;
	int fd;

	fd = fork();
	if (fd == -1)
		perror("ERROR IN FORK");
	if (fd == 0)
	{
		a = execve(user_cmd, argv, env);
		if (a == -1)
			exit(126);
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(stat);
		*stat = WEXITSTATUS(*stat);
	}
	free(argv);
	return (0);
}
