#include "header.h"
/**
 *getpath - Get path
 *@param: string to copy.
 *@envp: dest.
 *Return: char.
 */
char *getpath(char param[], char *envp[])
{
	char delim2[] = "=", *envpath = NULL, *envtmp = NULL;
	int i;

	for (i = 0; envp[i] != NULL; i++)
	{
		envtmp = _strdup(envp[i]);
		envpath = strtok(envtmp, delim2);
		while (envpath != NULL)
		{
			if (_strcmp(envpath, param) == 0)
			{
				envpath = strtok(NULL, delim2);
				free(envtmp);
				return (envpath);
			}
			envpath = strtok(NULL, delim2);
		}
		free(envtmp);
	}
	return (NULL);
}
