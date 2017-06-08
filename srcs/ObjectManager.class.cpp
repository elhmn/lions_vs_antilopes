#include <iostream>
#include "ObjectManager.class.h"
#include "Map.class.h"
#include "Object.class.h"
#include "Game.class.h"
#include "Team.class.h"
#include "error.h"

/*
** Non member variables
*/

bool				ObjectManager::_verbose = false;
ObjectManager		*ObjectManager::_instance = NULL;

/*
** Constructors
*/

ObjectManager::ObjectManager(void)
{
	if (ObjectManager::_verbose)
	{
		std::cout << "ObjectManager constructor called !" << std::endl;
	}
}

/*
** Destructors
*/

ObjectManager::~ObjectManager(void)
{
	if (ObjectManager::_verbose)
	{
		std::cout << "ObjectManager destructor called" << std::endl;
	}
	//destroy every data
}

/*
** Singleton getInstance
*/

ObjectManager			*ObjectManager::getInstance(void)
{
	if (!ObjectManager::_instance)
	{
		if (!(ObjectManager::_instance = new ObjectManager()))
			ERROR("BAD ALLOC");
	}
	return (ObjectManager::_instance);
}

/*
** Actions
*/

void					ObjectManager::destroy(void)
{
	std::cout << "ObjectManager destroy !" << std::endl;//_DEBUG_//
}

void					ObjectManager::spawn(void)
{
	std::cout << "ObjectManager spwan !" << std::endl;//_DEBUG_//
}

static void				move(void)
{
	int				i;
	int				count;
	Object			**o;
	char			**map;
	char			car;
	int				x;
	int				y;
	int				w;
	int				h;

	i = -1;
	o = Game::getInstance()->getObjects();
	map = Game::getInstance()->getMap()->getTab();
	w =  Game::getInstance()->getMap()->getWidth();
	h =  Game::getInstance()->getMap()->getHeight();
	count = Object::getCount();
	while (++i < count)
	{
		x = o[i]->getNextPos().x;
		y = o[i]->getNextPos().y;
		if (x >= 0 && x < w && y >= 0 && y < h
			&& map[y][x] == M_EMPTY)
		{
			car = map[o[i]->getPos().y][o[i]->getPos().x];
			map[o[i]->getPos().y][o[i]->getPos().x] = M_EMPTY;
			map[y][x] = car;
			o[i]->setPos(x, y);
		}
	}
}

void					ObjectManager::update(void)
{
	move();
	std::cout << "ObjectManager update !" << std::endl;//_DEBUG_//
}
