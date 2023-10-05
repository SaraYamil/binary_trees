#include "binary_trees.h"

/**
 * tree_height - Measures the height of a heap tree
 * @tree: A pointer to the root of the heap tree
 *
 * Return: The height of the heap tree, or 0 if @tree is NULL
 */
size_t tree_height(const heap_t *tree)
{
	size_t h_left = 0, h_right = 0;

	if (!tree)
	{
		return (0);
	}

	if (tree->left)
	{
		h_left = 1 + tree_height(tree->left);
	}

	if (tree->right)
	{
		h_right = 1 + tree_height(tree->right);
	}

	if (h_left > h_right)
	{
		return (h_left);
	}

	return (h_right);
}

/**
 * tree_size_h - Measures the size of a binary tree
 * @tree: A pointer to the root of the binary tree
 *
 * Return: The size of the binary tree, or 0 if @tree is NULL
 */
size_t tree_size_h(const binary_tree_t *tree)
{
	size_t h_left = 0, h_right = 0;

	if (!tree)
	{
		return (0);
	}

	if (tree->left)
	{
		h_left = 1 + tree_size_h(tree->left);
	}

	if (tree->right)
	{
		h_right = 1 + tree_size_h(tree->right);
	}

	return (h_left + h_right);
}

/**
 * _order - Helper function to recursively find a node at a certain height
 * @tree: A pointer to the current node being checked
 * @node: A pointer to a pointer that will store the found node
 * @height: The height at which to find the node
 */
void _order(heap_t *tree, heap_t **node, size_t height)
{
	if (!tree)
	{
		return;
	}

	if (!height)
	{
		*node = tree;
	}

	height--;

	_order(tree->left, node, height);
	_order(tree->right, node, height);
}

/**
 * heapify - Ensures the max heap property is maintained from the given root
 * @root: A pointer to the root of the heap
 */
void heapify(heap_t *root)
{
	heap_t *temp1, *temp2;
	int vl;

	if (!root)
	{
		return;
	}

	temp1 = root;

	while (1)
	{
		if (!temp1->left)
			break;
		if (!temp1->right)
			temp2 = temp1->left;
		else
		{
			if (temp1->left->n > temp1->right->n)
				temp2 = temp1->left;
			else
				temp2 = temp1->right;
		}
		if (temp1->n > temp2->n)
			break;
		vl = temp1->n;
		temp1->n = temp2->n;
		temp2->n = vl;
		temp1 = temp2;
	}
}

/**
 * heap_extract - Extracts the root value of a max heap
 * @root: A pointer to a pointer to the root of the max heap
 *
 * Return: The extracted root value, or 0 if @root is NULL or the
 *         heap is empty
 */
int heap_extract(heap_t **root)
{
	int vl;
	heap_t *heap_tree, *node_tree;

	if (!root || !*root)
	{
		return (0);
	}
	heap_tree = *root;
	vl = heap_tree->n;
	if (!heap_tree->left && !heap_tree->right)
	{
		*root = NULL;
		free(heap_tree);
		return (vl);
	}

	_order(heap_tree, &node_tree, tree_height(heap_tree));

	heap_tree->n = node_tree->n;
	if (node_tree->parent->right)
		node_tree->parent->right = NULL;
	else
		node_tree->parent->left = NULL;
	free(node_tree);
	heapify(heap_tree);
	*root = heap_tree;

	return (vl);
}
