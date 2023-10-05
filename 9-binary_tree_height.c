#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: root of the tree to measure
 * Return: height of the tree, 0 if the tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t hlf = 0, hrg = 0;

	if (!tree)
		return (0);

	if (tree->left)
		hlf = 1 + binary_tree_height(tree->left);
	if (tree->right)
		hrg = 1 + binary_tree_height(tree->right);

	if (hlf > hrg)
		return (hlf);
	return (hrg);
}
