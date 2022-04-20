#define  _CRT_SECURE_NO_WARNINGS 
#include "game.h"
void menu()
{
	printf("———————————********************———————————\n");
	printf("—————————*********1.play*********—————————\n");
	printf("—————————*********0.exit*********—————————\n");
	printf("———————————********************———————————\n");
}

void game()
{
	char ret = 0;
	char board[ROW][COL] = { 0 };
	//初始化
	InitBoard(board, ROW, COL);
	//打印
	DisplayBoard(board, ROW, COL);
	while (1)
	{
		//玩家移动
		player_move(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = is_win(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		//电脑移动
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
		printf("玩家赢！");
	}
	else if (ret = '#')
	{
		printf("电脑赢！");
	}
	else
	{
		printf("平局！");
	}
}

void test()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("输入数字->");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
		}
	} while (input);
}
//
int main()
{
	test();
	return 0;
}