#include "arraygraph.h"

int main(void)
{
	ArrayGraph *g;

	g = createArrayGraph(8);
	addVertexAG(g, 0);
	addVertexAG(g, 1);
	addVertexAG(g, 2);
	addVertexAG(g, 3);
	displayArrayGraph(g);
	addEdgeAG(g, 0, 1);
	addEdgeAG(g, 3, 1);
	displayArrayGraph(g);
	return (0);
}