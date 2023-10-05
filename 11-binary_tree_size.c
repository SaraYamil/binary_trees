#include "binary_trees.h"

/**
 * binary_tree_size - measures the size (number of nodes) of a binary tree
 * @tree: root of the tree to measure
 * Return: size of the tree, 0 if the tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t i = 1;

	if (!tree)
		return (0);

	i += binary_tree_size(tree->left);
	i += binary_tree_size(tree->right);

	return (i);
}
