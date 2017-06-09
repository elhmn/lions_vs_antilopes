#include <iostream>
#include <cstdlib>
#include <cstring>
#include <time.h>
#include <list>
#include <vector>
#include <cmath>
#include "AIManager.class.h"
#include "Game.class.h"
#include "Map.class.h"
#include "Object.class.h"
#include "Antilope.class.h"
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


/*
** Basic recursive Pathfinding algorithm
*/

char					**mapDup(char **map, int w, int h)
{
	char	**tmp;
	int		i;

	i = -1;
	tmp = NULL;
	if (!(tmp = (char**)malloc(sizeof(char*) * h + 1)))
		ERROR("BAD ALLOC");
	tmp[h] = NULL;
	while (++i < h)
	{
		if (!(tmp[i] = (char*)malloc(sizeof(char) * w + 1)))
			ERROR("BAD ALLOC");
 		tmp[i][w] = '\0';
		memcpy(tmp[i], map[i], w);
	}
	return (tmp);
}

void					freeMap(char ***map, int w, int h)
{
	int		i;

	i = -1;
	while (++i < h)
	{
		free(map[0][i]);
		map[0][i] = NULL;
	}
	free(map[0]);
	map[0] = NULL;
}

void					showMap(char **map, int w, int h)
{
	int		i;

	i = -1;
	while (++i < h)
		std::cout << map[i] << std::endl;
}

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

static void				printPath(std::list<t_pos> path)
{
	for (std::list<t_pos>::iterator it = path.begin(); it != path.end(); it++)
		std::cout << TAB << it->x << ", " << it->y << std::endl;
}

static void				printPaths(std::vector< std::list<t_pos> > paths)
{
	for (std::vector< std::list<t_pos> >::iterator it = paths.begin(); it != paths.end(); it++)
	{
		std::list<t_pos>	e;
		e = *it;
		std::cout << "PATH : " << std::endl;
		printPath(e);
	}
}

static void			findPath(Object *o, char **map, int w, int h, int x, int y)
{
	int					b_x;
	int					b_y;
	bool				start;
	t_pos				tab[8];
	std::vector< std::list<t_pos> >	paths;
	bool				way;

	setTab(tab, x, y);
	start = true;
	way = false;
  	while (42)
  	{
		way = false;
		if (start)
		{
			for (int i = 0; i < 8; i++)
			{
				b_x = tab[i].x;
				b_y = tab[i].y;
			 	if (!(b_x >= 0 && b_x < w && b_y >= 0 && b_y < h
			 		&& (map[b_y][b_x] == M_EMPTY
						|| map[b_y][b_x] == M_FLAG_A
						|| map[b_y][b_x] == M_FLAG_L)))
					continue ;
				if (o->getType() == ANTILOPE
					&& 	map[b_y][b_x] == M_LION)
					continue ;
				if (o->getType() == LION
					&& 	map[b_y][b_x] == M_ANTILOPE)
					continue ;
				way = true;
				std::list<t_pos>	p;
				p.push_back(tab[i]);
				paths.push_back(p);
 				map[b_y][b_x] = M_JAM;
				if (o->getTarget().x == tab[i].x && o->getTarget().y == tab[i].y)
				{
					o->setNextPos(p.begin()->x, p.begin()->y);
					return ;
				}
			}
			start = false;
		}
		else
		{
			int		size = paths.size();
			for (int i = 0; i < size; i++)
			{
				setTab(tab, paths[i].back().x, paths[i].back().y);
				for (int j = 0; j < 8; j++)
				{
					b_x = tab[j].x;
					b_y = tab[j].y;
			 		if (!(b_x >= 0 && b_x < w && b_y >= 0 && b_y < h
			 			&& (map[b_y][b_x] == M_EMPTY
							|| map[b_y][b_x] == M_FLAG_A
							|| map[b_y][b_x] == M_FLAG_L)))
					continue ;
					if (o->getType() == ANTILOPE
					&& 	map[b_y][b_x] == M_LION)
						continue ;
					if (o->getType() == LION
					&& 	map[b_y][b_x] == M_ANTILOPE)
						continue ;
					way = true;
					std::list<t_pos>	p;
					p = paths[i];
 					map[b_y][b_x] = M_JAM;
					p.push_back(tab[j]);
 					paths.push_back(p);
					if (o->getTarget().x == tab[j].x && o->getTarget().y == tab[j].y)
					{
						o->setNextPos(p.begin()->x, p.begin()->y);
						return ;
					}
				}
			}
 			paths.erase (paths.begin(), paths.begin() + size);
			if (!way)
				return ;
		}
	}
}


static float			distance(t_pos a, t_pos b)
{
	return (sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2)));
}

void					AIManager::simulate(void)
{
	int				i;
	int				count;
	Object			**o;
	char			**map;
	int				x;
	int				y;
	int				w;
	int				h;

	i = -1;
	o = Game::getInstance()->getObjects();
	count = Object::getCount();
	map = Game::getInstance()->getMap()->getTab();
	w =  Game::getInstance()->getMap()->getWidth();
	h =  Game::getInstance()->getMap()->getHeight();
	while (++i < count)
	{
		if (!o[i]->isAlive)
			continue ;
		x = o[i]->getPos().x;
		y = o[i]->getPos().y;
 		char	**mapTmp = mapDup(map, w, h);
		if (o[i]->getType() == LION)
		{
			o[i]->setTarget(Game::getInstance()->getAntilopes()->getFlag());
		}
		else if (o[i]->getType() == ANTILOPE)
		{
			
			o[i]->setTarget(Game::getInstance()->getLions()->getFlag());
		}
		if (o[i]->getTarget().x != -1
				&& o[i]->getTarget().y != -1)
				findPath(o[i], mapTmp, w, h, x, y);
 		freeMap(&mapTmp, w, h);
	}
}
