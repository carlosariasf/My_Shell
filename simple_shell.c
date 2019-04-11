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
*
*
**/
int main(__attribute__((unused))int ac, char **av)
{
    loop(av);

    return 0;
}
