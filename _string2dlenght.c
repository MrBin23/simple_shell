#include "shell.h"
/**
 * _string2dlenght - fuction counts the lenght off array
 *
 *@array2d: counting array lenght
 *Return: The lenght of the given array
 */
int _string2dlenght(char **array2d)
{
	int lenght;

	lenght = 0;
	if (!array2d)
		return (0);
	while (array2d[lenght])
		lenght++;
	return (lenght);
}
/**
 * _stringcompare - function checks for isentical strings
 *
 * @string1: for string checked
 * @string2: second string checked
 *Return: Always success
 */
int _stringcompare(const char *string1, const char *string2)
{
	if (!string1 || !string2)
	{
		return (0);
	}
	while (*string1 && *string2 && *string1 == *string2)
	{
		string1++;
		string2++;
	}
	if (!*string1 && !*string2)
		return (1);
	return (0);
}
/**
 *_stringlenght - function checks lenght of string
 *
 *@string: String to check
 *Return: Always the number of strings
 */
size_t _stringlenght(const char *string)
{
	size_t lenght;

	lenght = 0;
	while (string && string[lenght])
		lenght++;
	return (lenght);
}
