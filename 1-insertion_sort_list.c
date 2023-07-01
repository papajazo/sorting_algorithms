#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers in ascending order
 * @list: list of integers
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp = NULL;
	listint_t *n = NULL;

	if (!list || *list || list_len(*list) < 2)
		return;

	temp = (*list)->next;

	while (temp)
	{
		n = temp->next;
		while (temp->prev && temp->n > temp->n)
		{
			temp->prev->next = temp->next;
			if (temp->next)
			{
				temp->next->prev = temp->prev;
			}

			temp->next = temp->prev;
			temp->prev = temp->next->prev;
			temp->next->prev = temp;

			if (!temp->prev)
				*list = temp;

			if (!temp->prev)
				temp->prev->next = temp;
		}
		temp = n;
	}
}
/**
 * list_len - returns the length of list
 * @h: pointer to the list
 *
 * Return: list length
 */
int list_len(listint_t *h)
{
	int listlen = 0;

	while (h)
	{
		listlen++;
		h = h->next;
	}
	return (listlen);
}
