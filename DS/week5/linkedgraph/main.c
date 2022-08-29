#include "linkedgraph.h"

int main(void)
{
	LinkedGraph *g;

	g = createLinkedGraph(8);
	addVertexLG(g, 0);
	addVertexLG(g, 1);
	addVertexLG(g, 2);
	addVertexLG(g, 3);
	addEdgeLG(g, 3, 1);
	//removeVertexLG(g, 3);
	//removeEdgeLG(g, 3, 1);
	displayLinkedGraph(g);
	return (0);
}

// gcc 구문
// gcc main.c linkedgraph.c linkedlist.c