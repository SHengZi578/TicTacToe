#pragma once
#include <iostream>
#include <Windows.h>
#include <vector>
#include <stdlib.h>
using namespace std;
class TicTacToe
{
private:
	char dots[3][3];

public:
	unsigned int whoseRound = 0;
	static bool _3_8_Mode;
	char blank = ' ', player1 = 'O', player2 = 'X';
	TicTacToe();
	static void showMenu();
	void showDots();
	bool setDots(unsigned int rows, unsigned int columns);
	void AI_setDots();
	int isOver();
	int showTheEnd();
};

