#include "sort.h"

/**
 * insertion_sort_list - algorithm that sorts through a list
 * @list: list to sort
 * 
 * Return: nothing
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *node, *tmp, *tmp_next, *tmp_prev, *next;
	int i = 0;

	if (list == NULL || (*list)->next == NULL)
		return;
	node = *list;
	node = node->next;
	while (node != NULL)
	{
		tmp = node;
		next = node->next;
		tmp_next = tmp->next;
		tmp_prev = tmp->prev;

		while (tmp->prev != NULL && tmp_prev->n > tmp->n)
		{
			if (tmp_next != NULL)
				tmp_next->prev = tmp_prev;
			tmp_prev->next = tmp_next;
			if (tmp_prev->prev == NULL)
			{
				tmp_prev->prev = tmp;
				*list = tmp;
				tmp->prev = NULL;
			}
			else
			{
				tmp->prev = tmp_prev->prev;
				tmp_prev->prev->next = tmp;
				tmp_prev->prev = tmp;
			}
			tmp->next = tmp_prev;
			tmp_prev = tmp->prev;
			tmp_next = tmp->next;
			print_list(*list);
		}
		node = next;
		i++;
	}
