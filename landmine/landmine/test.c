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
	
	//��ʼ��
	Initboard(mine, ROWS, COLS, '0');
	Initboard(show, ROWS, COLS, '*');
	Displayboard(show, ROW, COL);

	//mine�����״�ӡ
	//Displayboard(mine, ROW, COL);
	
	//����mine
	setmine(mine, ROW, COL);
	//Displayboard(mine, ROW, COL);

	//��mine
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
		printf("������ѡ��->");
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
	
	return 0;
}