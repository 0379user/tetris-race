#include <iostream>
#include <chrono>
#include <conio.h> // _kbhit()  _getch()
#include "Window.h"
#include "Objects.h"
#include "Game.h"


//task
//
// need add function size screen
// other window.h
//  
//  game menu/add setup setup/ save function
//  stack of objects
// start and end game screen
 

int main()
{
	Game game;
	
	while (true) 
	{
		if (game.status_game == Game::state::MENU)
		{
			game.menu();
		}
		if(game.status_game==Game::state::GAME_RUN)
		{
			game.run();
		}
		if (game.status_game == Game::state::EXIT)
		{
			system("cls");
			std::cout << "good bye my friend\n";
			game.end_logo();
			break;
		}
		if (game.status_game == Game::state::GAME_OVER)
		{
			system("cls");
			game.game_over();
			game.status_game = Game::state::MENU;
			break;
		}

	}
	system("pause");
	return 0;
}