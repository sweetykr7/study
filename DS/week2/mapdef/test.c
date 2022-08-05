#include "stdio.h"

int main(void)
{
	static int DIRECTION_OFFSETS[4][2] = {
	{0, -1},		
	{1, 0},			
	{0, 1},			
	{-1, 0}			
};
	printf("%p",DIRECTION_OFFSETS[1]);
	return (0);
}
