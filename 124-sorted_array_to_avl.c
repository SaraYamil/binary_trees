#include "binary_trees.h"

avl_t *aux_sort(avl_t *parent, int *array, int begin, int last);

/**
 * sorted_array_to_avl - Constructs an AVL tree from a sorted array.
 * @array: Pointer to the sorted array.
 * @size: Size of the array.
 *
 * Return: Pointer to the root node of the constructed AVL tree,
 *         or NULL if array is NULL or size is 0.
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);
	return (aux_sort(NULL, array, 0, ((int)(size)) - 1));
}

/**
 * aux_sort - Recursively constructs an AVL tree from a sorted array.
 * @parent: Pointer to the parent node.
 * @array: Pointer to the sorted array.
 * @begin: Index of the beginning of the current subarray.
 * @last: Index of the last element in the current subarray.
 *
 * Return: Pointer to the root node of the constructed AVL tree.
 */
avl_t *aux_sort(avl_t *parent, int *array, int begin, int last)
{
	avl_t *root_node;
	binary_tree_t *auxiliary;
	int md = 0;

	if (begin <= last)
	{
		md = (begin + last) / 2;
		auxiliary = binary_tree_node((binary_tree_t *)parent, array[md]);
		if (auxiliary == NULL)
			return (NULL);
		root_node = (avl_t *)auxiliary;
		root_node->left = aux_sort(root_node, array, begin, md - 1);
		root_node->right = aux_sort(root_node, array, md + 1, last);

		return (root_node);
	}

	return (NULL);
}
