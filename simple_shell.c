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
* main - Main fuction
*@ac: argmt counter.
*@av: argumt vector.
*@envp: enviroment vars.
*Return: 0.
**/
int main(__attribute__((unused))int ac, char **av, char *envp[])
{
	loop(av, envp);
	return (0);
}
