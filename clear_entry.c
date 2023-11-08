#include "shell.h"
/**
 * claer_entry - frees memory asociated with entry in data structure
 * @data: pointer to entry to be cleared
 */
void clear_entry(void *data)
{
	enter_t *my_entry;

	my_entry = data;
	free(my_entry->key);
	free(my_entry->value);
	free(data);
}
