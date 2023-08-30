#include "binary_trees.h"

/**
 * binary_tree_postorder - Performs post-order traversal on a binary tree.
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to the function to be called for each node.
 *
 * Description: In post-order traversal, the left subtree is visited first,
 * then the right subtree, and finally the current node.
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
if (tree == NULL || func == NULL)
return;

binary_tree_postorder(tree->left, func);
binary_tree_postorder(tree->right, func);
func(tree->n);
}
