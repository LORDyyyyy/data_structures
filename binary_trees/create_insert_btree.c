#include "binary_trees.h"


/**
 * binary_tree_node - function that creates a binary tree node.
 * @parent: pointer to the parent node of the node to create.
 * @value: value to put in the new node.
 *
 * Return: pointer to the new node, or NULL on failure.
 */

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	new_node = malloc(sizeof(binary_tree_t));
	if (new_node == NULL)
		return (NULL);

	new_node->parent = parent;
	new_node->n = value;
	new_node->left = NULL;
	new_node->right = NULL;

	return (new_node);
}


/**
 * binary_tree_insert_left - function that inserts a node
 *                                       as the left-child of another node.
 * @parent: pointer to the node to insert the left-child in.
 * @value: value to store in the new node.
 *
 * Return: pointer to the created node,
 *                                 or NULL on failure or if parent is NULL.
 *
 * If parent already has a left-child, the new node must take its place,
 * and the old left-child must be set as the left-child of the new node.
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;
	binary_tree_t *parent_left;

	if (parent == NULL)
		return (NULL);

	new_node = binary_tree_node(parent, value);

	if (new_node == NULL)
		return (NULL);

	parent_left = parent->left;

	if (parent_left)
	{
		new_node->left = parent_left;
		parent_left->parent = new_node;
	}

	parent->left = new_node;

	return (new_node);
}

/**
 * binary_tree_insert_right - function that inserts a node
 *                                      as the right-child of another node.
 * @parent: pointer to the node to insert the right-child in.
 * @value: value to store in the new node.
 *
 * Return: pointer to the created node,
 *                                 or NULL on failure or if parent is NULL.
 *
 * If parent already has a right-child, the new node must take its place,
 * and the old right-child must be set as the right-child of the new node.
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;
	binary_tree_t *parent_right;

	if (parent == NULL)
		return (NULL);

	new_node = binary_tree_node(parent, value);

	if (new_node == NULL)
		return (NULL);

	parent_right = parent->right;

	if (parent_right)
	{
		new_node->right = parent_right;
		parent_right->parent = new_node;
	}

	parent->right = new_node;

	return (new_node);
}
