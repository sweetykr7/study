#include "doublylist.h"
#include <stdio.h>
#include <stdlib.h>



// #include "createDoublyList.c"
// #include "addDLElement.c"
// #include "removeDLElement.c"
// #include "getDLElement.c"
// #include "clearDoublyList.c"
// #include "getDoublyListLength.c"
// #include "deleteDoublyList.c"
// #include "displayDoublyList.c"
// #include "addPolyNodeLast.c"
// #include "findIndex.c"
// #include "polynomial.c"



int main(void)
{
	DoublyList	*h1;
	DoublyList	*h2;
	DoublyList	*res;

	h1 = createDoublyList();
	h2 = createDoublyList();
	addPolyNodeLast(h1, 2, 1);
	addPolyNodeLast(h1, 1.1, 1);
	addPolyNodeLast(h1, 2, 2);
	addPolyNodeLast(h1, -5, 5);
	addPolyNodeLast(h1, -1.3, 0);

	addPolyNodeLast(h2, 10, 1);
	addPolyNodeLast(h2, -17.1, 3);
	addPolyNodeLast(h2, 13, 5);
	addPolyNodeLast(h2, 3.7, 0);
	addPolyNodeLast(h2, -5, 6);

	displayDoublyList(h1);
	displayDoublyList(h2);
	res = polynomial(h1, h2);
	displayDoublyList(res);
	return (0);
}
