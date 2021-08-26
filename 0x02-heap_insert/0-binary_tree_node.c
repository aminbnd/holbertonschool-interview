#include "binary_trees.h"
#include<stdio.h>
/**
 * binary_tree_node - Adds a new node to a binary tree
 * @parent: parent of the created node
 * @value: int: the data of the node
 * Return: pointer to the created node
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	
	binary_tree_t *node;
	
	/* Save space in memory */
	node = malloc (sizeof(binary_tree_t));
	
	/* Error case */
	if(!node)
		return (0);
	
	/* Create new node */
	node->parent = parent;
	node->n = value;
	
	/* Return */
	return (node);
}