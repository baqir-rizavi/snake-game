#pragma once

#include "snake.h"
#include "fruit.h"
#include <conio.h>
#include <Windows.h>
using namespace std;

class game
{
	int score;
	bool game_over;
	int width;
	int height;
	snake s;
	fruit f;
	char next_input;
public:
	game() : game(30, 15)
	{}
	game(int w, int h) : width(w), height(h), game_over(false), score(0), f(w, h), s(w / 2, h / 2)
	{}
	void print_current_situation()
	{
		bool ok = 0;
		system("cls");
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				point p(j, i);
				if (i == 0 || i == height - 1)
				{
					cout << '-';
				}
				else if (j == 0 || j == width - 1)
				{
					cout << '|';
				}
				else if (s.tail[0] == p)
				{
					cout << 'O';
				}
				else if (f.position == p)
				{
					cout <<'$';
				}
				else 
				{
					for (int t = 1; t < s.length; t++)
					{
						ok = s.tail[t] == p;
						if (ok)
						{
							cout << '#';
							break;
						}
					}
					if (!ok)
					{
						cout << ' ';
					}
				}
			}
			cout << endl;
		}
		cout << "score:" << score << endl;
	}
	void take_input()
	{
		if (_kbhit())
		{
			next_input = _getch();
		}
	}
	void on_input_apply_logic()
	{
		if (s.tail[0] == f.position)
		{
			score += 50;
			f.reset();
			s.length++;
			cout << '\a';
		}
		point temp1, temp2;
		temp1 = s.tail[0];
		for (int i = 1; i < s.length; i++)
		{
			temp2 = s.tail[i];
			s.tail[i] = temp1;
			temp1 = temp2;
		}
		switch (next_input)
		{
		case 72:
			s.tail->y--;
			break;
		case 75:
			s.tail->x--;
			break;
		case 80:
			s.tail->y++;
			break;
		case 77:
			s.tail->x++;
			break;
		case ' ':
			game_over = true;
			return;
		}
		if (s.tail->x == 0 || s.tail->x == width - 1 || s.tail->y == 0 || s.tail->y == height-1)
		{
			game_over = true;
		}
	}
	void run()
	{ 
		char option='y';
		while (option == 'y')
		{
			game_over = false;
			s.length = 1;
			score = 0;
			s.tail[0] = point(width / 2, height / 2);
			next_input = '0';
			while (!game_over)
			{
				print_current_situation();
				take_input();
				on_input_apply_logic();
				Sleep(90);
			}
			cout << "\n!!!GAME OVER!!!\n";
			cout << "do you want to play again (y/n)? ";
			cin >> option;
		}
	}
};
