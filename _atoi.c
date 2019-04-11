/**
 * _atoi - Atoy fuction
 * @str: char to parse
 * Return: int 
**/
int _atoi(char *str)
{
int res = 0, i = 0;

for (i = 0; str[i] != '\0'; ++i)
res = res*10 + str[i] - '0';

return res; 
} 
