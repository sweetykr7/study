#include "linkedstack.h"
// #include "linkedstack.c"

int main(void)
{
  LinkedStack *head;
  StackNode   node;

  head = createLinkedStack();
  displayStack(head);
  node.data = 3;
  pushLS(head, node);
  node.data = 1;
  pushLS(head, node);
  node.data = -1;
  pushLS(head, node);
  node.data = 10;
  pushLS(head, node);
  node.data = -7;
  pushLS(head, node);
  displayStack(head);
  popLS(head);
  popLS(head);
  displayStack(head);

}