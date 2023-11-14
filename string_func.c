#include "shell.h"
/**
 * _strcat - concatenates 2 strings
 * @str1: first string to cat
 * @str2: second string to cat
 * Return: concatenated string
 */
char *_strcat(const char *str1, const char *str2)
{
	size_t len1, len2, rator;
	char *new_str;

	len1 = _strlen(str1);
	len2 = _strlen(str2);
	new_str = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (new_str == NULL)
		return (NULL);
	rator = 0;
	while (rator < len1)
	{
		new_str[rator] = str1[rator];
		rator++;
	}
	while (rator - len1 < len2)
	{
		new_str[rator] = str2[rator - len2];
		rator++;
	}
	new_str[rator] = 0;
	return (new_str);
}

/**
 */

