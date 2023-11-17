#include "shell.h"
/**
 * clear_entry - frees memory asociated with entry in data structure
 *
 * @datas: pointer to entry to be cleared
 * Return: Nothing
 */
void clear_entry(void *datas)
{
	enter_t *my_entry;

	my_entry = datas;
	free(my_entry->key);
	free(my_entry->value);
	free(datas);
}
