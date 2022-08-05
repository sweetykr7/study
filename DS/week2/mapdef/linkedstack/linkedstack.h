#ifndef _LINKED_STACK_
#define _LINKED_STACK_

# include <stdlib.h>
# include <stdio.h>



// static int DIREC[4][2] = {
// 	{0, -1},	
// 	{1, 0},		
// 	{0, 1},		
// 	{-1, 0}		
// };

typedef struct MapPositionType
{
	int x;		
	int y;		
	int *direction;	
} MapPosition;

typedef struct StackNodeType
{
	MapPosition root;	
	struct StackNodeType* pLink;
} StackNode;

typedef struct LinkedStackType
{
	int			currentElementCount;	
	int			final_y;
	StackNode*  pTopElement;		
} LinkedStack;

LinkedStack* createLinkedStack();
int pushLS(LinkedStack* pStack, StackNode element);
StackNode* popLS(LinkedStack* pStack);
StackNode* peekLS(LinkedStack* pStack);
void deleteLinkedStack(LinkedStack* pStack);
int isLinkedStackFull(LinkedStack* pStack);
int isLinkedStackEmpty(LinkedStack* pStack);
void displayStack(LinkedStack *pStack);

#endif

#ifndef _COMMON_STACK_DEF_
#define _COMMON_STACK_DEF_

#define TRUE		1
#define FALSE		0

#endif