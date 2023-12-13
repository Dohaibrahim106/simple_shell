#include "main.h"

/**
 * zd_argv - Function That generate all the arguments
 *
 * @lineptr: pointer to string from getline
 *
 * Return: pointer array of strings
 *
*/

char **zd_argv(char *lineptr)
{
	char **argv, *zd_token;
	int x = 0;

	argv = malloc(sizeof(char *) * (zd_strlen(lineptr) + 1));

	if (!argv)
		perror("malloc");

	zd_token = zd_strtok(lineptr, _DELIMITER);
	while (zd_token)
	{
		if (zd_token[0] == '#')
			break;
		argv[x] = zd_token;
		zd_token = zd_strtok(NULL, _DELIMITER);
		x++;
	}

	argv[x] = NULL;
	return (argv);
}
