#include <stdlib.h>
#include <stdio.h>
/**
 * size_string - Array
 * @str: Size of array
 * Return: Size string
**/
int size_string(char *str)
{
int i;

if (str == NULL)
	return (0);
for (i = 0; str[i] != '\0'; i++)
;
return (i);
}
/**
 * *str_concat - Array
 * @s1: Pointer string
 * @s2: Content of array
 * Return: Null if size == 0, or Address of pointer if size > 0
**/
char *str_concat(char *s1, char *s2)
{
int i, ii, size1, size2, sizec;
char *p;

size1 = size_string(s1);
size2 = size_string(s2);
sizec = size1 + size2;
p = malloc(sizeof(char) * sizec + 1);
if (p == NULL)
	return (NULL);
for (i = 0; i < size1; i++)
	p[i] = s1[i];
for (ii = 0; ii < size2; i++, ii++)
	p[i] = s2[ii];
p[sizec] = '\0';
/*printf("asignacion MEM str_concat: %p entry1:%s entry2:%s\n", &p, s1, s2);*/
return (p);
}
