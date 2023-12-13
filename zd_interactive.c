#include "main.h"
/**
 * zd_interactive_mode - Function used to run shell in interactive mode
 * @argv: array pointer to commands
 * Return: function return void.
*/
void zd_interactive_mode(char **argv)
{
char *lineptr = NULL, *ptr, *command_copy,
**command_argv = {NULL}, *environ[] = {NULL};
ssize_t rd;
int stat = 0, z = 0, i;
size_t s = 0;
while (1)
{
z++;
write(1, "$ ", sizeof("$ ") - 1);
rd = zd_getline(&lineptr, &s, stdin);
if (rd == -1)
{
write(1, "\n", 1);
break;
}
command_copy = zdhandle_new_line(lineptr);
ptr = get_total_path(command_copy);
if (zd_strcmp(command_copy, "\n") == 0 || command_copy[0] == '#')
continue;
else if (zd_builtin_command(argv[0], command_copy, &stat, z, lineptr) != -1)
{
free(ptr);
continue;
}
else if (ptr != NULL)
{
command_argv = zd_argv(command_copy);
i = zd_excut(ptr, command_argv, environ, &stat);

if (i == 0)
zd_print_errors(argv[0], z, stat, command_copy);
}
else if (ptr == NULL)
{
zdexcute_notFound(command_copy, command_argv, environ, &stat);
zd_print_errors(argv[0], z, stat, command_copy);
}
free(ptr);
}
free(lineptr);
}
