#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include "header.h"

char *comparecmd(char *str, char * envp[])
{
	char delim1[] = ":";
	char delim2[] = "=";
	char nmpath[] = "PATH";
	char *envpath = NULL;
	char *listpaths = NULL;
	char *conct2 = NULL;
	int i;
	struct stat buf;
	/*conct = str_concat(binnm,str);
	  printf("(%s)\n",conct);*/
	if(stat(str,&buf) == 0)
	{
		printf("found, returning same.\n");
		return str;
	}
	str = str_concat("/",str);
	    for (i = 0; envp[i] != NULL; i++)
	    {
		    envpath = strtok( envp[i], delim2 );
		    while( envpath != NULL ) {
			    if(_strcmp(envpath,nmpath) == 0)
			    {
				    envpath = strtok( NULL, delim2);
				    listpaths = strtok( envpath, delim1);
				    while( listpaths != NULL ) {
					    /*str = str_concat("/",str);*/
					    conct2 = str_concat(listpaths,str);
					    if(stat(conct2,&buf) == 0)
					    {
						    /*printf("FOUND in builints :%s\n", conct2);*/
						    return conct2;
					    }
					    printf("%s\n", listpaths);
					    listpaths = strtok( NULL, delim1);
				    }
				    break;
			    }
			    envpath = strtok( NULL, delim2);
		    }
	    }
	    return (NULL);
}
