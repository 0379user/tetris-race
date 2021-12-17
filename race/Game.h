#pragma once
#include "Window.h"
#include "Objects.h"

class Window;
class Object;
class Car;

//
class Game
{
public:
	enum class state { GAME_RUN = 0, MENU, EXIT, GAME_OVER };
	Game() : 
		rend_screen(1),
		level(0),
		level_time(1.8) ,
		status_game(Game::state::MENU)
	{
		objects.push_back(new Car()); // start position player
		start_time = std::chrono::high_resolution_clock::now();

		//logo
		win.show_start_logo();
		system("pause");
		system("cls");
		//logo

		///name
		std::cout << "\n\n\n\n\n\n\n\n";
		std::cout << "\t\t\t";
		std::cout << "inter your name\n";
		std::cout << "\t\t\t";
		std::cin >> name;
		objects.push_back(new Dask_info(name));
		//name
	}
public:
	void menu()
	{
		system("cls");
		int val_menu = 0;
		std::string cursor = "--> ";
		std::string space = "    ";
		while (status_game == Game::state::MENU) {
			input();
			if (rend_screen) {
				val_menu = (move_vec == Object::mv::DOWN) ? ++val_menu :
					       (move_vec == Object::mv::UP)   ? --val_menu :
					       (move_vec == Object::mv::ENTER)? val_menu   : val_menu;
				val_menu =  (val_menu < 0) ? 0 :
				        	(val_menu > 2) ? 2 : val_menu;

				system("cls");
				std::cout << "\n\n\n\n\n\n\n\n";
				std::cout << "\t\t\t"; std::cout << ((val_menu == 0) ? cursor : space) << " START GAME\n";
				std::cout << "\t\t\t"; std::cout << ((val_menu == 1) ? cursor : space) << " SETUP\n";
				std::cout << "\t\t\t"; std::cout << ((val_menu == 2) ? cursor : space) << " EXIT\n";
				rend_screen = false; 
				if (val_menu == 2 && move_vec== Object::mv::ENTER)
				{ 
					status_game = Game::state::EXIT;
					break;
				}
				if (val_menu == 1 && move_vec == Object::mv::ENTER)
				{
					//status_game = Game::state::EXIT;menuuuuuuuuuu
					break;
				}
				if (val_menu == 0 && move_vec == Object::mv::ENTER)
				{
					status_game = Game::state::GAME_RUN;
					break;
				}
			}
		}
		
	}
	void run() 
	{
		if(rend_screen)
		{
			win.init();
			win.modificate(objects);
			win.show();
			rend_screen = 0;
		}
		input();
		logic();
		
	}
 private:
	void input()
	{
		if (_kbhit())
		{
			switch (_getch())
			{
			case 'a': move_vec = Object::mv::LEFT;  rend_screen = true; break;
			case 228: move_vec = Object::mv::LEFT;  rend_screen = true; break;
			case 'd': move_vec = Object::mv::RIGHT; rend_screen = true; break;
			case 162: move_vec = Object::mv::RIGHT; rend_screen = true; break;

			case 'w': move_vec = Object::mv::UP; rend_screen = true; break;
			case 230: move_vec = Object::mv::UP; rend_screen = true; break;
			case 's': move_vec = Object::mv::DOWN; rend_screen = true; break;
			case 235: move_vec = Object::mv::DOWN; rend_screen = true; break;

			case 13: move_vec = Object::mv::ENTER; rend_screen = true; break;
			case 27: move_vec = Object::mv::ESC; status_game = (status_game == Game::state::GAME_RUN) ? Game::state::MENU : Game::state::GAME_RUN;  rend_screen = true; break;

			case ' ': status_game=Game::state::EXIT; break;
			default:move_vec = Object::mv::ZERO;
				break;
			}
			if (status_game == Game::state::GAME_RUN)
			{
				objects[0]->move(move_vec);
			}
		}
		
	}
	void logic()
	{
		end_time= std::chrono::high_resolution_clock::now();
		result_time = end_time - start_time;
		full_time = result_time.count();
		if (full_time > level_time)
		{
			start_time = end_time;
			rend_screen = true;
			score++;
			level = score / 3;
		}
		static_cast<Dask_info*>(objects[1])->level = level;
		static_cast<Dask_info*>(objects[1])->score = score;

		if (full_time > 1.0) 
		{
			//score++;
		}
	}
public:
	void end_logo()
	{
		win.show_end_logo();
	}
public:
	state status_game;
	std::vector<Object*> objects; 
	bool rend_screen;
private:
	Window win;
	Object::mv move_vec;
	float level_time;
	float full_time;
	int level;
	int score;
	std::string name;
private:
	std::chrono::steady_clock::time_point start_time, end_time; // from lib mytimer
	std::chrono::duration<float> result_time;
};


