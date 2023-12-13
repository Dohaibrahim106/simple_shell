#include "main.h"

/**
 * zd_builtin_command - Function excute builtin commands
 *
 * @programe_name: command name
 *
 * @counter: number of commands
 *
 * @stat: status of process
 *
 * @lineptr: command builtin
 *
 * @lin: line
 *
 * Return: return (-1) or (i)
 *
*/

int zd_builtin_command(char *programe_name, char *lineptr,
		int *stat, int counter, char *lin)
{
	int num = 1;
	int i;
	char *cmd_copy;
	char *built_command[] = {"exit", "env", "echo"};

	cmd_copy = strdup(lineptr);
	cmd_copy = zd_strtok(cmd_copy, " ");

	for (i = 0; i < 2; i++)
	{
		if (zd_strcmp(cmd_copy, built_command[i]) == 0)
		{
			num = 0;
			free(cmd_copy);
			break;
		}
	}
	switch (i)
	{
		case 0:
			zd_exit(lineptr, stat, counter, programe_name, lin);
			break;
		case 1:
			zd_env();
			break;
	}
	if (num)
	{
		free(cmd_copy);
		return (-1);
	}
	else
		return (i);
}
