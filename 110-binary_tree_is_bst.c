#include "binary_trees.h"

int btib_helper(const binary_tree_t *tree, int min, int max);

/**
 * binary_tree_is_bst - checks if a binary tree is a binary search tree (BST)
 * @tree: pointer to the root node of the tree
 *
 * Return: 1 if the tree is a BST, 0 otherwise or if the tree is NULL
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
	{
		return (0);
	}

	return (btib_helper(tree, INT_MIN, INT_MAX));
}

/**
 * btib_helper - helper function to check if a binary tree is a BST
 * @tree: pointer to the node being checked
 * @min: minimum value allowed for nodes in the subtree
 * @max: maximum value allowed for nodes in the subtree
 *
 * Return: 1 if the subtree is a BST, 0 otherwise
 */
int btib_helper(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
	{
		return (1);
	}

	if (tree->n < min || tree->n > max)
	{
		return (0);
	}

	return (btib_helper(tree->left, min, tree->n - 1) &&
		btib_helper(tree->right, tree->n + 1, max));
}
