#ifndef SHELLHEAD
#define SHELLHEAD
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
void checker(char *buf, const char *proname, char *envp[], char **a);
void loop(char **a, char *envp[]);
char *str_concat(char *s1, char *s2);
int _strcmp(char *s1, char *s2);
int _atoi(char *str);
char *comparecmd(char *str, char *envp[]);
void print_env(char *envp[]);
char *getpath(char param[], char *envp[]);
void _cd(char **a, char *envp[]);
void my_exit(char *buf, char **a);
char *_strdup(char *str);
#endif
