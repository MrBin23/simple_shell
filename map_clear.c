#include "shell.h"
/**
 * map_clear - frees the allocated memory
 *
 *@mapp: Allocated memory to be freed
 *Return: void
 */
void map_clear(obj_t *mapp)
{
	int iterates;

	iterates = 0;
	while (iterates < BACKET_SIZE)
	{
		_freelist(mapp->backets[iterates], clear_entry);
		iterates++;
	}
	free(mapp);
}
