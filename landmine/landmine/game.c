#define  _CRT_SECURE_NO_WARNINGS 
#include "game.h"

//初始化
void Initboard(char board[ROWS][COLS], int row, int col, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = set;
		}
	}
}

//打印mine与未布置的mine
void Displayboard(char board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	printf("---------------------\n");
	for (j = 0; j <= col; j++)
	{
		printf(" %d", j);
	}
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf(" %d ", i);
		for (j = 1; j <= col; j++)
		{
			
			printf("%c ",board[i][j]);
		}
		printf("\n");
	}
	printf("---------------------\n");
}


//布置mine
void setmine(char board[ROWS][COLS], int row, int col)
{
	int count = Mine_easy;
	while (count)
	{
		int x = rand() % row + 1;
	    int y = rand() % col + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
		
	}
}
int Getmine(char mine[ROWS][COLS], int x, int y)
{
	return mine[x][y+1]+
		mine[x][y-1]+
		mine[x+1][y]+
		mine[x-1][y]+
		mine[x+1][y-1]+
		mine[x+1][y-1]+
		mine[x+1][y-1]+
		mine[x-1][y+1]
			-8 * '0';
}
void Findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("输入坐标->");
		printf("\n");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("你被雷炸死了\n");
				printf("\n");
				break;
			}
			else
			{
				int count = Getmine(mine, x, y);
				show[x][y] = count + '0';
				Displayboard(show, ROW, COL);
			}
		}
		else
		{
			printf("坐标非法\n");
		}
	}
}
