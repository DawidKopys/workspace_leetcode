#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
  int val;
  struct ListNode *next;
};

void free_linked_list(struct ListNode *head)
{
  struct ListNode *node, *temp;

  node = head;
  while (node != NULL)
  {
    temp = node;
    node = node->next;
    free(temp);
  }
}

void print_linked_list(struct ListNode *head)
{
  struct ListNode *node;

  node = head;
  while (node != NULL)
  {
    printf("List item: current is %p, next is %p, data is %d\n", node, node->next, node->val);
    node = node->next;
  }
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
  if (l1 == NULL)
    return l2;
  if (l2 == NULL)
    return l1;

  int carry = 0;
  struct ListNode *node, *head = NULL, *curr = NULL;

  while ((l1 != NULL) || (l2 != NULL))
  {
    if (l1 != NULL)
    {
      carry += l1->val;
      l1 = l1->next;
    }
    if (l2 != NULL)
    {
      carry += l2->val;
      l2 = l2->next;
    }

    node = malloc(sizeof(struct ListNode));
    node->next = NULL;
    node->val = carry % 10;

    if (head == NULL)
    {
      curr = node;
      head = curr;
    }
    else
    {
      curr->next = node;
      curr = node;
    }

    carry /= 10;
  }

  if (carry > 0)
  {
    node = malloc(sizeof(struct ListNode));
    node->next = NULL;
    node->val = carry;
    curr->next = node;
  }

  return head;
}

int main(int argc, char const *argv[])
{
  struct ListNode *node, *l1, *l2, *result;

  l1 = NULL;
  l2 = NULL;

  /* populate first linked list*/
  for (int i = 2; i < 5; i++)
  {
    node = malloc(sizeof(struct ListNode));
    node->val = i;
    node->next = l1;
    l1 = node;
  }
  /* ... and second one */
  for (int i = 3; i < 6; i++)
  {
    node = malloc(sizeof(struct ListNode));
    node->val = i;
    node->next = l2;
    l2 = node;
  }

  /* print linked lists's contents and free each element */
  node = l1;
  printf("l1 contents:\n");
  while (node != NULL)
  {
    //temp = node;
    printf("List item: current is %p, next is %p, data is %d\n", node, node->next, node->val);
    node = node->next;
    //free(temp);
  }

  /* print linked lists's contents and free each element */
  node = l2;
  printf("l2 contents:\n");
  while (node != NULL)
  {
    //temp = node;
    printf("List item: current is %p, next is %p, data is %d\n", node, node->next, node->val);
    node = node->next;
    //free(temp);
  }

  result = addTwoNumbers(l1, l2);

  printf("result:\n");
  print_linked_list(result);

  free_linked_list(l1);
  free_linked_list(l2);
  free_linked_list(result);

  return 0;
}