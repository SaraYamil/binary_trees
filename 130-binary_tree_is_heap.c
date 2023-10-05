#include "binary_trees.h"

int check_complete(const binary_tree_t *root, int index, int nodes);
int check_status(const binary_tree_t *node);
int get_nodes(const binary_tree_t *root);

/**
 * binary_tree_is_heap - Checks if a binary tree is a max heap.
 * @tree: Pointer to the root node of the binary tree.
 *
 * Return: 1 if the binary tree is a max heap, 0 otherwise or if the
 *         tree is NULL.
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int finish, state, i = 0, tree_nodes;

	if (!tree)
	{
		return (0);
	}

	tree_nodes = get_nodes(tree);
	finish = check_complete(tree, i, tree_nodes);
	state = check_status(tree);

	return (finish && state);
}


/**
 * check_complete - Checks if a binary tree is complete.
 * @root: Pointer to the root node of the binary tree.
 * @index: Current index of the node being checked.
 * @nodes: Total number of nodes in the binary tree.
 *
 * Return: 1 if the binary tree is complete, 0 otherwise.
 */
int check_complete(const binary_tree_t *root, int index, int nodes)
{
	if (!root)
	{
		return (1);
	}
	if (index >= nodes)
	{
		return (0);
	}

	return (check_complete(root->left, 2 * index + 1, nodes) &&
			check_complete(root->right, 2 * index + 2, nodes));
}

/**
 * check_status - Checks if a binary tree satisfies max-heap property.
 * @node: Pointer to the node being checked during recursion.
 *
 * Return: 1 if the binary tree satisfies max-heap property, 0 otherwise.
 */
int check_status(const binary_tree_t *node)
{
	if (!node)
	{
		return (1);
	}
	if (node->left)
	{
		if (node->left->n > node->n)
		{
			return (0);
		}
	}
	if (node->right)
	{
		if (node->right->n > node->n)
		{
			return (0);
		}
	}
	return (check_status(node->left) && check_status(node->right));
}

/**
 * get_nodes - Calculates the number of nodes in a binary tree.
 * @root: Pointer to the root node of the binary tree.
 *
 * Return: Number of nodes in the binary tree.
 */
int get_nodes(const binary_tree_t *root)
{
	if (!root)
		return (0);
	return (get_nodes(root->left) +
			get_nodes(root->right) + 1);
}
