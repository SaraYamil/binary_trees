#include "binary_trees.h"

/**
 * bst_search - searches for a value in a Binary Search Tree (BST)
 * @tree: root of the BST to search
 * @value: value to search for
 * Return: pointer to the node containing the value,
 * or NULL if not found or if tree is NULL
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *found;

	if (tree == NULL)
		return (NULL);

	if (value < tree->n)
	{
		found = bst_search(tree->left, value);
	}
	else if (value > tree->n)
	{
		found = bst_search(tree->right, value);
	}
	else if (value == tree->n)
		return ((bst_t *)tree);
	else
		return (NULL);
	return (found);
}
