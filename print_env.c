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
 * print_env - print env vars
 * @envp: array var env.
 * Return : Void
 **/
void print_env(char *envp[])
{
	int i;
	int lenght;

	for (i = 0; envp[i] != NULL; i++)
	{
		lenght = _strlen(envp[i]);
		write(1, envp[i], lenght);
		write(1, "\n", 1);
	}
}
