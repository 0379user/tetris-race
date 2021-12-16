#include "Window.h"
#include <fstream>
#include <string>
#include <iostream>

#include <windows.h>

Window::Window()//work with file
{
	/// <summary>
	/// /set console
	/// </summary>
	//HANDLE hWnd = GetStdHandle(STD_OUTPUT_HANDLE);
	//COORD bufferSize = { 80, 50 };
	//SetConsoleScreenBufferSize(wHnd, bufferSize);
	//
	std::ifstream SCREEN("screen.txt");
	std::string str;
	int h = 0;
	if (!SCREEN.is_open()){std::cout<<"errooooooooooooooooor";}

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

