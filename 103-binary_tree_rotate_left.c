#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs a left rotation on a binary tree
 * @tree: pointer to the root node of the tree to be rotated
 *
 * Return: pointer to the new root node after rotation, or NULL if invalid
 *         input
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *temporary = NULL, *parent_tree;

	if (!tree || !tree->right)
	{
		return (NULL);
	}
	temporary = tree;
	parent_tree = tree->parent;
	tree = tree->right;
	tree->parent = NULL;
	if (tree->left)
	{
		temporary->right = tree->left;
		tree->left->parent = temporary;
	}
	else
	{
		temporary->right = NULL;
	}
	temporary->parent = tree;
	tree->left = temporary;
	if (parent_tree)
	{
		parent_tree->right = tree;
	}
	tree->parent = parent_tree;

	return (tree);
}
