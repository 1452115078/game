#define  _CRT_SECURE_NO_WARNINGS 
#include "game.h"
void menu()
{
	printf("***************\n");
	printf("*****1.play****\n");
	printf("*****0.exit****\n");
	printf("***************\n");
}
void game()
{
	
	char mine[ROWS][COLS] = { 0 };//'1'
	char show[ROWS][COLS] = { 0 };//'0'
	
	//初始化
	Initboard(mine, ROWS, COLS, '0');
	Initboard(show, ROWS, COLS, '*');
	Displayboard(show, ROW, COL);

	//mine不轻易打印
	//Displayboard(mine, ROW, COL);
	
	//布置mine
	setmine(mine, ROW, COL);
	//Displayboard(mine, ROW, COL);

	//找mine
	Findmine(mine, show, ROW, COL);
	//Displayboard(show, ROW, COL);

}
int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("请输入选项->");
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
	
	return 0;
}