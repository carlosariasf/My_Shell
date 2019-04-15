#include "header.h"
/**
 * _cd - Open directory
 * @a: Args
 * @envp: Env Var
**/
void _cd(char **a, char *envp[])
{
	if (a[1] != NULL && _strcmp(a[1], "-"))
	{
	chdir(a[1]);
	}
	else if (a[1] == NULL)
	{
	chdir(getpath("HOME", envp));
	}
	else if (!_strcmp(a[1], "-"))
	{
		chdir(getpath("OLDPWD", envp));
	}
}
