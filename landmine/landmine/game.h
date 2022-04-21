#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Mine_easy 10
#define Mine_hard 50
#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2

//初始化
void Initboard(char board[ROWS][COLS], int row, int col, char set);

//打印
void Displayboard(char board[ROWS][COLS], int row, int col);

//布置
void setmine(char board[ROWS][COLS],int row, int col);

//找mine
void Findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
