#include "doublylist.h"

int	findIndex(DoublyList *pList, int degree)
{
	int				idx;
	int				cnt;
	DoublyListNode	*temp;

	temp = &pList->headerNode;
	idx = 0;
	cnt = 0;
	if (degree == 0)
		return (-1);
	while (cnt < pList->currentElementCount)
	{
		temp = temp->pRLink;
		if (degree >= temp->degree)
			break ;
		cnt++;
		idx++;
	}
<<<<<<< HEAD

=======
>>>>>>> master
	return (idx);
}
