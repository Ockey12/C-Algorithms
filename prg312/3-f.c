#include <stdio.h>
#include "ex3lib12.h"

typedef struct _lnode2
{
  int data;
  struct _lnode2 *next;
} LNODE;

void LL_print2(LNODE *head);

void LL_isort(LNODE *head)
{
  LNODE tmp = {-100, NULL};
  LNODE *node = head->next;
  LNODE *next_node;
  LNODE *pos;

  next_node = &tmp;
  pos = next_node;

  while (node != NULL)
    {
      while (pos->next != NULL)
	{
	  if (pos->next->data > node->data)
	    {
	      break;
	    }
	  pos = pos->next;
	}

      head->next=node->next;
      node->next=pos->next;
      pos->next= node;
      node=head->next;

      pos = next_node;
      LL_print2(next_node);
    }
  head->next = next_node->next;

  return;
}

int main(void)
{
  LNODE node[] = {{-123}, {59}, {10}, {44}, {86}, {54}, {72}, {18}};
  LNODE *head = &node[0];
  int i;
  int n = sizeof(node) / sizeof(node[0]);

  for (i = 0; i < n - 1; i++)
    {
      node[i].next = &node[i + 1];
    }

  LL_print2(head);

  LL_isort(head);

  return 0;
}

void LL_print2(LNODE *head)
{
  LNODE *pos = head->next;

  while (pos != NULL)
    {
      printf("%d,", pos->data);
      pos = pos->next;
    }
  printf("\n");
  return;
}
