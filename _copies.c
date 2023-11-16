#include "shell.h"
/**
 * _copies -function copies data to destination
 *
 *@dest: Buffer in which the data/character will be
 *@source: Source of characters
 *@size: Lenght of data
 *Return: Destination
 */
char *_copies(char *dest, const char *source, size_t size)
{
	size_t iterates;

	iterates = 0;
	while (iterates < size)
	{
		dest[iterates] = source[iterates];
		iterates++;
	}
	dest[iterates] = 0;
	return (dest);
}
/**
 *_environmt - builtin function that print variables
 *
 *@commd: Contains info bout commands
 *Return: 0 success or error
 */
int _environmt(cmd_t *commd)
{
	char **iterates;
	(void)commd;

	iterates = __environ;
	if (!iterates)
	{
		return (1);
	}
	while (*iterates)
	{
		_fprint(1, "%s\n", *iterates);
		iterates++;
	}
	return (0);
}
