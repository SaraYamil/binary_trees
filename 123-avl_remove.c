/**
 * avl_remove - removes a node with a specific value from an AVL tree
 * @root: root of the AVL tree
 * @value: value to remove
 * Return: pointer to the new root of the AVL tree after removal
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *root_a = (avl_t *) bst_remove((bst_t *) root, value);

	if (root_a == NULL)
		return (NULL);
	bal(&root_a);
	return (root_a);
}
