#include "shell.h"
/**
 * _clear_map - frees the allocated memory
 *
 *@mapp: Allocated memory to be freed
 *Return: Success
 */
void map_clear(map_t *mapp)
{
	int iterates;

	iterates = 0;
	while (iterates < BACKET_SIZE)
	{
		free_list(mapp->bakets[iterates], _clear_entry);
		iterates++;
	}
	free(mapp);
}
