#include <iostream>
#include "ObjectManager.class.h"
#include "Map.class.h"
#include "Object.class.h"
#include "Game.class.h"
#include "Team.class.h"
#include "Antilope.class.h"
#include <cstdlib>
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
		//dummy speed handler
		if (o[i]->speedCount < SECOND)
			o[i]->speedCount += (float)o[i]->getSpeed() / (float)FPS;
		o[i]->speedCount = 0;
		x = o[i]->getNextPos().x;
		y = o[i]->getNextPos().y;
		if (o[i]->hasFlag)
		{
			if (o[i]->getType() == ANTILOPE)
			{
				Game::getInstance()->getLions()->setFlag(o[i]->getPos());
			}
			if (o[i]->getType() == LION)
			{
				Game::getInstance()->getAntilopes()->setFlag(o[i]->getPos());
			}
		}
		if (x >= 0 && x < w && y >= 0 && y < h
			&& (map[y][x] == M_EMPTY
			|| map[y][x] == M_FLAG_L
			|| map[y][x] == M_FLAG_A))
		{
			if (map[y][x] == M_FLAG_L)
			{
				if (o[i]->getType() == ANTILOPE)
				{
					o[i]->hasFlag = true;
					o[i]->setTarget(Game::getInstance()->getAntilopes()->originFlag);
					Game::getInstance()->getAntilopes()->hasFlag = true;
					Game::getInstance()->getLions()->ownFlag = false;
				}
				if (o[i]->getType() == LION)
				{
					if (o[i]->hasFlag)
					{
						Game::getInstance()->getLions()->points++;
						Game::getInstance()->reset = true;
					}
					else
						continue ;
				}
			}
			if (map[y][x] == M_FLAG_A)
			{
				if (o[i]->getType() == LION)
				{
					o[i]->hasFlag = true;
					o[i]->setTarget(Game::getInstance()->getLions()->originFlag);
					Game::getInstance()->getLions()->hasFlag = true;
					Game::getInstance()->getAntilopes()->ownFlag = false;
				}
				if (o[i]->getType() == ANTILOPE)
				{
					if (o[i]->hasFlag)
					{
						Game::getInstance()->getAntilopes()->points++;
						Game::getInstance()->reset = true;
					}
					else
						continue ;
				}
			}
			car = map[o[i]->getPos().y][o[i]->getPos().x];
			if (o[i]->getType() == LION && o[i]->hasFlag)
				car = M_L_GETFLAG;
			else if (o[i]->getType() == ANTILOPE && o[i]->hasFlag)
				car = M_A_GETFLAG;
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
		if (!a->getIsLeader() && a->getLeaderID() != -1)
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

	if (1000.0 * (std::clock()
		- Game::getInstance()->getObjectManager()->c_start) / CLOCKS_PER_SEC < WAIT_CLOCK)
		return ;
	Game::getInstance()->getObjectManager()->c_start = std::clock();
	i = -1;
	o = Game::getInstance()->getObjects();
	count = Object::getCount();
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
					o[i]->setPos(o[i]->origin.x, o[i]->origin.y);

			}
			if (o[i]->getType() == LION)
			{
				map[o[i]->origin.y][o[i]->origin.x] = M_LION;
				o[i]->setPos(o[i]->origin.x, o[i]->origin.y);
			}
		}
	}
}

void					updateObjectTarget(void)
{
	int				i;
	int				count;
	int				ret;
	Object			**o;

	i = -1;
	o = Game::getInstance()->getObjects();
	count = Object::getCount();
	while (++i < count)
	{
		if (!o[i]->isAlive)
			continue ;
		if (o[i]->getType() == ANTILOPE)
		{

			if (!Game::getInstance()->getAntilopes()->ownFlag)
			{
				o[i]->setTarget(Game::getInstance()->getAntilopes()->getFlag());
			}
			else
			{
				if (Game::getInstance()->getAntilopes()->hasFlag)
				{
					if (o[i]->hasFlag)
						o[i]->setTarget(Game::getInstance()->getAntilopes()->originFlag);
					else
					{
						ret = rand() % Game::getInstance()->getLions()->getMemberCount();
						if (Game::getInstance()->getLions()->getMember(ret)->isAlive)
							o[i]->setTarget(Game::getInstance()->getLions()->getMember(ret)->getPos());
					}
				}
				else
				{
					o[i]->setTarget(Game::getInstance()->getLions()->originFlag);
				}
			}
		}
		if (o[i]->getType() == LION)
		{
			if (!Game::getInstance()->getLions()->ownFlag)
			{
				o[i]->setTarget(Game::getInstance()->getLions()->getFlag());
			}
			else
			{
				if (Game::getInstance()->getLions()->hasFlag)
				{
					if (o[i]->hasFlag)
						o[i]->setTarget(Game::getInstance()->getLions()->originFlag);
					else
					{
						ret = rand() % Game::getInstance()->getAntilopes()->getMemberCount();
						if (Game::getInstance()->getAntilopes()->getMember(ret)->isAlive)
							o[i]->setTarget(Game::getInstance()->getAntilopes()->getMember(ret)->getPos());
					}
				}
				else
				{
					o[i]->setTarget(Game::getInstance()->getAntilopes()->originFlag);
				}
			}
		}
	}
}

static void				updateFlag(void)
{
	char			**map;
	int				x;
	int				y;

	map = Game::getInstance()->getMap()->getTab();
	if (Game::getInstance()->getLions()->ownFlag)
	{
		x = Game::getInstance()->getLions()->originFlag.x;
		y = Game::getInstance()->getLions()->originFlag.y;
		map[y][x] = M_FLAG_L;
		Game::getInstance()->getLions()->setFlag(
			Game::getInstance()->getLions()->originFlag);
	}
	if (Game::getInstance()->getAntilopes()->ownFlag)
	{
		x = Game::getInstance()->getAntilopes()->originFlag.x;
		y = Game::getInstance()->getAntilopes()->originFlag.y;
		map[y][x] = M_FLAG_A;
		Game::getInstance()->getAntilopes()->setFlag(
			Game::getInstance()->getAntilopes()->originFlag);
	}
}

void					ObjectManager::update(void)
{
	move();
	updateAntilopeFollowers();
	updateObjectTarget();
	updateFlag();
	respawn();
}
