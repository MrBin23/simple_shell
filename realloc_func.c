#include "shell.h"
/**
 * _realloc - increases the size of buffer
 * @prev_buff: pointer to the previous buffer
 * @prev_size:m size of previous buffer
 * @new_size: size of buffer after reallocation
 * Return: buffer after reallocation
 */
void *_realloc(void *prev_buff, size_t prev_size, size_t new_size)
{
	unsigned char *buff, *str_buff;
	size_t rator;

	buff = malloc(sizeof(unsigned char) * (new_size + 1));
	if (!buff)
		return (NULL);
	str_buff = prev_buff;
	rator = 0;

	while (str_buff && rator < prev_size)
	{
		buff[rator] = str_buff[rator];
		rator++;
	}
	while (rator < new_size)
	{
		buff[rator] = 0;
		rator++;
	}
	buff[rator] = 0;
	free[prev_buff];
	return (buff);
}
