#include "linkedgraph.h"

int main(void)
{
	LinkedGraph *g;

	g = createLinkedGraph(8);
	addVertexLG(g, 0);
	addVertexLG(g, 1);
	addVertexLG(g, 2);
	addVertexLG(g, 3);
	addVertexLG(g, 4);
	addVertexLG(g, 5);
	addEdgeLG(g, 3, 0);
	addEdgeLG(g, 0, 5);
	addEdgeLG(g, 5, 4);
	//removeVertexLG(g, 3);
	//removeEdgeLG(g, 3, 1);
	//displayLinkedGraph(g);
	bfs_graph(g, 3);
	return (0);
}

// gcc 구문
// gcc main.c linkedgraph.c linkedlist.c