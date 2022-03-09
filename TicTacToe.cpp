#include "TicTacToe.h"

static void setColor(unsigned int color)
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, color);
}

int TicTacToe::isOver()
{
	for (int i = 0; i < 3; ++i)
	{
		if ((dots[i][0] == dots[i][1]) && (dots[i][1] == dots[i][2]) && ((dots[i][0] != blank) && (dots[i][1] != blank) && (dots[i][2] != blank)))
		{
			return 1;
		}
		else if ((dots[0][i] == dots[1][i]) && (dots[1][i] == dots[2][i]) && ((dots[0][i] != blank) && (dots[1][i] != blank) && (dots[2][i] != blank)))
		{
			return 1;
		}
		else if (((dots[0][0] == dots[1][1] && dots[1][1] != blank) && (dots[1][1] == dots[2][2])) || ((dots[0][2] == dots[1][1] && dots[1][1] != blank) && (dots[1][1] == dots[2][0])))
		{
			return 1;
		}
	}
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; j++)
		{
			if (dots[i][j] == blank)
				return 0;
		}
	}
	return 2;
}

TicTacToe::TicTacToe()
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			dots[i][j] = blank;
		}
	}
}

void TicTacToe::showMenu()
{
	if (_3_8_Mode)
		setColor(FOREGROUND_RED);
	cout << "欢迎来到井字棋" << endl;
	setColor(7);
	cout << "请选择你的模式: " << endl;
	cout << "1. AI模式" << endl;
	cout << "2. PVP模式" << endl;
}

void TicTacToe::showDots()
{
	if (_3_8_Mode)
		setColor(FOREGROUND_RED);
	cout << "-------" << endl;
	for (int i = 0; i < 3; ++i)
	{
		if (_3_8_Mode)
			setColor(FOREGROUND_RED);
		cout << '|';
		setColor(7);
		for (int j = 0; j < 3; ++j)
		{
			if (dots[i][j] == player1)
				setColor(FOREGROUND_GREEN);
			else
				setColor(FOREGROUND_BLUE | FOREGROUND_GREEN);
			cout << dots[i][j];
			setColor(7);
			if (_3_8_Mode)
				setColor(FOREGROUND_RED);
			cout << '|';
			setColor(7);
		}
		if (_3_8_Mode)
			setColor(FOREGROUND_RED);
		cout << "\n-------" << endl;
		setColor(7);
	}
}

int TicTacToe::showTheEnd()
{
	switch (isOver())
	{
	case 0:
		system("cls");
		showDots();
		return 0;
	case 1:
	{
		char as = whoseRound ? player1 : player2;
		system("cls");
		showDots();
		setColor(FOREGROUND_BLUE | FOREGROUND_RED);
		cout << as;
		setColor(FOREGROUND_GREEN | FOREGROUND_RED);
		cout << " 胜利" << endl;
		setColor(7);
		system("pause");
		return 1;
	}
	case 2:
		system("cls");
		showDots();
		cout << "平手" << endl;
		system("pause");
		return 2;
	default:
		return -1;
	}
}

bool TicTacToe::setDots(unsigned int rows, unsigned int columns)
{
	if (dots[rows][columns] == blank)
	{
		if (whoseRound == 0)
		{
			dots[rows][columns] = player1;
			whoseRound = 1;
		}
		else
		{
			dots[rows][columns] = player2;
			whoseRound = 0;
		}
		return true;
	}
	return false;
}

void TicTacToe::AI_setDots()
{
	int num = 0;
	int rows = -1;
	int columns = -1;
	//AI
	//直
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (dots[i][j] == player2)
				++num;
			else if (dots[i][j] == blank)
			{
				rows = i;
				columns = j;
			}
		}
		if (num == 2 && columns != -1)
		{
			setDots(rows, columns);
			return;
		}
		num = 0;
		rows = -1;
		columns = -1;

		if (num == 2 && columns != -1)
		{
			setDots(rows, columns);
			return;
		}
		num = 0;
		rows = -1;
		columns = -1;
	}
	//捺
	for (int i = 0; i < 3; i++)
	{
		if (dots[i][i] == player2)
			++num;
		else if (dots[i][i] == blank)
		{
			rows = i;
			columns = i;
		}
	}
	if (num == 2 && columns != -1)
	{
		setDots(rows, columns);
		return;
	}

	num = 0;
	rows = -1;
	columns = -1;
	//撇
	for (int i = 0; i < 3; i++)
	{
		if (dots[i][2 - i] == player2)
			++num;
		else if (dots[i][2 - i] == blank)
		{
			rows = i;
			columns = 2 - i;
		}
	}
	if (num == 2 && columns != -1)
	{
		setDots(rows, columns);
		return;
	}

	num = 0;
	rows = -1;
	columns = -1;
	//player
	//直
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (dots[i][j] == player1)
				++num;
			else if (dots[i][j] == blank)
			{
				rows = i;
				columns = j;
			}
		}
		if (num == 2 && columns != -1)
		{
			setDots(rows, columns);
			return;
		}
		num = 0;
		rows = -1;
		columns = -1;

		for (int j = 0; j < 3; j++)
		{
			if (dots[j][i] == player1)
				++num;
			else if (dots[j][i] == blank)
			{
				rows = j;
				columns = i;
			}
		}
		if (num == 2 && columns != -1)
		{
			setDots(rows, columns);
			return;
		}
		num = 0;
		rows = -1;
		columns = -1;
	}

	//捺
	for (int i = 0; i < 3; i++)
	{
		if (dots[i][i] == player1)
			++num;
		else if (dots[i][i] == blank)
		{
			rows = i;
			columns = i;
		}
	}
	if (num == 2 && columns != -1)
	{
		setDots(rows, columns);
		return;
	}

	num = 0;
	rows = -1;
	columns = -1;
	//撇
	for (int i = 0; i < 3; i++)
	{
		if (dots[i][2 - i] == player1)
			++num;
		else if (dots[i][2 - i] == blank)
		{
			rows = i;
			columns = 2 - i;
		}
	}
	if (num == 2 && columns != -1)
	{
		setDots(rows, columns);
		return;
	}

	vector < pair <int, int> > v;
	srand((unsigned)&v);
	if (((rand() % 7) < 2) && setDots(1, 1))
		return;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; j++)
		{
			if (dots[i][j] == blank)
				v.push_back(make_pair(i, j));
		}
	}
	setDots(v[rand() % v.size()].first, v[rand() % v.size()].second);
}

bool TicTacToe::_3_8_Mode = false;