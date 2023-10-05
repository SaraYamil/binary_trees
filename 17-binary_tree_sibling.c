#include "binary_trees.h"

/**
 * binary_tree_sibling - finds the sibling of a given node in a binary tree
 * @node: node to find the sibling of
 * Return: pointer to the sibling node, or NULL if none or if node is NULL
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *parent;

	if (!node || !node->parent)
		return (NULL);

	parent = node->parent;
	if (node == parent->left)
		return (parent->right);

	return (parent->left);
}
