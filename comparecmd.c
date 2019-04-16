#include "header.h"
/**
 * comparecmd - Compare path
 * @str: Strings
 * @envp: Env Vars
 * Return: Path
**/
char *comparecmd(char *str, char *envp[])
{
	char delim1[] = ":", delim2[] = "=", nmpath[] = "PATH";
	char *envpath = NULL, *listpaths = NULL, *conct2 = NULL;
	int i;
	char *strtmp, *envtmp1 = NULL;
	struct stat buf;

	if (str == NULL)
	{}
	strtmp = str_concat("/", str);
	for (i = 0; envp[i] != NULL; i++)
	{
		envtmp1 = _strdup(envp[i]);
		envpath = strtok(envtmp1, delim2);
		while (envpath != NULL)
		{
			if (_strcmp(envpath, nmpath) == 0)
			{
				envpath = strtok(NULL, delim2);
				listpaths = strtok(envpath, delim1);
				while (listpaths != NULL)
				{
					conct2 = str_concat(listpaths, strtmp);
					if (stat(conct2, &buf) == 0)
					{
						return (conct2);
					}
					listpaths = strtok(NULL, delim1);
					free(conct2);
				}
			}
			envpath = strtok(NULL, delim2);
		}
		free(envtmp1);
	}
	if (stat(str, &buf) == 0)
	{ free(strtmp);
		return (str); }
	free(strtmp);
	return (str);
}
