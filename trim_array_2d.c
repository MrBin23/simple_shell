#include "shell.h"
/**
 * count_string - counts number of non empty string
 * @str: conains number of non empty string
 * Return: number of string not empty
 */
int count_string(char **str)
{
	int length;

	length = 0;
	while (*str)
	{
		length = length + (**str != '\0');
		str++;
	}
	return (length);
}

/**
 * trim_array_2d - trims an array of string, and returns an empty string
 * @str: input array of string
 * return: dynamically allocated array of string with removed empty string
 */
char **trim_array_2d(char **str)
{
	char **new_str;
	int length;

	length = count_string(str);
	new_str = malloc(sizeof(char *) * (length + 1));
	if (new_str == NULL)
		return (NULL);
	new_str[length] = NULL;

	length = 0;
	while (*str)
	{
		if (**str)
		{
			new_str[len] = _strdup(*str);
			length++;
		}
		str++;
	}
	return (new_str);

}
