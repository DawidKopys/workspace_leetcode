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
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int carry = 0;
    struct ListNode *p, *q, *ret = NULL, *node;
    int x, y, sum;

    p = l1;sizeof(struct ListNode)
    q = l2;
    while ((p != NULL) || (q != NULL))
    {
        x = (p == NULL) ? 0 : p->val;
        y = (q == NULL) ? 0 : q->val;
        // (p == NULL) ? (x = 0) : (x = p->val);
        // (q == NULL) ? (y = 0) : (y = q->val);
        sum = x + y + carry;
        carry = sum/10;

        node = malloc(sizeof(struct ListNode));
        node->val = sum%10;
        node->next = ret;
        ret = node;

        if (p != NULL) { p = p->next; }
        if (q != NULL) { q = q->next; }
    }
    
    if (carry > 0)
    {
        node = malloc(sizeof(struct ListNode));
        node->val = 0;
        node->next = ret;
        ret = node;
    }

    return ret;
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