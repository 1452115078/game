#pragma once
#define ROW 3
#define COL 3
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//��ʼ��
void InitBoard(char board[ROW][COL], int row, int col);
//��ӡ
void DisplayBoard(char board[ROW][COL], int row, int col);
//����ƶ�
void player_move(char board[ROW][COL], int row, int col);
//�����ƶ�
void computer_move(char board[ROW][COL], int row, int col);

char is_win(char board[ROW][COL], int row, int col);