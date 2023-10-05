#include "binary_trees.h"

/**
 * binary_tree_insert_left - inserts a new left node
 * @parent: parent node
 * @value: value for the new node
 * Return: address of the new node, or NULL if it fails
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	if (parent == NULL)
		return (NULL);

	new = binary_tree_node(parent, value);
	if (new == NULL)
		return (NULL);

	if (parent->left != NULL)
	{
		new->left = parent->left;
		parent->left->parent = new;
	}
	parent->left = new;

	return (new);
}
