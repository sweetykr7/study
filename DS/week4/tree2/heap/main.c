#include "heap.h"

int main()
{
	Heap		*h;
	HeapNode	node;

	h = createHeap(8);
	node.key = 10;
	insertMaxHeap(h, node);
	node.key = 1;
	insertMaxHeap(h, node);
	node.key = 3;
	insertMaxHeap(h, node);
	node.key = -7;
	insertMaxHeap(h, node);
	node.key = 30;
	insertMaxHeap(h, node);
	node.key = 20;
	insertMaxHeap(h, node);
	node.key = -5;
	insertMaxHeap(h, node);
	displayHeap(h);
	deleteMaxHeapNode(h);
	displayHeap(h);
}