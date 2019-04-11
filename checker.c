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
 * checker - Main fuction
 * @buffer: pointer
 * @proname: Prog
 * @path: Url
 * @a: args pointer
 * Return : Void
**/
void checker(char *buffer, const char *proname, char *path, char **a)
{
        char *pathexc;
        int status;
        pid_t child, tpid;

        if (!_strcmp(a[0], "exit"))
                a[1] != NULL ? free(buffer), _exit(_atoi(a[1])): free(buffer), _exit(0);
        else if (!_strcmp(a[0], "cd"))
                a[1] != NULL ? chdir(a[1]): chdir("~"), free(buffer);
        else
        {
                child = fork();
                if (child == 0)
                {
                        pathexc = str_concat(path, a[0]);
                        if (execve(pathexc,a,NULL) == -1)
                        {
                                perror(proname);
                                free(buffer);
                        }
                        exit(0);
                }
                else
                {
                        do {
                        tpid = wait(&status);
                        } while(tpid != child);
                }
        free(buffer);
        }
}
