#include "shell.h"
/**
 * handle_error_parsing - function runs line against parsing error
 *
 *@lines: to check against
 *Return: Number greater than 0 or 0
 */
int handle_error_parsing(char *lines)
{
	size_t lenght;

	if (!lines || !*lines)
		return (0);
	lenght = _stringlenght(lines);
	if (lines[0] == ';' || lines[0] == '|' || lines[lenght - 1] == '|' ||
		lines[lenght - 1] == '>' || lines[lenght - 1] == '<')
		return (2);
	lenght = 0;
	while (lines[lenght])
	{
		if (check_invalid_char_occur(lines + lenght))
				return (2);
			lenght++;
	}
	return (0);
}
/**
 * check_invalid_char_occur - function finds invalid characters
 *
 *@lines: Line to check for character that are not valid
 *Return: Invalid character or 0
 */
int check_invalid_char_occur(char *lines)
{
	size_t indx;
	size_t iterates;
	size_t iterates1;
	char *invalid_char[] = {";;", "|||", ">>>", "<<"};

	indx = 0;
	while (indx < 4)
	{
		iterates = 0;
		iterates1 = 0;
		while (lines[iterates1] && invalid_char[indx][iterates] &&
			(invalid_char[indx][iterates] == lines[iterates1] || lines[iterates1] == ' '))
		{
			if (lines[iterates1] == ' ')
				iterates1++;
			else
			{
				iterates1++;
				iterates++;
			}
		}
		if (!invalid_char[indx][iterates])
			return (1);
		indx++;
	}
	return (0);
}
