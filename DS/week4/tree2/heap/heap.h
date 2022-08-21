typedef struct HeapNodeType
{
	int	key;
}	HeapNode;

typedef struct HeapType
{
	int			maxCount;
	int			currentCount;
	HeapNode	*pElement;
}	Heap;

Heap*		createHeap(int maxCount);
void		deleteHeap(Heap **pHeap);
int			insertMaxHeap(Heap *pHeap, HeapNode element);
int			insertMinHeap(Heap *pHeap, HeapNode element);
int			deleteMaxHeapNode(Heap *pHeap);
int			deleteMinHeapNode(Heap *pHeap);
HeapNode	*getMaxHeapNode(Heap *pHeap);
HeapNode	*getMinHeapNode(Heap *pHeap);
int			isHeapFull(Heap *pHeap);
int			isHeapEmpty(Heap *pHeap);
void		displayHeap(Heap *pHeap);