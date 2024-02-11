#include "binary_trees.h"


/**
 * binary_tree_nodes - Counts the nodes with at least 1 child in a binary tree.
 * @tree: A pointer to the root node of the tree to count the nodes.
 *
 * Return: Number of nodes with at least 1 child in the tree.
 *
 * If tree is NULL, the function returns 0.
 * A NULL pointer is not a node.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes = 0;

	if (tree == NULL)
		return (0);

	if (tree->left || tree->right)
		nodes += 1;

	nodes += binary_tree_nodes(tree->left);
	nodes += binary_tree_nodes(tree->right);

	return (nodes);
}


/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree.
 *
 * Return: The height of the binary tree.
 *
 * If tree is NULL, the function returns 0.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 1, right_height = 1;

	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);

	left_height += binary_tree_height(tree->left);
	right_height += binary_tree_height(tree->right);

	if (left_height > right_height)
		return (left_height);
	else
		return (right_height);
}


/**
 * binary_tree_depth - Measures the depth of a node in a binary tree.
 * @tree: A pointer to the node to measure the depth.
 *
 * Return: The depth of the node in the binary tree.
 *
 * If tree is NULL, the function returns 0.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	const binary_tree_t *current_node = tree;
	size_t current_depth = 0;

	if (tree == NULL)
		return (0);

	while (current_node->parent != NULL)
	{
		current_depth += 1;
		current_node = current_node->parent;
	}

	return (current_depth);
}


/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the size.
 *
 * Return: Size of the binary tree.
 *
 * If tree is NULL, the function returns 0.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 1;

	if (tree == NULL)
		return (0);

	size += binary_tree_size(tree->left);
	size += binary_tree_size(tree->right);

	return (size);
}

/**
 * binary_tree_leaves - Counts the leaves in a binary tree.
 * @tree: A pointer to the root node of the tree to count the number of leaves.
 *
 * Return: Number of leaves in the tree.
 *
 * If tree is NULL, the function returns 0.
 * A NULL pointer is not a leaf.
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t left_leaves, right_leaves;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	left_leaves = binary_tree_leaves(tree->left);
	right_leaves = binary_tree_leaves(tree->right);

	return (left_leaves + right_leaves);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree.
 * @tree: a pointer to the node to measure the balance factor
 * If tree is NULL, return 0.
 * Return: Balance factor
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int left_balance, right_balance;

	if (tree == NULL)
		return (0);

	left_balance = binary_tree_height(tree->left);
	right_balance = binary_tree_height(tree->right);

	return (left_balance - right_balance);
}
