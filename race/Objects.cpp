#include "Objects.h"
#include "Window.h"
 
//
Car::Car()
{
	x = 20;
	y = WEIGHT_GAME_SCREEN_END /2;
	live = true;
}
void Car::create(Window * w)
{
		w->win_arr[x][y] =		'*';
		w->win_arr[x+1][y-1] =  '*';
		w->win_arr[x+1][y] =	'*';
		w->win_arr[x+1][y+1] =  '*';
		w->win_arr[x+2][y-1] =  '*';
		w->win_arr[x+2][y+ 1] = '*';
}

void Car::move(Object::mv mov)
{
	if (mov==Object::mv::LEFT)
	{ 
		if(y-1== WEIGHT_GAME_SCREEN_BEGIN){}
		else
		{
			y--;
		}
	}
	if (mov == Object::mv::RIGHT)
	{
		if(y+1== WEIGHT_GAME_SCREEN_END){}
		else
		{
			y++;
		}
	}
	if (mov == Object::mv::DOWN)
	{
		if (x + 3 == HEIGHT) 
		{
			live = false;
		}
		else
		{
			x++;
		}
	}
}

Dask_info::Dask_info(std::string s)
{
	live = true;
	x = 3;
	y = 44;
	name = s;
	score = 0;
	level = 0;
}

void Dask_info::create(Window* w)
{
	for (int i = 0, it = y+1; i < name.size(); i++, it++)
	{
		w->win_arr[x][it]= name[i];
	}
	//score making
	w->win_arr[x+1][y+1] = magic_return_char_from_int (score / 100);
	w->win_arr[x + 1][y + 2] = magic_return_char_from_int(score % 100/10);
	w->win_arr[x + 1][y + 3] = magic_return_char_from_int(score % 10);
	//level
	w->win_arr[x + 2][y + 1] = magic_return_char_from_int (level / 100);
	w->win_arr[x + 2][y + 2] = magic_return_char_from_int( level%100/10);
	w->win_arr[x + 2][y + 3] = magic_return_char_from_int( level % 10);






//	live = false;
}

void Dask_info::move(Object::mv mov) {} //not using function



char magic_return_char_from_int(int value)

{
	char x;
	switch (value)
	{
	case 0: x= '0'; break;
	case 1: x = '1'; break;
	case 2: x = '2'; break;
	case 3: x = '3'; break;
	case 4: x = '4'; break;
	case 5: x = '5'; break;
	case 6: x = '6'; break;
	case 7: x = '7'; break;
	case 8: x = '8'; break;
	case 9: x = '9'; break;
	default:
		x = '0'; break;
	}
	return x;
}