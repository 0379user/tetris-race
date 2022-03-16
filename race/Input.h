#pragma once
#include <conio.h> // _kbhit()  _getch()
#include "Game.h"
 


	class Input
	{
	public:
		
	void input() {
			if (_kbhit())
			{
				switch (_getch())
				{
					//case 'd': move_vec = Object::mv::RIGHT; rend_screen = true; break; orig
				    //case 'a': pressed_key = event_key::LEFT;  g->rend_screen = true; break;
				case 'a': pressed_key = event_key::LEFT;   break;
				case 228: pressed_key = event_key::LEFT;   break;
				case 'd': pressed_key = event_key::RIGHT;  break;
				case 162: pressed_key = event_key::RIGHT;  break;

				case 'w': pressed_key = event_key::UP;     break;
				case 230: pressed_key = event_key::UP;     break;
				case 's': pressed_key = event_key::DOWN;   break;
				case 235: pressed_key = event_key::DOWN;   break;

				case 13: pressed_key = event_key::ENTER;   break;
				case 27: pressed_key = event_key::ESC; break; // g->status_game = (g->status_game == Game::state::GAME_RUN) ? Game::state::MENU : Game::state::GAME_RUN;  g->rend_screen = true; break;
					//need inproveee logic 
				case ' ': break; // g->status_game = Game::state::EXIT; g->rend_screen = true; break;
				default:pressed_key = event_key::ZERO;
					break;
				}
				/*if (g->status_game == Game::state::GAME_RUN)
				{
					g->objects[0]->move(static_cast<Object::mv>(pressed_key));
				}*/
			}
			
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
		event_key pressed_key;

	};
	