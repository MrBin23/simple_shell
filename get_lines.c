#include "shell.h"
/**
 *search_nextnewline - function will search for newline
 *
 * @buff: Buffer to save character
 * @lenght: The lenght of buffer
 * Return: Read char or -1
 */
size_t search_nextnewline(char *buff, size_t lenght)
{
	size_t pos;

	pos = 0;
	while (pos < lenght && buff[pos] != '\n')
		pos++;
	return (pos);
}
/**
 * _getline - function gets the address of character
 *
 *@lines: Address of character line
 *Return: Read character
 */
size_t _getline(char **lines)
{
	static char buff[BUFF_SIZE];
	static ssize_t curr_pos;
	static ssize_t endof_buff;
	ssize_t oldsize;
	ssize_t nextnewline;

	*lines = NULL;
	oldsize = 0;
	while (1)
	{
		if (curr_pos >= endof_buff)
		{
			endof_buff = read(STDIN_FILENO, buff, BUFF_SIZE);
			curr_pos = 0;
			if (endof_buff < 0)
			{
				free(*lines);
				*lines = NULL;
				return (-1);
			}
			if (endof_buff == 0)
				return (oldsize);
		}
		nextnewline = search_nextnewline(buff + curr_pos, endof_buff - curr_pos);
		*lines = _realloc(*lines, oldsize, oldsize + nextnewline);
		if (!*lines)
			return (-1);
		_copies((*lines) + oldsize, buff + curr_pos, nextnewline);
		oldsize += nextnewline;
		curr_pos += nextnewline;
		if (curr_pos < endof_buff)
		{
			curr_pos++;
			return (oldsize);
		}
		curr_pos++;
	}
	return (-1);
}
