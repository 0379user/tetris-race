#pragma once
#include <conio.h> // _kbhit()  _getch()

 
class Game;

namespace Core
{
	class Input
	{
	public:
		void input(Game *g);
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
		event_key pressed_key;

	};
}