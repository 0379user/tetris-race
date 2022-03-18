#pragma once
#include <conio.h> // _kbhit()  _getch()
#include "Game.h"
 
/*
			LEFT = 0,
			RIGHT,
			UP,
			DOWN,
			ENTER,
			ESC,
			ZERO
*/

 

namespace System
{
	class Input
	{
	public:

		enum class event_key
		{
			LEFT = 0,
			RIGHT,
			UP,
			DOWN,
			ENTER,
			ESC,
			ZERO
		};
		Input::event_key input()
		{
			if (_kbhit())
			{
				switch (_getch())
				{
				case 'a':   pressed_key = event_key::LEFT; break;
				case 228:  pressed_key = event_key::LEFT;   break;
				case 'd':  pressed_key = event_key::RIGHT;  break;
				case 162:  pressed_key = event_key::RIGHT;  break;

				case 'w': pressed_key = event_key::UP;     break;
				case 230: pressed_key = event_key::UP;     break;
				case 's': pressed_key = event_key::DOWN;   break;
				case 235: pressed_key = event_key::DOWN;   break;

				case 13: pressed_key = event_key::ENTER;   break;
				case 27: pressed_key = event_key::ESC;     break;
				case ' ': break;
				default:pressed_key = event_key::ZERO;
					break;
				}

			}
			return  pressed_key;
		};
	private:
		event_key pressed_key;
	};//class Input
	
	void render()
	{
	//show();
	}
	void update() 
	{
	//	logic();
	//	input();
	}






}

	//namespace system
	
namespace procedure_version
{
	//window
	static char win_arr[HEIGHT][WEIGHT];
	
	void  init()
	{

		for (int i = 0; i < HEIGHT; i++)
		{
			for (int j = 0; j < WEIGHT; j++)
			{
				win_arr[i][j] = ' ';
			}
		}

	}
	
	void show() 
	{
		system("cls");
		for (int i = 0; i < HEIGHT; i++)
		{
			for (int j = 0; j < WEIGHT; j++)
			{
				std::cout << win_arr[i][j];
			}
		}

	};
	

	static 	event_key pressed_key = ZERO;

	enum  event_key
	{
		LEFT = 0,
		RIGHT,
		UP,
		DOWN,
		ENTER,
		ESC,
		ZERO
	};

	void input()
	{
		if (_kbhit())
		{
			switch (_getch())
			{
			case 'a':  pressed_key = event_key::LEFT;   break;
			case 228:  pressed_key = event_key::LEFT;   break;
			case 'd':  pressed_key = event_key::RIGHT;  break;
			case 162:  pressed_key = event_key::RIGHT;  break;

			case 'w': pressed_key = event_key::UP;     break;
			case 230: pressed_key = event_key::UP;     break;
			case 's': pressed_key = event_key::DOWN;   break;
			case 235: pressed_key = event_key::DOWN;   break;

			case 13: pressed_key = event_key::ENTER;   break;
			case 27: pressed_key = event_key::ESC;     break;
			case ' ': break;
			default:pressed_key = event_key::ZERO;
				break;
			}

		}
		//return  pressed_key;
	};
	
	void update(){}
	void render(){}





}