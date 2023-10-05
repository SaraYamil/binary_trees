#include "binary_trees.h"

bst_t *inorder_succ(bst_t *root);
bst_t *bst_dlt(bst_t *root, bst_t *node);
bst_t *best_remove_recur(bst_t *root, bst_t *node, int value);

/**
 * bst_remove - removes a node with a specific value from a Binary Search Tree
 *	      (BST)
 * @root: pointer to the root node of the BST
 * @value: value to be removed
 *
 * Return: pointer to the new root node of the BST after removal
 */
bst_t *bst_remove(bst_t *root, int value)
{
	return (best_remove_recur(root, root, value));
}

/**
 * inorder_succ - finds the in-order successor of a node in a Binary Search
 * @root: pointer to the root node of the subtree
 *
 * Return: pointer to the in-order successor node
 */
bst_t *inorder_succ(bst_t *root)
{
	while (root->left != NULL)
	{
		root = root->left;
	}

	return (root);
}

/**
 * bst_dlt - deletes a node from a Binary Search Tree (BST)
 * @root: pointer to the root node of the BST
 * @node: pointer to the node to be deleted
 *
 * Return: pointer to the new root node of the BST after deletion
 */
bst_t *bst_dlt(bst_t *root, bst_t *node)
{
	bst_t *parent_node = node->parent, *succ = NULL;

	if (node->left == NULL)
	{
		if (parent_node != NULL && parent_node->left == node)
		{
			parent_node->left = node->right;
		}
		else if (parent_node != NULL)
		{
			parent_node->right = node->right;
		}
		if (node->right != NULL)
		{
			node->right->parent = parent_node;
		}

		free(node);

		return (parent_node == NULL ? node->right : root);
	}

	if (node->right == NULL)
	{
		if (parent_node != NULL && parent_node->left == node)
			parent_node->left = node->left;
		else if (parent_node != NULL)
			parent_node->right = node->left;
		if (node->left != NULL)
			node->left->parent = parent_node;
		free(node);

		return (parent_node == NULL ? node->left : root);
	}

	succ = inorder_succ(node->right);
	node->n = succ->n;

	return (bst_dlt(root, succ));
}

/**
 * best_remove_recur - recursively removes a node with a specific value
 *		     from a BST
 * @root: pointer to the root node of the BST
 * @node: current node being checked during recursion
 * @value: value to be removed
 *
 * Return: pointer to the new root node of the BST after removal
 */
bst_t *best_remove_recur(bst_t *root, bst_t *node, int value)
{
	if (node != NULL)
	{
		if (node->n == value)
			return (bst_dlt(root, node));
		if (node->n > value)
			return (best_remove_recur(root, node->left, value));
		return (best_remove_recur(root, node->right, value));
	}

	return (NULL);
}
