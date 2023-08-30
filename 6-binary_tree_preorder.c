#include "binary_trees.h"

/**
 * binary_tree_preorder - Performs pre-order traversal on a binary tree.
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to the function to be called for each node.
 *
 * Description: In pre-order traversal, the current node is visited first,
 * followed by its left subtree, and then its right subtree.
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
if (tree == NULL || func == NULL)
return;

func(tree->n);
binary_tree_preorder(tree->left, func);
binary_tree_preorder(tree->right, func);
}
