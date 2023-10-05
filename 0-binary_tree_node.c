#include "binary_trees.h"

/**
 * binary_tree_node - creates a new binary tree node
 * @parent: pointer to the parent node
 * @value: value to be stored in the new node
 *
 * Return: pointer to the new node, or NULL if memory allocation fails
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_binary_tree = malloc(sizeof(binary_tree_t));

	if (!new_binary_tree)
	{
		return (NULL);
	}

	new_binary_tree->n = value;
	new_binary_tree->parent = parent;
	new_binary_tree->left = NULL;
	new_binary_tree->right = NULL;

	return (new_binary_tree);
}
