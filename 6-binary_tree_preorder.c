#include "binary_trees.h"

/**
 * binary_tree_preorder - performs a preorder traversal on a binary tree
 * @tree: pointer to the root node of the tree
 * @func: pointer to a function to be applied to each node's value
 *
 * Return: void
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
	{
		return;
	}

	func(tree->n);

	binary_tree_preorder(tree->left, func);
	binary_tree_preorder(tree->right, func);
}
