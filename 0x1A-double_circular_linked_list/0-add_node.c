#include "list.h"

/**
 * createNode - Creates new Node
 *
 * @string: Data contained in the node
 * Return: the created node (of type List)
 */

List *createNode(char *string)
{
	List *newNode = NULL;

	newNode = malloc(sizeof(List));
	if (!newNode)
		return (NULL);
	newNode->str = strdup(string);
	newNode->next = NULL;
	newNode->prev = NULL;
	if (!newNode->str)
		return (NULL);
	return (newNode);
}

/**
 * add_node_end - adds a node at the end of a linked list
 *
 * @list: the list to edit
 * @str: the data contained in the node (string)
 * Return: the new added node
 */

List *add_node_end(List **list, char *str)
{
	List *last_node, *new_node;

	if (!str)
		return (NULL);
	new_node = createNode(str);
	if (new_node == NULL)
		return (NULL);
	if (!list || !(*list))
	{
		*list = new_node;
		(*list)->prev = new_node;
		(*list)->next = new_node;
		return (new_node);
	}
	last_node = (*list)->prev;

	new_node->next = *list;
	(*list)->prev = new_node;
	last_node->next = new_node;
	new_node->prev = last_node;

	return (new_node);
}

/**
 * add_node_begin - adds a node at the begining of a linked List
 *
 * @list: the linked list to edit
 * @str: data contained in the node to add (string)
 * Return: the added node
 */

List *add_node_begin(List **list, char *str)
{
	List *new_node;

	new_node = add_node_end(list, str);
	(*list) = new_node;
	return (new_node);
}
