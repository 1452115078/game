#pragma once
#define ROW 3
#define COL 3
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//初始化
void InitBoard(char board[ROW][COL], int row, int col);
//打印
void DisplayBoard(char board[ROW][COL], int row, int col);
//玩家移动
void player_move(char board[ROW][COL], int row, int col);
//电脑移动
void computer_move(char board[ROW][COL], int row, int col);

char is_win(char board[ROW][COL], int row, int col);