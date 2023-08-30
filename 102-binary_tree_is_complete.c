#include "binary_trees.h"
#include <stdlib.h>

/**
 * new_node - Function that creates new_node in a linked_list
 * @node: Type pointer of node to be created
 * Return: the node created
 */
link_t *new_node(binary_tree_t *node)
{
link_t *new;

new = malloc(sizeof(link_t));
if (new == NULL)
{
return (NULL);
}
new->node = node;
new->next = NULL;

return (new);
}

/**
 * free_q - Function that free the nodes in the linked list
 * @head: Head node of the linked list
 */
void free_q(link_t *head)
{
link_t *temp_node;

while (head)
{
temp_node = head->next;
free(head);
head = temp_node;
}
}

/**
 * _push - Function that pushes a node into the stack
 * @node: Node of the tree
 * @head: Head node in the stack
 * @tail: Tail node in the stack
 */
void _push(binary_tree_t *node, link_t *head, link_t **tail)
{
link_t *new;

new = new_node(node);
if (new == NULL)
{
free_q(head);
exit(1);
}
(*tail)->next = new;
*tail = new;
}

/**
 * _pop - Function that pops a node from the stack
 * @head: Head node in the stack
 */
void _pop(link_t **head)
{
link_t *temp_node;

temp_node = (*head)->next;
free(*head);
*head = temp_node;
}

/**
 * binary_tree_is_complete - Function that checks if a binary tree is complete
 * @tree: Root node of the tree
 * Return: 1 if it is complete, 0 if it is not
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
link_t *head, *tail;
int flag = 0;

if (tree == NULL)
{
return (0);
}
head = tail = new_node((binary_tree_t *)tree);
if (head == NULL)
{
exit(1);
}
while (head != NULL)
{
if (head->node->left != NULL)
{
if (flag == 1)
{
free_q(head);
return (0);
}
_push(head->node->left, head, &tail);
}
else
flag = 1;
if (head->node->right != NULL)
{
if (flag == 1)
{
free_q(head);
return (0);
}
_push(head->node->right, head, &tail);
}
else
flag = 1;
_pop(&head);
}
return (1);
}
