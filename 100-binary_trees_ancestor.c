#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor
 * of two nodes in a binary tree
 * @first: first node
 * @second: second node
 * Return: pointer to the lowest common ancestor node, or NULL if not found
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
					const binary_tree_t *second)
{
	const binary_tree_t *f_anc, *s_anc;

	for (f_anc = first; f_anc; f_anc = f_anc->parent)
		for (s_anc = second; s_anc; s_anc = s_anc->parent)
			if (f_anc == s_anc)
				return ((binary_tree_t *)f_anc);
	return (NULL);
}
