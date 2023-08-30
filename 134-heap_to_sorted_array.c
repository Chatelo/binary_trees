#include <stdlib.h>
#include "binary_trees.h"

/**
 * get_tree_size - Computes the size of a binary tree
 * @root: Pointer to the root node of the tree
 *
 * Return: The size of the tree
 */
size_t get_tree_size(heap_t *root)
{
if (root == NULL)
return (0);

return (1 + get_tree_size(root->left) + get_tree_size(root->right));
}

/**
 * heap_to_sorted_array - Converts a Binary Max Heap to a sorted array
 * @heap: Pointer to the root node of the heap
 * @size: Address to store the size of the array
 *
 * Return: Pointer to the sorted array of integers
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
int *sorted_array;
size_t heap_size, i;

if (heap == NULL)
{
*size = 0;
return (NULL);
}

heap_size = get_tree_size(heap);
sorted_array = malloc(heap_size *sizeof(int));
if (sorted_array == NULL)
{
*size = 0;
return (NULL);
}

for (i = 0; i < heap_size; i++)
{
sorted_array[i] = heap->n;
heap_extract(&heap);
}

*size = heap_size;

return (sorted_array);
}
