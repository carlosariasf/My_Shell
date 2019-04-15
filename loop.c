#include "header.h"
/**
 * loop - Loop fuction
 * @a: arg pointer
 * @envp: Environment Variables
 * Return : Void
**/
void loop(char **a, char *envp[])
{
	char *buffer, *token, *argumts[1024], delimit[] = " \t\r\n\v\f";
	size_t bufsize = 32;
	const char *proname = a[0];
	int countargt = 1;

	signal(SIGINT, SIG_IGN);
	while (stdin)
	{
		buffer = (char *)malloc(bufsize * sizeof(char));
		if (buffer == NULL)
		{
			perror("Unable to allocate buffer");
			exit(1);
		}
		countargt = 1;
		if (isatty(0))
			printf("$ ");
		if (getline(&buffer, &bufsize, stdin) != EOF)
		{
			token = strtok(buffer, delimit);
			argumts[0] = token;
			if (!token)
			{
				free(buffer);
				continue;
			}
			while (token != NULL)
			{
				token = strtok(NULL, delimit);
				argumts[countargt] = token;
				countargt++;
			}
			checker(buffer, proname, envp, argumts);
		}
		else
		{
			free(buffer);
			break;
		}
	}
}
