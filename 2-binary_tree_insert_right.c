#include "binary_trees.h"

/**
 * binary_tree_insert_right - inserts a new node as the right child of a parent
 *                            node
 * @parent: pointer to the parent node
 * @value: value to be stored in the new node
 *
 * Return: pointer to the new right child node, or NULL on failure
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_binary_tree;

	if (!parent)
	{
		return (NULL);
	}

	new_binary_tree = malloc(sizeof(binary_tree_t));
	if (!new_binary_tree)
	{
		return (NULL);
	}

	new_binary_tree->n = value;
	new_binary_tree->parent = parent;
	new_binary_tree->left = NULL;
	new_binary_tree->right = parent->right;
	parent->right = new_binary_tree;

	if (new_binary_tree->right)
	{
		new_binary_tree->right->parent = new_binary_tree;
	}

	return (new_binary_tree);
}
