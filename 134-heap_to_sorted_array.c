#include "binary_trees.h"

size_t tree_size(const binary_tree_t *tree);

/**
 * heap_to_sorted_array - Converts a max heap to a sorted array
 * @heap: A pointer to the root of the max heap
 * @size: A pointer to a size_t to store the size of the array
 *
 * Return: A pointer to the sorted array, or NULL on failure
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int index, *atree = NULL;

	if (!heap || !size)
	{
		return (NULL);
	}

	*size = tree_size(heap) + 1;

	atree = malloc(sizeof(int) * (*size));

	if (!atree)
	{
		return (NULL);
	}

	for (index = 0; heap; index++)
	{
		atree[index] = heap_extract(&heap);
	}

	return (atree);
}

/**
 * tree_size - Calculates the number of nodes in a binary tree
 * @tree: A pointer to the root of the binary tree
 *
 * Return: The number of nodes in the binary tree
 */
size_t tree_size(const binary_tree_t *tree)
{
	size_t h_left = 0, h_right = 0;

	if (!tree)
	{
		return (0);
	}

	if (tree->left)
	{
		h_left = 1 + tree_size(tree->left);
	}

	if (tree->right)
	{
		h_right = 1 + tree_size(tree->right);
	}

	return (h_left + h_right);
}
