#include "shell.h"
/**
 * free_split - frees allocted memory to bucket
 *
 *@backs: what will be freed
 *Return: void
 */
void free_split(char ***backs)
{
	char **head;

	head = *backs;
	while (*head)
	{
		free(*head);
		head++;
	}
	free(*backs);
	*backs = NULL;
}
