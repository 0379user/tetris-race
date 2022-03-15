#pragma once
#include <iostream>
#include <vector>
#include "Objects.h"

#define WEIGHT 80
#define HEIGHT 25

#define WEIGHT_GAME_SCREEN_BEGIN 1
#define WEIGHT_GAME_SCREEN_END 30
//
class Object;


namespace Core
{
	void setConsole();
}

class Window
{
public:
	Window();//work with file
public:
	void show() const;
	void init();
	void modificate(std::vector<Object*> & objects);
	void show_start_logo();
	void show_gameover_logo();
	void show_end_logo();
public:
	char win_arr[HEIGHT][WEIGHT];
	char clean_arr[HEIGHT][WEIGHT];
};

