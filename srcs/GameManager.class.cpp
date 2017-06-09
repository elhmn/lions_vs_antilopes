#include <iostream>
#include "GameManager.class.h"
#include "Game.class.h"
#include "RenderManager.class.h"
#include "Object.class.h"
#include "types.h"
#include "error.h"

/*
** Non member variables
*/

bool				GameManager::_verbose = false;
GameManager		*GameManager::_instance = NULL;

/*
** Constructors
*/

GameManager::GameManager(void)
{
	if (GameManager::_verbose)
	{
		std::cout << "GameManager constructor called !" << std::endl;
	}
}

/*
** Destructors
*/

GameManager::~GameManager(void)
{
	if (GameManager::_verbose)
	{
		std::cout << "GameManager destructor called" << std::endl;
	}
	//destroy every data
}

/*
** Singleton getInstance
*/

GameManager			*GameManager::getInstance(void)
{
	if (!GameManager::_instance)
	{
		if (!(GameManager::_instance = new GameManager()))
			ERROR("BAD ALLOC");
	}
	return (GameManager::_instance);
}

/*
** Actions
*/

static t_pos			*setTab(t_pos *tab, int x, int y)
{
	tab[0].setPos(x, y + 1);
	tab[1].setPos(x, y - 1);
	tab[2].setPos(x + 1, y);
	tab[3].setPos(x - 1, y);
	tab[4].setPos(x - 1, y + 1);
	tab[5].setPos(x - 1, y - 1);
	tab[6].setPos(x + 1, y - 1);
	tab[7].setPos(x + 1, y + 1);
	return (tab);
}

static void				fightController(void)
{
	t_pos			tab[8];
	int				count;
	Object			**o;
	char			**map;
	char			car;
	int				x;
	int				y;
	int				b_x;
	int				b_y;
	int				w;
	int				h;
	int				n;

	o = Game::getInstance()->getObjects();
	map = Game::getInstance()->getMap()->getTab();
	w =  Game::getInstance()->getMap()->getWidth();
	h =  Game::getInstance()->getMap()->getHeight();
	count = Object::getCount();
	for (int i = 0; i < count; i++)
	{
		x = o[i]->getPos().x;
		y = o[i]->getPos().y;
		setTab(tab, x, y);
		n = 0;

		for(int j = 0; j < 8; j++)
		{
			b_x = tab[j].x;
			b_y = tab[j].y;
			if (!(b_x >= 0 && b_x < w && b_y >= 0 && b_y < h))
				continue ;
			if (o[i]->getType() == ANTILOPE)
			{
				if (M_LION == map[b_y][b_x])
					n++;
			}
			if (o[i]->getType() == LION)
			{
				if (M_ANTILOPE == map[tab[j].y][tab[j].x])
					n++;
			}
		}
		if (o[i]->getType() == ANTILOPE)
		{
			if (n >= 1)
			{
				map[y][x] = M_EMPTY;
				o[i]->isAlive = false;
				if (o[i]->hasFlag)
				{
					t_pos p;

					p = Game::getInstance()->getLions()->originFlag;
					map[p.y][p.x] = M_FLAG_L;
					o[i]->hasFlag = false;
					Game::getInstance()->getAntilopes()->hasFlag = false;
					Game::getInstance()->getLions()->ownFlag = true;
				}
			}
		}
		else if (o[i]->getType() == LION)
		{
			if (n >= 4)
			{
				map[y][x] = M_EMPTY;
				o[i]->isAlive = false;
				if (o[i]->hasFlag)
				{
					t_pos p;

					p = Game::getInstance()->getAntilopes()->originFlag;
					map[p.y][p.x] = M_FLAG_A;
					o[i]->hasFlag = false;
					Game::getInstance()->getLions()->hasFlag = false;
					Game::getInstance()->getAntilopes()->ownFlag = true;
				}
			}
		}
	}
}

void					GameManager::update(void)
{
	fightController();
}
