#include "binary_trees.h"

int binary_tree_is_perfect(const binary_tree_t *tree);
size_t binary_tree_height(const binary_tree_t *tree);

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	binary_tree_t *left, *right;
	size_t left_node, right_node;

	if (tree == NULL)
	{
		return (0);
	}
	left = tree->left;
	right = tree->right;

	if (binary_tree_is_leaf(tree))
	{
		return (1);
	}
	if (left == NULL || right == NULL)
	{
		return (0);
	}
	left_node = binary_tree_height(right);
	right_node = binary_tree_height(left);
	if (left_node == right_node)
	{
		if (binary_tree_is_perfect(left) && binary_tree_is_perfect(right))
		{
			return (1);
		}
	}

	return (0);
}

/**
 * binary_tree_is_leaf - checks if a node is a leaf in a binary tree
 * @node: pointer to the node to check
 *
 * Return: 1 if the node is a leaf, 0 otherwise
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
	{
		return (0);
	}
	else if (node->left == NULL && node->right == NULL)
	{
		return (1);
	}

	return (0);
}

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree
 *
 * Return: height of the tree, or 0 if the tree is NULL or a leaf
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t h_left_node, h_right_node;

	if (tree == NULL || binary_tree_is_leaf(tree))
	{
		return (0);
	}

	h_left_node = binary_tree_height(tree->left);
	h_right_node = binary_tree_height(tree->right);
	if (h_right_node <= h_left_node)
	{
		return (h_left_node + 1);
	}

	return (h_right_node + 1);
}
