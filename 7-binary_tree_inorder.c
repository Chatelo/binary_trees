#include "binary_trees.h"

/**
 * binary_tree_inorder - Performs in-order traversal on a binary tree.
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to the function to be called for each node.
 *
 * Description: In in-order traversal, the left subtree is visited first,
 * then the current node, and finally the right subtree.
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
if (tree == NULL || func == NULL)
return;

binary_tree_inorder(tree->left, func);
func(tree->n);
binary_tree_inorder(tree->right, func);
}
