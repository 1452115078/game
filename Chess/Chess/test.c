#define  _CRT_SECURE_NO_WARNINGS 
#include "game.h"
void menu()
{
	printf("����������������������********************����������������������\n");
	printf("������������������*********1.play*********������������������\n");
	printf("������������������*********0.exit*********������������������\n");
	printf("����������������������********************����������������������\n");
}

void game()
{
	char ret = 0;
	char board[ROW][COL] = { 0 };
	//��ʼ��
	InitBoard(board, ROW, COL);
	//��ӡ
	DisplayBoard(board, ROW, COL);
	while (1)
	{
		//����ƶ�
		player_move(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = is_win(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		//�����ƶ�
		computer_move(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = is_win(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret = '*')
	{
		printf("���Ӯ��");
	}
	else if (ret = '#')
	{
		printf("����Ӯ��");
	}
	else
	{
		printf("ƽ�֣�");
	}
}

void test()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("��������->");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
		}
	} while (input);
}
//
int main()
{
	test();
	return 0;
}