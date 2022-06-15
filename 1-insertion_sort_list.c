#include "sort.h"

/**
 * check_before - recursive function that swaps nodes.
 * @b: pointer to the node to be swap.
 * @list: pointer to the head of the double linked list.
 *
 * Return: nothing.
 */
void check_before(listint_t *b, listint_t **list)
{
	listint_t *c = b->prev;

	if (c == NULL)
		return;
	if (b->n < c->n)
	{
		c->next = b->next;
		if (c->next != NULL)
			c->next->prev = c;
		b->prev = c->prev;
		c->prev = b;
		b->next = c;
		if (b->prev != NULL)
			b->prev->next = b;
		if ((*list)->prev != NULL)
			*list = (*list)->prev;
		print_list(*list);
		check_before(b, list);
	}
}

/**
 * insertion_sort_list - sorts a doubly linked list
 * of integers in ascending order using the
 * Insertion sort algorithm.
 *
 * @list: pointer to the head of the double linked list.
 *
 * Return: nothing.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *p = NULL;

	if (*list == NULL)
		return;

	/* start checking from second node */
	p = (*list)->next;
	while (p != NULL)
	{
		if (p->prev->n > p->n)
			check_before(p, list);
		p = p->next;
	}
}
