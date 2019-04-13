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
 *str_concat - concat strings
 *@s1: string to copy.
 *@s2: dest.
 *Return: char.
 */
char *getpath(char param[], char *envp[])
{
        char delim2[] = "=";
        char *envpath = NULL;
        int i;

	for (i = 0; envp[i] != NULL; i++)
	{
		envpath = strtok( envp[i], delim2 );
		while( envpath != NULL ) {
			if(_strcmp(envpath,param) == 0)
			{
				envpath = strtok( NULL, delim2);
				return(envpath);
			}
			envpath = strtok( NULL, delim2);
		}
	}
	return(NULL);
}
