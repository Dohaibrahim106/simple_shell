#include "main.h"

/**
 * zd_strlen - find the length of a string
 * @p: pointer to the string
 * Return: Function returns length of string
*/
int zd_strlen(char *p)
{
int l = 0;

while (*p != '\0')
{
l++;
p++;
}
return (l);
}

/**
 * zd_strcpy -  Function copies the string.
 * @dest: pointer to the destination array.
 * @src: pointer to source array.
 * Return: Function returns pointer to destination.
 */
char *zd_strcpy(char *dest, char *src)
{
int j = -1;

j++;
while (*(src + j) != '\0')
{
*(dest + j) = *(src + j);
j++;
}
*(dest + j) = '\0';
return (dest);
}

/**
 * zd_strcat - Function append source string to destination
 * @string1: pointer to the destination array.
 * @string2: pointer to source array.
 * Return: return void.
*/
void zd_strcat(char *string1, const char *string2)
{
size_t len1 = strlen(string1);
size_t i = 0;

while (string2[i])
{
string1[len1 + i] = string2[i];
i++;
}

string1[len1 + i] = '\0';
}

/**
* zd_strdup - function creates a copy of a string.
* @string: pointer to string that you want to duplicate
* Return: return pointer to a new string
*/
char *zd_strdup(char *string)
{
char *k;
unsigned int x;
unsigned int n;

if (string == NULL)
return (NULL);

n = strlen(string);

k = (char *)malloc(n + 1);

if (k == NULL)
return (NULL);

for (x = 0; x <= n; x++)
k[x] = string[x];

return (k);
}

/**
 * zd_strcmp -  function that compares two strings.
 * @string1: pointer to string
 * @string2: pointer to string
 * Return: function returns (0).
 */
int zd_strcmp(char *string1, char *string2)
{
int x = 0;
int res = 0;
int l1, l2;

l1 = (int)strlen(string1);
l2 = (int)strlen(string2);

if (l1 != l2)
return (-1);

for (x = 0; ((string1[x] != '\0') && (string2[x] != '\0')); x++)
{
res = (string1[x] - string2[x]);
if (res != 0)
{
return (res);
}
}
return (0);
}
