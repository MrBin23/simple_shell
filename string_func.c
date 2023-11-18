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

	len1 = _stringlenght(str1);
	len2 = _stringlenght(str2);
	new_str = malloc(sizeof(char) * (len1 + len2 + 1));
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
		new_str[rator] = str2[rator - len1];
		rator++;
	}
	new_str[rator] = 0;
	return (new_str);
}

/**
 * _strdup - duplicates a string
 * @str: string to duplicate
 * Return: duplicated string
 */
char *_strdup(const char *str)
{
	size_t length, rator;
	char *new_str;

	length = _stringlenght(str);
	new_str = malloc(sizeof(char) * (length + 1));
	if (new_str == NULL)
		return (NULL);
	new_str[length] = 0;
	rator = 0;

	while (rator < length)
	{
		new_str[rator] = str[rator];
		rator++;
	}
	return (new_str);
}

/**
 * str_slice - creates a new string slice from the specified input string
 * @lines: line to be sliced
 * @start: starting index of sli
 * @end: end index of sli
 * Return: dynamically allocated string slice
 */
char *str_slice(const char *lines, int start, int end)
{
	int length, rator;
	char *sli;

	if (start < 0)
		start = 0;
	length = _stringlenght(lines);
	if (length < end || end < 0)
		end = length;
	sli = malloc(sizeof(char) * (end - start + 1));
	rator = 0;

	while (start + rator < end)
	{
		sli[rator] = lines[start + rator];
		rator++;
	}
	sli[rator] = 0;
	return (sli);
}
