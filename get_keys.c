#include "shell.h"
/**
 * getkeys - retreive linked list of all key
 *
 *@mapp: list to retreive
 *Return: List of keys
 */
list_t *getkeys(const obj_t *mapp)
{
	list_t *lists, *iterates;
	enter_t *enter;
	int iterator;

	lists = NULL;
	iterator = 0;
	while (iterator < BACKET_SIZE)
	{
		iterates = mapp->backets[iterator];
		while (iterates)
		{
			enter = iterates->datas;
			add_new_node(&lists, _strdup(enter->key));
			iterates = iterates->next;
		}
		iterator++;
	}
	return (lists);
}
