#include "binary_trees.h"

/**
 * array_to_heap - Converts an array into a max-heap
 * @array: pointer to the array of integers
 * @size: number of elements in the array
 *
 * Return: Pointer to the root node of the max-heap, or NULL on failure
 */
heap_t *array_to_heap(int *array, size_t size)
{
	heap_t *root_node = NULL;
	unsigned int i;

	for (i = 0; i < size; i++)
	{
		heap_insert(&root_node, array[i]);
	}

	return (root_node);
}
