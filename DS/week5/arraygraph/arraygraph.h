#ifndef _GRAPH_ADJMATRIX_
#define _GRAPH_ADJMATRIX_

typedef struct ArrayGraphType
{
	int maxVertexCount;		// 최대 노드 개수
	int currentVertexCount;	// 현재 노드 개수
	int graphType;			// 1-Undirected, 2-Directed
	int **ppAdjEdge;		//   간선 저장을 위한 배열 포인터
	int *pVertex;			//  노드 저장을 위한 배열 포인터
} ArrayGraph;


// �׷��� ����
ArrayGraph* createArrayGraph(int maxVertexCount);
ArrayGraph* createArrayDirectedGraph(int maxVertexCount);

// �׷��� ����
void deleteArrayGraph(ArrayGraph* pGraph);

// ���� �׷��� ���� �Ǵ�
int isEmptyAG(ArrayGraph* pGraph);

// ��� �߰�
int addVertexAG(ArrayGraph* pGraph, int vertexID);

// ���� �߰�
int addEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID);
int addEdgewithWeightAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID, int weight);

// ����� ��ȿ�� ����.
int checkVertexValid(ArrayGraph* pGraph, int vertexID);

// ��� ����
int removeVertexAG(ArrayGraph* pGraph, int vertexID);

// ���� ����
int removeEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID);

// �׷��� ���� ���
void displayArrayGraph(ArrayGraph* pGraph);
#endif

#ifndef _COMMON_GRAPH_DEF_
#define _COMMON_GRAPH_DEF_

#define USED				1
#define NOT_USED			0

#define SUCCESS				1
#define FAIL				0

#define TRUE				1
#define FALSE				0

#define GRAPH_UNDIRECTED	1
#define GRAPH_DIRECTED		2
#endif
