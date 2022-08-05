#include "linkedstack.h"
#include "linkedstack.c"
#include "checkBracketMatching.c"
#include "calculator.c"

int main(void)
{
	LinkedStack *head;
	StackNode   node;

	head = createLinkedStack();
	displayStack(head);
	// node.data = '(';
	// pushLS(head, node);
	node.data = '1';
	pushLS(head, node);
	node.data = '2';
	pushLS(head, node);
	node.data = '3';
	pushLS(head, node);
	node.data = '+';
	pushLS(head, node);
	node.data = '4';
	pushLS(head, node);
	node.data = '*';
	pushLS(head, node);
	node.data = '-';
	pushLS(head, node);
	displayStack(head);
	printf("result : %d", calculator_stack(head));
	// if (checkBracketMatching(head))
	// 	printf("Matching Complete\n");
	// else
	// 	printf("Matching Error\n");
  // displayStack(head);
  // popLS(head);
  // popLS(head);
  	

}