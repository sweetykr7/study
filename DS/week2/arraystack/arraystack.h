#ifndef _ARRAY_STACK_
#define _ARRAY_STACK_

# include <stdlib.h>
# include <stdio.h>

typedef struct ArrayStackNodeType
{
	int data;
} node;

typedef struct ArrayStackType
{
	int maxElementCount;		
	int currentElementCount;	
	node *pElement;	
} ArrayStack;

ArrayStack* createArrayStack();
int pushLS(ArrayStack* pStack, node element);
node* popLS(ArrayStack* pStack);
node* peekLS(ArrayStack* pStack);
void deleteArrayStack(ArrayStack* pStack);
int isArrayStackFull(ArrayStack* pStack);
int isArrayStackEmpty(ArrayStack* pStack);

#endif

#ifndef _COMMON_STACK_DEF_
#define _COMMON_STACK_DEF_

#define TRUE		1
#define FALSE		0

#endif