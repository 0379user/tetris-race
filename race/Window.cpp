#include "Window.h"
#include <fstream>
#include <string>
#include <iostream>

#include <windows.h> //libra for setCoinsole



namespace Core
{
	void setConsole()
	{
		HANDLE hWnd = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD bufferSize = { WEIGHT, HEIGHT };
		SetConsoleScreenBufferSize(hWnd, bufferSize);
		HWND hWindowConsole = GetConsoleWindow();
		MoveWindow(hWindowConsole, 80, 80, 10 * WEIGHT, 14 * HEIGHT, true);
	}
}

Window::Window()//work with file
{
	std::ifstream SCREEN("screen.txt");
	std::string str;
	int h = 0;
	if (!SCREEN.is_open()){std::cout<<"error, file screen.txt is not opened";}

	while (getline(SCREEN, str))
	{
		for (int i = 0; i < 80; i++)
		{
			clean_arr[h][i] = str[i];
		}
		h++;
	}

	SCREEN.close();
	init();
}

void Window::show()const
{
	system("cls");
for (int i = 0; i < HEIGHT; i++)
		{
			for (int j = 0; j < WEIGHT; j++)
			{
				std::cout << win_arr[i][j];
			}
		}
	
}

void Window::init()
{

		for (int i = 0; i < HEIGHT; i++)
		{
			for (int j = 0; j < WEIGHT; j++)
			{
				win_arr[i][j] = clean_arr[i][j];
			}
		}
	
}

void Window::modificate(std::vector<Object*>  & objects)
{
	for (auto& el : objects)
	{
		if (el->is_live())
		{
			el->create(this);
		}
	}
	  
}

void Window::show_start_logo()
{
	std::cout << "\n\n\n\n\n\n\t\t\t\t";
	std::cout << "show_start_logo\n";
}

void Window::show_gameover_logo()
{
	std::cout << "\n\n\n\n\n\n\t\t\t\t";
	std::cout << "show_gameover_logo\n";
}

void Window::show_end_logo()
{
	std::cout << "\n\n\n\n\n\n\t\t\t\t";
	std::cout << "show_end_logo\n";
}

