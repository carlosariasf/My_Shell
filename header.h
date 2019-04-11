#ifndef SHELLHEAD
#define SHELLHEAD
void checker(char *buffer, const char *proname, char *envp[], char **a);
void loop(char **a, char *envp[]);
char *str_concat(char *s1, char *s2);
int _strcmp(char *s1, char *s2);
int _atoi(char *str);
char *comparecmd(char *str, char *envp[]);
void print_env(char *envp[]);
#endif
