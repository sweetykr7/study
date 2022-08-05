#include "linkedstack.h"

void BracketDelete(LinkedStack *h)
{
	StackNode	*top1;
	StackNode	*top2;

	if (!h || h->currentElementCount < 2)
		return ;
	top1 = h->pTopElement;
	top2 = top1->pLink;
	if (top1->data == '(')
	{
		if (top2->data != ')')
			return ;
	}
	else if (top1->data == '{')
	{
		if (top2->data != '}')
			return ;
	}
	else if (top1->data == '[')
	{
		if (top2->data != ']')
			return ;
	}
	popLS(h);
	popLS(h);	
}

int checkBracket(char c)
{
  if (c == '[' || c == ']' || c == '{' || c == '}' || c == '(' || c == ')')
    return (1);
  return (0);
}

int checkBracketMatching(LinkedStack *h)
{
	LinkedStack *new;
	StackNode   *temp;

	new = createLinkedStack();
	while (!isLinkedStackEmpty(h))
	{
		temp = popLS(h);
		if (checkBracket(temp->data))
			pushLS(new, *temp);
		BracketDelete(new);
	}
	if (isLinkedStackEmpty(new))
		return (TRUE);
	return (FALSE);
}

