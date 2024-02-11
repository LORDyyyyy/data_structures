#include "binary_trees.h"

/**
 * binary_tree_is_leaf - function that checks if a node is a leaf.
 * @node: pointer to the node to check.
 *
 * Return: 1 if node is a leaf, otherwise 0
 * If node is NULL, return 0
 */

int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	if (node->left == NULL && node->right == NULL)
		return (1);

	return (0);
}

/**
 * binary_tree_is_root - function that checks if a given node is a root.
 * @node: pointer to the node to check.
 *
 * Return: 1 if node is a root, otherwise 0
 * If node is NULL, return 0
 */

int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);

	if (!node->parent)
		return (1);

	return (0);
}

/**
 * binary_tree_is_full -  checks if a binary tree is full
 * @tree: the binary tree
 *
 * Return:  1 if full, 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!tree->right && !tree->left)
		return (1);

	if (tree->left && tree->right)
	{
		int tmp1, tmp2;

		tmp1 = binary_tree_is_full(tree->left);
		tmp2 = binary_tree_is_full(tree->right);

		return ((tmp1 & tmp2));
	}

	return (0);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: the binary tree
 *
 * Return: 1 if perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int leftHeight, rightHeight;

	if (!tree)
		return (0);

	leftHeight = binary_tree_height(tree->left);
	rightHeight = binary_tree_height(tree->right);

	if (leftHeight == rightHeight)
	{
		if (!tree->left || !tree->right)
			return (1);

		return (binary_tree_is_perfect(tree->left) &&
				binary_tree_is_perfect(tree->right));
	}
	return (0);
}
