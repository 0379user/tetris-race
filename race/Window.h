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


class AbsWindow
{
public:
	virtual void show() const = 0;
	virtual void modificate(std::vector<Object*>& objects) = 0;
	virtual void show_start_logo() = 0;
	virtual void show_gameover_logo() = 0;
	virtual void show_end_logo() = 0;
};

class Window : public AbsWindow
{
public:
	Window();//work with file
public:
	void show() const override;
	void init();
	void modificate(std::vector<Object*> & objects) override;
	void show_start_logo() override;
	void show_gameover_logo() override;
	void show_end_logo() override;
public:
	char win_arr[HEIGHT][WEIGHT];
	char clean_arr[HEIGHT][WEIGHT];
};



/*
class SFML : public AbsWindow
{
public:
	void show() const override;
	void init();
	void modificate(std::vector<Object*>& objects) override;
	void show_start_logo() override;
	void show_gameover_logo() override;
	void show_end_logo() override;
};
*/