#include "binary_trees.h"

/**
 * binary_tree_postorder - performs a postorder traversal on a binary tree
 * @tree: pointer to the root node of the tree
 * @func: pointer to a function to be applied to each node's value
 *
 * Return: void
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
	{
		return;
	}

	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);

	func(tree->n);
}
