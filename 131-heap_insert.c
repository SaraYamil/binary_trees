#include "binary_trees.h"

size_t binary_tree_size(const binary_tree_t *tree);

/**
 * heap_insert - Inserts a value into a max-heap and maintains the max-heap
 *	       property
 * @root: double pointer to the root node of the max-heap
 * @value: value to be inserted
 *
 * Return: Pointer to the newly inserted node, or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *binary_tree, *new_tree, *flip_tree;
	int size, lvl, temp, leaves, sub, bit;

	if (!root)
	{
	return (NULL);
	}
	if (!(*root))
		return (*root = binary_tree_node(NULL, value));
	binary_tree = *root;
	size = binary_tree_size(binary_tree);
	leaves = size;
	for (lvl = 0, sub = 1; leaves >= sub; sub *= 2, lvl++)
	{
		leaves -= sub;
	}

	for (bit = 1 << (lvl - 1); bit != 1; bit >>= 1)
	{
		binary_tree = leaves & bit ? binary_tree->right : binary_tree->left;
	}

	new_tree = binary_tree_node(binary_tree, value);
	leaves & 1 ? (binary_tree->right = new_tree) : (binary_tree->left = new_tree);

	flip_tree = new_tree;
	for (; flip_tree->parent && (flip_tree->n > flip_tree->parent->n);
	 flip_tree = flip_tree->parent)
	{
		temp = flip_tree->n;
		flip_tree->n = flip_tree->parent->n;
		flip_tree->parent->n = temp;
		new_tree = new_tree->parent;
	}

	return (new_tree);
}

/**
 * binary_tree_size - Calculates the size of a binary tree
 * @tree: pointer to the root node of the binary tree
 *
 * Return: Size of the binary tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
	{
		return (0);
	}

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
