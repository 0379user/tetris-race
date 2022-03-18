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
	
	enum class state
	{
		GAME_RUN = 0,
		MENU,
		EXIT,
		GAME_OVER
	};
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
	static	event_key pressed_key = System::event_key::ZERO;
	static state game_state = System::state::GAME_RUN;
	Window win;
	bool rend=true;

	//int level;
	//int score;
	//int alive_objects;
	//std::string name;
	float level_time;
	float full_time;
	std::chrono::steady_clock::time_point start_time, end_time; // from lib mytimer
	std::chrono::duration<float> result_time;

	void input();
	void logic();
	void render();
	void update();






}

///defenition
 
namespace System
{
void input()
{
			if (_kbhit())
			{
				switch (_getch())
				{
				case 'a': pressed_key = event_key::LEFT;   break;
				case 228: pressed_key = event_key::LEFT;   break;
				case 'd': pressed_key = event_key::RIGHT;  break;
				case 162: pressed_key = event_key::RIGHT;  break;

				case 'w': pressed_key = event_key::UP;     break;
				case 230: pressed_key = event_key::UP;     break;
				case 's': pressed_key = event_key::DOWN;   break;
				case 235: pressed_key = event_key::DOWN;   break;

				case  13: pressed_key = event_key::ENTER;  break;
				case  27: pressed_key = event_key::ESC;    break;
				case ' ': System::game_state = System::state::EXIT; break;
				default : pressed_key = event_key::ZERO;   break;
				}
			}
};

	void logic()
	{
		end_time = std::chrono::high_resolution_clock::now();
		result_time = end_time - start_time;
		full_time = result_time.count();
		if (full_time > level_time)
		{
			//System::rend = true;
		}
		
		if (full_time > 4.0)
		{
			start_time = end_time;
			System::rend = true;
			//score++;
		}

	}

	void render()
	{
		if (rend)
		{
			System::win.show();
		}
		rend = false;
	}
	void update()
	{
		//	logic();
		//	input();
	}






}