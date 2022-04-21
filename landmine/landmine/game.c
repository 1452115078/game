#define  _CRT_SECURE_NO_WARNINGS 
#include "game.h"

//��ʼ��
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

//��ӡmine��δ���õ�mine
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


//����mine
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
		printf("��������->");
		printf("\n");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("�㱻��ը����\n");
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
			printf("����Ƿ�\n");
		}
	}
}
