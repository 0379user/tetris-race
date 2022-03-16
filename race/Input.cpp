#include "Input.h"
#include "Game.h"


namespace Core
{
	
	void Input::input(Game* g)
	{
		if (_kbhit())
		{
			switch (_getch())
			{
//case 'd': move_vec = Object::mv::RIGHT; rend_screen = true; break; orig
			case 'a': pressed_key = event_key::LEFT;  g->rend_screen = true; break;
			case 228: pressed_key = event_key::LEFT;  g->rend_screen = true; break;
			case 'd': pressed_key = event_key::RIGHT; g->rend_screen = true; break;
			case 162: pressed_key = event_key::RIGHT; g->rend_screen = true; break;
			
			case 'w': pressed_key = event_key::UP;    g->rend_screen = true; break;
			case 230: pressed_key = event_key::UP;    g->rend_screen = true; break;
			case 's': pressed_key = event_key::DOWN;  g->rend_screen = true; break;
			case 235: pressed_key = event_key::DOWN;  g->rend_screen = true; break;

			case 13: pressed_key = event_key::ENTER;  g->rend_screen = true; break;
			case 27: pressed_key = event_key::ESC; g->status_game = (g->status_game == Game::state::GAME_RUN) ? Game::state::MENU : Game::state::GAME_RUN;  g->rend_screen = true; break;
//need inproveee logic 
			case ' ': g->status_game = Game::state::EXIT; g->rend_screen = true; break;
			default:pressed_key = event_key::ZERO;
				break;
			}
			if (g->status_game == Game::state::GAME_RUN)
			{
				g->objects[0]->move(static_cast<Object::mv>(pressed_key));
			}
		}

	}
}
