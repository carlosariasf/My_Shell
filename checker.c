#include "header.h"
/**
 * checker - Main fuction
 * @buf: pointer
 * @proname: Prog
 * @envp: Env Vars
 * @a: args pointer
 * Return : Void
**/
void checker(char *buf, const char *proname, char *envp[], char **a)
{
	char *pathexc;
	int status;
	pid_t child, tpid;

	if (!_strcmp(a[0], "exit"))
		my_exit(buf, a);
	else if (!_strcmp(a[0], "cd"))
		_cd(a, envp), free(buf);
	else if (!_strcmp(a[0], "env") && a[1] == NULL)
		print_env(envp), free(buf);
	else
	{
		child = fork();
		if (child == 0)
		{
			pathexc = comparecmd(a[0], envp);
			if (execve(pathexc, a, NULL) == -1)
			{
				perror(proname);
				free(buf);
			}
			exit(0);
		}
		else
		{
			do {
				tpid = wait(&status);
			} while (tpid != child);
		}
		free(buf);
	}
}
