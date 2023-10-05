#include "binary_trees.h"

/**
 * bst_insert - inserts a value into a Binary Search Tree (BST)
 * @tree: double pointer to the root node of the BST
 * @value: value to be inserted
 *
 * Return: pointer to the newly inserted node, or NULL on failure
 *	 or duplicate value
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *temp = NULL, *second_t = NULL, *new_t = NULL;

	if (!tree)
	{
		return (NULL);
	}
	if (*tree == NULL)
	{
		return (*tree = binary_tree_node(NULL, value));
	}

	temp = *tree;
	while (temp)
	{
		second_t = temp;
		if (value < temp->n)
			temp = temp->left;
		else if (value > temp->n)
			temp = temp->right;
		else if (value == temp->n)
			return (NULL);
	}

	new_t = binary_tree_node(NULL, value);
	if (second_t == NULL)
	{
		second_t = new_t;
	}
	else if (value < second_t->n)
	{
		second_t->left = new_t;
		new_t->parent = second_t;
	}
	else
	{
		second_t->right = new_t;
		new_t->parent = second_t;
	}

	return (new_t);
}
