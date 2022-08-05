#include "doublylist.h"



int	addPolyNodeLast(DoublyList *pList, float coef, int degree)
{
	int				ret;
	int				idx;
	DoublyListNode	node;

	ret = 0;
	idx = findIndex(pList, degree);
	node.coef = coef;
	node.degree = degree;
	if (pList)
		ret = addDLElement(pList, idx, node);
	return (ret);
}
