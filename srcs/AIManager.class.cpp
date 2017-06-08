#include <iostream>
#include <cstdlib>
#include <time.h>
#include "AIManager.class.h"
#include "Game.class.h"
#include "Map.class.h"
#include "Object.class.h"
#include "error.h"

/*
** Non member variables
*/

bool				AIManager::_verbose = false;
AIManager			*AIManager::_instance = NULL;

/*
** Constructors
*/

AIManager::AIManager(void)
{
	if (AIManager::_verbose)
	{
		std::cout << "AIManager constructor called !" << std::endl;
	}
}

/*
** Destructors
*/

AIManager::~AIManager(void)
{
	if (AIManager::_verbose)
	{
		std::cout << "AIManager destructor called" << std::endl;
	}
	//destroy every data
}

/*
** Singleton getInstance
*/

AIManager			*AIManager::getInstance(void)
{
	if (!AIManager::_instance)
	{
		if (!(AIManager::_instance = new AIManager()))
			ERROR("BAD ALLOC");
	}
	return (AIManager::_instance);
}

/*
** Actions
*/

void					AIManager::simulate(void)
{
	int				i;
	int				sign_y;
	int				sign_x;
	int				count;
	Object			**o;
	char			**map;
	int				x;
	int				y;
	int				w;
	int				h;
	int				tries;

	i = -1;
	o = Game::getInstance()->getObjects();
	count = Object::getCount();
	map = Game::getInstance()->getMap()->getTab();
	w =  Game::getInstance()->getMap()->getWidth();
	h =  Game::getInstance()->getMap()->getHeight();
	std::cout << "c = " << count << std::endl;//_DEBUG_//
	while (++i < count)
	{
		tries = 0;
		std::cout << "i = " << i << std::endl;
		do
		{
			sign_x = (rand() % 100 > 80) ? -1 : 1;
			sign_y = (rand() % 100 > 80) ? -1 : 1;
			if (tries == 20)
			{
				x = o[i]->nextPos.x = o[i]->getPos().x + sign_x * FPS / SECOND;
				y = o[i]->nextPos.y = o[i]->getPos().y + sign_y * FPS / SECOND;
				break ;
			}
			x = o[i]->nextPos.x = o[i]->getPos().x + sign_x * FPS / SECOND;
			y = o[i]->nextPos.y = o[i]->getPos().y + sign_y * FPS / SECOND;
			tries++;
		}
		while (!(x >= 0 && x < w && y >= 0 && y < h
			&& map[y][x] == M_EMPTY));
	}
	std::cout << "AIManager simulate !" << std::endl;//_DEBUG_//
}
