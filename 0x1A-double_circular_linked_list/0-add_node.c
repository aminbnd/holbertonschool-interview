#include "list.h"
/**
 * Create a node object - creates a node in a linked list
 *
 * @str: data contained in the node
 * Return: pointer to the created node
 */

List *create_node(char *str)
{
	List *new_node = NULL;

	new_node = malloc(sizeof(List));
	if (!new_node)
		return (NULL);
	new_node->str = strdup(str);
	new_node->next = NULL;
	new_node->prev = NULL;
	if (!new_node->str)
		return (NULL);
	return (new_node);
}

/**
 * add_node_end - adds node at the end of linked list
 *
 * @list: the linked list to add the node to
 * @str: data contained in the node (string)
 * Return: pointer to the added node
 */

List *add_node_end(List **list, char *str)
{
	List *last, *new;

	if (!str)
		return (NULL);
	new = create_node(str);
	if (new == NULL)
		return (NULL);
	if (!list || !(*list))
	{
		*list = new;
		(*list)->prev = new;
		(*list)->next = new;
		return (new);
	}
	last = (*list)->prev;

	new->next = *list;
	(*list)->prev = new;
	last->next = new;
	new->prev = last;

	return (new);
}

/**
 * add_node_begin - adds a node at the start of linked list
 *
 * @list: the list to add the node to
 * @str: the data contained in the node (string)
 * Return: the added node
 */
List *add_node_begin(List **list, char *str)
{
	List *new;

	new = add_node_end(list, str);
	(*list) = new;
	return (new);
}
