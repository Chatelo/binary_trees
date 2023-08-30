#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_levelorder - Performs level-order traversal on binary tree
 *
 * @tree: Pointer to the root node of tree to traverse
 * @func: Pointer to function to call for each node
 *        The value in the node must be passed as parameter to this function
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t **queue = NULL;
	size_t front = 0, rear = 0;

	if (tree == NULL || func == NULL)
		return;

	queue = malloc(sizeof(binary_tree_t *) * 1024);
	if (queue == NULL)
		return;

	queue[rear++] = (binary_tree_t *)tree;

	while (front < rear)
	{
		binary_tree_t *current = queue[front++];

		func(current->n);

		if (current->left != NULL)
			queue[rear++] = current->left;

		if (current->right != NULL)
			queue[rear++] = current->right;
	}

	free(queue);
}
