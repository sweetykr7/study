#include "linkedstack.h"

int	check_operand(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return (1);
	return (0);
}

void	calculate_both(LinkedStack *h, char oper, char top2, char top3)
{
	StackNode res_node;
	int num1;
	int	num2;
	int	res;

	res_node.pLink = 0;
	num1 = top2 - '0';
	num2 = top3 - '0';
	if (oper == '+')
		res = num2 + num1;
	else if (oper == '-')
		res = num2 - num1;
	else if (oper == '*')
		res = num2 * num1;
	else if (oper == '/')
		res = num2 / num1;
	res_node.data = res + '0';
	popLS_and_free(h);
	popLS_and_free(h);
	popLS_and_free(h);
	pushLS(h, res_node);
}

int calculator_stack(LinkedStack *h)
{
	LinkedStack *temp;
	StackNode 	*top1;
	StackNode	*top2;
	StackNode	*top3;
	StackNode	*temp_node;

	if (!h || h->currentElementCount < 3)
		return (-1);
	temp = createLinkedStack();
	while (h->currentElementCount != 1)
	{
		top1 = h->pTopElement;
		top2 = top1->pLink;
		top3 = top2->pLink;
		if (!check_operand(top2->data) && !check_operand(top3->data))
		{
			calculate_both(h, top1->data, top2->data, top3->data);
			if (!isLinkedStackEmpty(temp))
				pushLS_ALL(h, temp);
		}
		else
		{
			temp_node = popLS(h);
			pushLS(temp, *temp_node);
		}
	}
	return (h->pTopElement->data - '0');
}