#include "main.h"

/**
 * zd_getenv - Function that get the value of the variable
 *
 * @nameptr: pointer to variable name
 *
 * Return: return pointer
 *
*/

char *zd_getenv(char *nameptr)
{
	int len_name;
	char **envi;

	if (nameptr == NULL || nameptr[0] == '\0')
		return (NULL);
	len_name = (int)strlen(nameptr);

	for (envi = environ; *envi != NULL; envi++)
	{
		if (strncmp(*envi, nameptr, len_name) == 0 && (*envi)[len_name] == '=')
			return (*envi + len_name + 1);
	}
	return (NULL);
}
