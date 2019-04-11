#include <stdio.h>
/**
 * *_strcmp - reset
 *
 * @s1: char
 * @s2: char
 *
 * Return: int return the size of the char.
**/
int _strcmp(char *s1, char *s2)
{
int s, ss, sss, count, fin = 0;

for (ss = 0; s1[ss] != '\0'; ss++)
;
for (sss = 0; s2[sss] != '\0'; sss++)
;
for (s = 0; s1[s] != '\0' && s2[s] != '\0'; s++)
{
	count = s2[s] - s1[s];
	count = count <= 0 ? count * -1 : count * 1;
	if (count > fin)
	{
	fin = count;
	}
}
fin = ss > sss ? fin * -1 : fin * 1;

return (fin);
}
