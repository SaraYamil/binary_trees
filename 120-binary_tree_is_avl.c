#include "binary_trees.h"

size_t height(const binary_tree_t *tree);
int is_avl_helper(const binary_tree_t *tree, int lo, int hi);

/**
 * binary_tree_is_avl - checks if a binary tree is an AVL tree
 * @tree: pointer to the root node of the binary tree
 *
 * Return: 1 if the tree is an AVL tree, 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
	{
		return (0);
	}

	return (is_avl_helper(tree, INT_MIN, INT_MAX));
}

/**
 * height - calculates the height of a binary tree
 * @tree: pointer to the root node of the binary tree
 *
 * Return: height of the tree
 */
size_t height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t l = 0, r = 0;

		l = tree->left ? 1 + height(tree->left) : 1;
		r = tree->right ? 1 + height(tree->right) : 1;
		return ((l > r) ? l : r);
	}
	return (0);
}

/**
 * is_avl_helper - checks if a binary tree is an AVL tree within specified
 *		 range
 * @tree: pointer to the root node of the binary tree
 * @lo: minimum allowed value for nodes in the subtree
 * @hi: maximum allowed value for nodes in the subtree
 *
 * Return: 1 if the tree is an AVL tree, 0 otherwise
 */
int is_avl_helper(const binary_tree_t *tree, int lo, int hi)
{
	size_t left_gt, right_gt, difference;

	if (tree != NULL)
	{
		if (tree->n < lo || tree->n > hi)
		{
			return (0);
		}
		left_gt = height(tree->left);
		right_gt = height(tree->right);
		difference = left_gt > right_gt ? left_gt - right_gt : right_gt - left_gt;
		if (difference > 1)
		{
			return (0);
		}

		return (is_avl_helper(tree->left, lo, tree->n - 1) &&
			is_avl_helper(tree->right, tree->n + 1, hi));
	}

	return (1);
}
