#include "main.h"

/**
 * zd_non_interactive_mode - Function that run shell program
 *
 * @argv: string pointer to command
 *
 * Return: returns void
 *
*/

void zd_non_interactive_mode(char **argv)
{
	char *lineptr = NULL, *ptr, *command_copy,
	     **command_argv = {NULL}, *environ[] = {NULL};

	size_t z = 0;
	ssize_t rd;
	int stat = 0, c = 0, i;

	while (1)
	{
		c++;
		rd = zd_getline(&lineptr, &z, stdin);
		if (rd == -1)
		{
			break;
		}
		command_copy = zdhandle_new_line(lineptr);
		ptr = get_total_path(command_copy);
		if (zd_strcmp(command_copy, "\n") == 0 || command_copy[0] == '#')
			continue;
		else if (zd_builtin_command(argv[0], command_copy, &stat, c, lineptr) != -1)
		{
			free(ptr);
			continue;
		}
		else if (ptr != NULL)
		{
			command_argv = zd_argv(command_copy);
			i = zd_excut(ptr, command_argv, environ, &stat);
			if (i == 0)
				zd_print_errors(argv[0], c, stat, command_copy);
		}
		else if (ptr == NULL)
		{
			zdexcute_notFound(command_copy, command_argv, environ, &stat);
			zd_print_errors(argv[0], c, stat, command_copy);
		}
		free(ptr);
	}
	free(lineptr);
}
