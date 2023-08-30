#include <stdlib.h>
#include "binary_trees.h"

/**
 * get_last_node - Returns the last level-order node of a binary tree
 * @root: Pointer to the root node of the tree
 *
 * Return: Pointer to the last node
 */
heap_t *get_last_node(heap_t *root)
{
heap_t *queue[100], *node = NULL;
size_t rear = 0, front = 0;

if (root == NULL)
return (NULL);

queue[rear++] = root;
while (front < rear)
{
node = queue[front++];
if (node->left != NULL)
queue[rear++] = node->left;
if (node->right != NULL)
queue[rear++] = node->right;
}

return (node);
}

/**
 * sift_down - Reorganizes the heap downward from the given node
 * @root: Pointer to the root node of the heap
 *
 * Return: Pointer to the new root node
 */
heap_t *sift_down(heap_t *root)
{
heap_t *current = root, *child;
int temp;

while (current->left != NULL)
{
child = current->left;
if (current->right != NULL && current->right->n > child->n)
child = current->right;
if (current->n >= child->n)
break;
temp = current->n;
current->n = child->n;
child->n = temp;
current = child;
}

return (root);
}

/**
* heap_extract - Extracts the root node of a Max Binary Heap
* @root: Double pointer to the root node of the heap
*
* Return: Value stored in the root node, or 0 on failure
*/
int heap_extract(heap_t **root)
{
heap_t *last_node, *current;
int extracted_value;

if (root == NULL || *root == NULL)
return (0);

current = *root;
extracted_value = current->n;
last_node = get_last_node(*root);

if (current == last_node)
{
free(current);
*root = NULL;
return (extracted_value);
}

current->n = last_node->n;

if (last_node->parent->left == last_node)
last_node->parent->left = NULL;
else
last_node->parent->right = NULL;

free(last_node);

*root = sift_down(*root);

return (extracted_value);
}
