#include <iostream>
#include <chrono>
#include <conio.h> // _kbhit()  _getch()
#include "Window.h"
#include "Objects.h"
#include "Game.h"

//  game menu/setup/
//  stack of objects
//
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
			break;
		}
	}
	system("pause");
	return 0;
}