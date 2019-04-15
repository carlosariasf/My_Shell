#include "header.h"
/**
 * my_exit - Terminate the shell
 * @buf: Pointer to buffer
 * @a: Arguments
**/
void my_exit(char *buf, char **a)
{
	int es;

	if (a[1] != NULL)
	{
		es = _atoi(a[1]);
		free(buf);
		_exit(es);
	}
	else
	{
		free(buf);
		exit(0);
	}
}
