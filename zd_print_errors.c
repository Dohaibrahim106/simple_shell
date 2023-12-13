#include "main.h"
/**
 * zd_print_errors - Function that print error
 *
 * @prog_name: name of program
 * @counter: number of commands
 * @stat: Status of process
 * @lineptr: command from user
 *
 * Return: void.
*/
void zd_print_errors(char *prog_name, int counter, int stat, char *lineptr)
{
char *num;

num = zdprint_num(counter);
if (stat == 126)
zd_path_errors(prog_name, num, lineptr);
if (stat == 127)
zd_command_error(prog_name, num, lineptr);
if (stat == 2 && (strncmp(lineptr, "exit", 4) == 0))
zd_exit_error(prog_name, num, lineptr);
free(num);
}

/**
 * zd_path_errors - Function prints path error
 *
 * @prog_name: name of program
 * @counter: number of commands
 * @lineptr: command from user
 *
 * Return: void
*/
void zd_path_errors(char *prog_name, char *counter, char *lineptr)
{
write(2, prog_name, zd_strlen(prog_name));
write(2, ": ", 2);
write(2, counter, strlen(counter));
write(2, ": ", 2);
write(2, lineptr, (int)strlen(lineptr));
write(2, ": ", 2);
write(2, "Permission denied", sizeof("Permission denied") - 1);
write(2, "\n", 1);
}

/**
 * zd_command_error - Function prints errors
 *
 * @prog_name: name of program
 * @counter: number of commands
 * @lineptr: command from user
 * Return: void
*/
void zd_command_error(char *prog_name, char *counter, char *lineptr)
{
write(2, prog_name, zd_strlen(prog_name));
write(2, ": ", 2);
write(2, counter, strlen(counter));
write(2, ": ", 2);
write(2, lineptr, (int)strlen(lineptr));
write(2, ": ", 2);
write(2, "not found", sizeof("not found") - 1);
write(2, "\n", 1);
}

/**
 * zd_exit_error - Function prints errors
 *
 * @prog_name: name of program
 * @counter: number of commands
 * @lineptr: command from user
 * Return: void
*/
void zd_exit_error(char *prog_name, char *counter, char *lineptr)
{

char *token;
strtok(lineptr, _DELIMITER);
write(2, prog_name, zd_strlen(prog_name));
write(2, ": ", 2);
write(2, counter, strlen(counter));
write(2, ": ", 2);
write(2, lineptr, (int)strlen(lineptr));
write(2, ": ", 2);
write(2, "Illegal number", sizeof("Illegal number:") - 1);
write(2, ": ", 2);
token = strtok(NULL, _DELIMITER);
write(2, token, (int)strlen(token));
write(2, "\n", 1);
}

/**
 * zdprint_num - function return number of string
 * @num: parameter an integer
 * Return: pointer to number chararcter of string
 */

char *zdprint_num(int num)
{
unsigned int id;
unsigned int x;

int len = 0;
int j = 0;

char *counter;

id = num;
x = 1;

while (id > 9)
{
id /= 10;
x *= 10;
len++;
}
len++;
counter = (char *)malloc(len + 1);
if (counter == NULL)
return (NULL);
for (; x >= 1; x /= 10)
{
counter[j++] = ((num / x) % 10) + '0';
}
counter[len] = '\0';
return (counter);
}
