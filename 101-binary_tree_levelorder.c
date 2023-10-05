#include "binary_trees.h"

/**
 * binary_tree_levelorder - performs a level-order traversal on a binary tree
 * @tree: pointer to the root node of the tree
 * @func: pointer to a function to be applied to each node's value
 *
 * Return: void
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t *binary_list[1024], *temp;
	int i = 0, j = 0;

	if (tree == NULL || func == NULL)
	{
		return;
	}
	for (i = 0; i < 1024; i++)
	{
		binary_list[i] = NULL;
	}
	binary_list[0] = (binary_tree_t *)tree;
	i = 0;
	while (binary_list[i] != NULL)
	{
		temp = binary_list[i];
		func(temp->n);
		if (temp->left != NULL)
		{
			j++;
			binary_list[j] = temp->left;
		}
		if (temp->right != NULL)
		{
			j++;
			binary_list[j] = temp->right;
		}
		i++;
	}
}
