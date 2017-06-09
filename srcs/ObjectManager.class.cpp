#include <iostream>
#include "ObjectManager.class.h"
#include "Map.class.h"
#include "Object.class.h"
#include "Game.class.h"
#include "Team.class.h"
#include "Antilope.class.h"
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
	c_start = std::clock();
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
		if (!o[i]->isAlive)
			continue ;
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

static void				updateAntilopeFollowers()
{
	Object				**l;
	int					count;

	count = Game::getInstance()->getAntilopes()->getMemberCount();
	l = Game::getInstance()->getAntilopes()->getMembers();
	for (int i = 0; i < count; i++)
	{
		Antilope	*a;
		a = dynamic_cast<Antilope*>(l[i]);
		if (!a->getIsLeader())
		{
			a->setTarget(l[a->getLeaderID()]->getTarget());
		}
	}
}

static void				respawn(void)
{
	Object			**o;
	char			**map;
	int				count;
	int				i;

	if (1000.0 * (std::clock() - Game::getInstance()->getObjectManager()->c_start) / CLOCKS_PER_SEC < WAIT_CLOCK)
		return ;
	Game::getInstance()->getObjectManager()->c_start = std::clock();
	i = -1;
	o = Game::getInstance()->getObjects();
	count = Game::getInstance()->getAntilopes()->getMemberCount();
	map = Game::getInstance()->getMap()->getTab();
	while (++i < count)
	{
		if (!o[i]->isAlive
			&& map[o[i]->origin.y][o[i]->origin.x] == M_EMPTY)
		{
			o[i]->isAlive = true;
			if (o[i]->getType() == ANTILOPE)
			{
				if (dynamic_cast<Antilope*>(o[i])->getIsLeader())
					map[o[i]->origin.y][o[i]->origin.x] = M_LEAD;
				else
					map[o[i]->origin.y][o[i]->origin.x] = M_ANTILOPE;

			}
			if (o[i]->getType() == LION)
				map[o[i]->origin.y][o[i]->origin.x] = M_LION;
		}
	}
}

void					ObjectManager::update(void)
{
	move();
	updateAntilopeFollowers();
	respawn();
}
