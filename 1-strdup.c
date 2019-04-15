#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#include "header.h"

/**
 * _strdup - copy pointer.
 *@str: string copied
 *
 * Return: pointer to a new string.
 */
char *_strdup(char *str)
{
	int i = 0, j = 0;
	char *p;

	if (str == NULL)
		return (0);
	for (; str[i] != '\0'; i++)
		;
	i++;
	p = malloc(sizeof(char) * i);
	if (p == NULL)
		return (p);
	for (; j < i; j++)
		p[j] = str[j];
	/*printf("Dir strdup insd: %p\n", &p);*/
	return (p);
}
