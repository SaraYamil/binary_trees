#include "binary_trees.h"

int btic_helper(const binary_tree_t *tree, size_t index, size_t size);
size_t binary_tree_size(const binary_tree_t *tree);

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: A pointer to the root node of the binary tree.
 *
 * Return: 1 if the tree is complete, 0 otherwise or if the tree is NULL.
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t tree_size;

	if (!tree)
		return (0);
	tree_size = binary_tree_size(tree);

	return (btic_helper(tree, 0, tree_size));
}

/**
 * binary_tree_size - Calculates the size of a binary tree.
 * @tree: A pointer to the root node of the binary tree.
 *
 * Return: Size of the binary tree.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) +
		binary_tree_size(tree->right) + 1);
}

/**
 * btic_helper - Checks if a binary tree is complete.
 * @tree: A pointer to the node being checked during recursion.
 * @index: Current index of the node being checked.
 * @size: Total size of the binary tree.
 *
 * Return: 1 if the subtree is complete, 0 otherwise.
 */
int btic_helper(const binary_tree_t *tree, size_t index, size_t size)
{
	if (!tree)
		return (1);

	if (index >= size)
		return (0);

	return (btic_helper(tree->left, 2 * index + 1, size) &&
		btic_helper(tree->right, 2 * index + 2, size));
}
