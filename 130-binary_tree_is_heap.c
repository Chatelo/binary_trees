#include "binary_trees.h"

/**
 * binary_tree_size - Measure the size of a binary tree
 * @tree: Pointer to the root node of the tree
 *
 * Return: The size of the tree, or 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
if (tree == NULL)
return (0);

return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
* is_complete - Check if a binary tree is complete
* @tree: Pointer to the root node of the tree
* @index: Index of the current node
* @node_count: Number of nodes in the tree
*
* Return: 1 if the tree is complete, 0 otherwise
*/
int is_complete(const binary_tree_t *tree, int index, int node_count)
{
if (tree == NULL)
return (1);

if (index >= node_count)
return (0);

return (is_complete(tree->left, 2 * index + 1, node_count) &&
is_complete(tree->right, 2 * index + 2, node_count));
}

/**
* is_heap - Check if a binary tree is a Max Heap
* @tree: Pointer to the root node of the tree
*
* Return: 1 if the tree is a Max Heap, 0 otherwise
*/
int is_heap(const binary_tree_t *tree)
{
if (tree == NULL || (tree->left == NULL && tree->right == NULL))
return (1);

if (tree->left != NULL && tree->n < tree->left->n)
return (0);

if (tree->right != NULL && tree->n < tree->right->n)
return (0);

return (is_heap(tree->left) && is_heap(tree->right));
}

/**
* binary_tree_is_heap - Check if a binary tree is a valid Max Binary Heap
* @tree: Pointer to the root node of the tree
*
* Return: 1 if the tree is a valid Max Binary Heap, 0 otherwise
*/
int binary_tree_is_heap(const binary_tree_t *tree)
{
int node_count;

if (tree == NULL)
return (0);

node_count = binary_tree_size(tree);

if (is_complete(tree, 0, node_count) && is_heap(tree))
return (1);

return (0);
}
