#define  _CRT_SECURE_NO_WARNINGS 
#include "game.h"
//��ʼ��
void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}
//��ӡ
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			//��ӡ����
			printf(" %c ", board[i][j]);
			if(j < col - 1)
				printf("|");
		}
		printf("\n");
		//��ӡ�ָ���
		if (i < col - 1)
		{
			for (j = 0; j < col; j++)
			{
				//��ӡ����
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}

//����ƶ�
void player_move(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("������壨���������꣩>");
		scanf("%d %d", &x, &y);
		if (x > 0 && x <= row && y > 0 && y <= col)
		{
			if (board[x - 1][y - 1] = ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
		}
		else
		{
			printf("���볬�����̷�Χ������������\n");
		}
	}
}

//�����ƶ�
void computer_move(char board[ROW][COL], int row, int col)
{
	int num1 = 0;
	int num2 = 0;
	while (1)
	{
		printf("��������\n");
		num1 = rand() % row;
	    num2 = rand() % col;
		if (board[num1][num2] = ' ')
		{
			board[num1][num2] = '#';
			break;
		}
	}
	
}

//�ж������Ƿ�����
static int is_full(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;
}

char is_win(char board[ROW][COL], int row, int col)
{
	int i = 0;
	//��
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
		{
			return board[i][1];
		}
	}
	//��
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
		{
			return board[1][i];
		}
	}
	//�Խ���
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][i] != ' ')
	{
		return board[1][1];
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][i] != ' ')
	{
		return board[1][1];
	}
	//�����Ƿ�����
	if (is_full(board, ROW, COL) == 1)
	{
		return 'Q';
	}
	
	return 'C';
}