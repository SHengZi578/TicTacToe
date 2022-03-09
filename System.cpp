#include "TicTacToe.h"

//定义隐藏光标函数
void showCursor(bool bolean)
{
	CONSOLE_CURSOR_INFO cursor;
	cursor.bVisible = bolean;
	cursor.dwSize = sizeof(cursor);
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(handle, &cursor);
}

void input()
{
	unsigned int input;
	while (1) {
		if (cin >> input)
			break;
		else
		{
			cout << "error, please try again." << endl;
			cin.clear();
			cin.ignore(8192, '\n');
			continue;
		}
	}

	switch (input)
	{
	case 1:
	{
		TicTacToe TTT;

		srand((unsigned)time(NULL));
		unsigned int rows, columns;

		TTT.whoseRound = rand() % 2;
		if (TTT.whoseRound)
			goto AI;
		while (1)
		{
			if (TTT.showTheEnd())
				return;

			while (1) {
				if (cin >> rows >> columns && TTT.setDots(rows - 1, columns - 1))
					break;
				else
				{
					cout << "error, please try again." << endl;

					cin.clear();
					cin.ignore(4096, '\n');

					continue;
				}
			}

			if (TTT.showTheEnd())
				return;
		AI:
			srand((unsigned)time(NULL));
			Sleep(rand() % 1200 + 500);

			TTT.AI_setDots();
		}
	}
	case 2:
	{
		TicTacToe TTT;
		while (1)
		{
			if (TTT.showTheEnd())
				return;

			unsigned int rows, columns;

			while (1) {
				if (cin >> rows >> columns)
					break;
				else
				{
					cout << "error, please try again." << endl;

					cin.clear();
					cin.ignore(4096, '\n');

					continue;
				}
			}

			TTT.setDots(rows - 1, columns - 1);

			if (TTT.showTheEnd())
				return;
		}
	}
	case 3:
	{
		int num;
		while (1) {
			if (cin >> num)
				break;
			else
			{
				cout << "error, please try again." << endl;

				cin.clear();
				cin.ignore(4096, '\n');

				continue;
			}
		}
		if (num == 8)
		{
			TicTacToe::_3_8_Mode = true;
		}
		else
		{
			break;
		}
	}
	default:
		break;
	}
}

int main()
{
	showCursor(false);
	while (1)
	{
		TicTacToe::showMenu();
		input();
		system("cls");
	}

	return 0;
}