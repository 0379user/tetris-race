#pragma once
#include "Window.h"


char magic_return_char_from_int(int value); 

class Window;

class Object
{
public:
	enum class mv
	{
		LEFT=0,
		RIGHT,
		UP,
		DOWN,
		ENTER,
		ESC,
		ZERO
	};
	Object(): live(0) {}
	Object(int a, int b, bool l=false): x(a), y(b), live(l){}
	virtual ~Object(){}
public:
	virtual  void create(Window* w) = 0;
	virtual  void move(Object::mv mov) = 0;
public:
	inline bool is_live() { return live; }
	int x;
	int y;
	bool live;
};

class Car : public Object
{
public:
	Car(int x, int y, bool l):Object(x, y, l){}
	Car(); //standart constructor x 21 y 40
public:	
	void create(Window* w)  override;
	void move(Object::mv mov) override;
};

class Dask_info : public Object
{
public:
	
	Dask_info(std::string s);  
public:
	void create(Window* w)  override;
	void move(Object::mv mov) override;
	std::string name;
	int score;
	int level;
};

