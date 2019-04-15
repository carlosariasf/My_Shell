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
	char *envtmp = NULL;

	for (i = 0; envp[i] != NULL; i++)
	{
		envtmp = _strdup(envp[i]);
		envpath = strtok(envtmp, delim2);
		while(envpath != NULL) {
			if(_strcmp(envpath,param) == 0)
			{
				/*printf("ENCONTRo otro =\n");*/
				envpath = strtok(NULL, delim2);
				/*printf("Dir a lib FOUND! strdup: %p\n", &envtmp);*/
				free(envtmp);
				return(envpath);
			}
			envpath = strtok( NULL, delim2);
		}
		/*printf("Dir a lib strdup: %p\n", &envtmp);*/
		free(envtmp);
	}
	/*free(envtmp);*/
	return(NULL);
}
