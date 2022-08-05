#include "mapdef.h"

static int map[8][8] = {
        { -1, 0, 1, 1, 1, 1, 1, 1 },
        { 1, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 1, 1, 0, 1, 1, 1, 1 },
		{ 1, 1, 1, 0, 1, 1, 1, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 1, 1, 1, 1, 1, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0 },
		{ 1, 1, 1, 1, 1, 1, 1, -2 }
    };

static int DIREC[4][2] = {
	{0, -1},	
	{1, 0},		
	{0, 1},		
	{-1, 0}		
};

void printMaze(int mazeArray[HEIGHT][WIDTH])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < HEIGHT)
	{
		while (i < WIDTH)
		{
			if (mazeArray[j][i] == 0)
				printf("%s ", "☐");
			else if (mazeArray[j][i] == 1)
				printf("%s ", "◼︎");
			else if (mazeArray[j][i] == 2)
				printf("%s ", "✓");
			else if (mazeArray[j][i] == -1)
				printf("%s ", "S");
			else if (mazeArray[j][i] == -2)
				printf("%s ", "E");
			i++;
		}
		printf("\n");
		i = 0;
		j++;
	}
}

int	pushLSMapPosition(LinkedStack *pStack, MapPosition data)
{
	StackNode	node;

	if (!pStack)
		return (0);
	node.root.x = data.x;
	node.root.y = data.y;
	node.root.direction = data.direction;
	pushLS(pStack, node);
	return (1);
}

int is_available_root(int mazeArray[HEIGHT][WIDTH], int x, int y)
{
	if (mazeArray[y][x] == 0)
		return (1);
	else if (mazeArray[y][x] == -2)
		return (-2);
	return (0);
}

int	is_same_root(LinkedStack *h, int x, int y)
{
	StackNode	*temp;

	temp = h->pTopElement;
	while (temp)
	{
		if (temp->root.x == x && temp->root.y == y)
			return (1);
		temp = temp->pLink;
	}
	return (0);
}

int get_direction(MapPosition *spos, MapPosition *epos, int mazeArray[HEIGHT][WIDTH], LinkedStack *h)
{
	if (epos->y != 7 && !is_same_root(h, spos->x, spos->y + 1) \
					&& (mazeArray[spos->y + 1][spos->x] == 0 || mazeArray[spos->y + 1][spos->x] == -2)\
					&& (spos->x != epos->x && spos->y + 1 != epos->y))
	{
		epos->x = spos->x;
		epos->y = epos->y + 1;
		epos->direction = DIREC[2];
		return (1);
	}
	else if (epos->x != 7 && !is_same_root(h, spos->x + 1, spos->y) \
			&& (mazeArray[spos->y][spos->x + 1] == 0 || mazeArray[spos->y][spos->x + 1] == -2)\
			&& (spos->x + 1 != epos->x && spos->y != epos->y))
	{
		epos->y = spos->y;
		epos->x = spos->x + 1;
		epos->direction = DIREC[1];
		return (1);
	}
	else if (epos->y != 0 && !is_same_root(h, spos->x, spos->y - 1) \
			&& (mazeArray[spos->y - 1][spos->x] == 0 || mazeArray[spos->y - 1][spos->x] == -2)\
			&& (spos->x != epos->x && spos->y - 1 != epos->y))
	{
		epos->y = spos->y - 1;
		epos->x = spos->x;
		epos->direction = DIREC[0];
		return (1);
	}
	else if (epos->x != 0 && !is_same_root(h, spos->x - 1, spos->y) \
			&& (mazeArray[spos->y][spos->x - 1] == 0 || mazeArray[spos->y][spos->x - 1] == -2)\
			&& (spos->x - 1 != epos->x && spos->y != epos->y))
	{
		epos->y = spos->y;
		epos->x = spos->x - 1;
		epos->direction = DIREC[3];
		return (1);
	}
	return (0);
}

int	*reverse_direction(int *direc)
{
	int	x;
	int	y;

	x = direc[0];
	y = direc[1];
	if (x == 0 && y == -1)
		return (DIREC[2]);
	else if (x == 1 && y == 0)
		return (DIREC[3]);
	else if (x == 0 && y == 1)
		return (DIREC[0]);
	else if (x == -1 && y == 0)
		return (DIREC[1]);
	return (0);
}


void findPath(int mazeArray[HEIGHT][WIDTH], MapPosition startPos, MapPosition endPos, LinkedStack *pStack)
{
	int	test;

	if (startPos.x == 3 && startPos.y == 4)
		test = 0;
	if (mazeArray[endPos.x][endPos.y] == -2)
	{
		pushLSMapPosition(pStack, endPos);
		return ;
	}
	if (is_same_root(pStack, endPos.x, endPos.y))
		get_direction(&startPos, &endPos, mazeArray, pStack);
	if (is_available_root(mazeArray, endPos.x, endPos.y))
	{
		pushLSMapPosition(pStack, endPos);
		startPos = endPos;
		endPos.x = endPos.x + endPos.direction[0];
		endPos.y = endPos.y + endPos.direction[1];
		findPath(mazeArray, startPos, endPos, pStack);
	}
	else
	{
		if (!get_direction(&startPos, &endPos, mazeArray, pStack))
		{			
			endPos = startPos;
			endPos.direction = reverse_direction(endPos.direction);
			endPos.x = startPos.x + endPos.direction[0];
			endPos.y = startPos.y + endPos.direction[1];
		}
		findPath(mazeArray, startPos, endPos, pStack);
	}
}

void showPath(LinkedStack *pStack, int mazeArray[HEIGHT][WIDTH])
{
	StackNode	*node;
	int			x;
	int			y;

	x = 0;
	y = 0;
	node = pStack->pTopElement;
	while (node)
	{
		x = node->root.x;
		y = node->root.y;
		if (mazeArray[y][x] != -1 && mazeArray[y][x] != -2)
			mazeArray[y][x] = 2;
		node = node->pLink;
	}
	printMaze(mazeArray);
}

int	main(void)
{
	LinkedStack *pStack;
	LinkedStack *temp;
	MapPosition sPos;
	MapPosition ePos;

	printMaze(map);
	pStack = createLinkedStack();
	temp = createLinkedStack();
	pStack->final_y = 7;
	sPos.x = 0;
	sPos.y = 0;
	sPos.direction = DIREC[1];
	ePos.x = 1;
	ePos.y = 0;
	ePos.direction = DIREC[1];
	pushLSMapPosition(pStack, sPos);
	findPath(map, sPos, ePos, pStack);
	pushLS_ALL(temp, pStack);
	printf("=========================\n");
	showPath(temp, map);
	//displayStack(temp);
}



//git test;
//git test;