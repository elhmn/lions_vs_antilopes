#include <iostream>
#include "RenderManager.class.h"
#include "Game.class.h"
#include "load_map.h"
#include "error.h"

/*
** Non member variables
*/

bool				RenderManager::_verbose = false;
RenderManager		*RenderManager::_instance = NULL;

/*
** Constructors
*/

RenderManager::RenderManager(void)
{
	if (RenderManager::_verbose)
	{
		std::cout << "RenderManager constructor called !" << std::endl;
	}
}

/*
** Destructors
*/

RenderManager::~RenderManager(void)
{
	if (RenderManager::_verbose)
	{
		std::cout << "RenderManager destructor called" << std::endl;
	}
	//destroy every data
}

/*
** Singleton getInstance
*/

RenderManager			*RenderManager::getInstance(void)
{
	if (!RenderManager::_instance)
	{
		if (!(RenderManager::_instance = new RenderManager()))
			ERROR("BAD ALLOC");
	}
	return (RenderManager::_instance);
}

/*
** Actions
*/

void					RenderManager::render(void)
{
	int		i;
	int		j;
	int		w;
	int		h;
	int		ret;
	char	**map;

	CLEAR();
	i = -1;
	map = Game::getInstance()->getMap()->getTab();
	w = Game::getInstance()->getMap()->getWidth();
	h = Game::getInstance()->getMap()->getHeight();
	while (++i < h)
	{
		j = -1;
		while (++j < w)
		{
			ret = map[i][j];
			if (ret == M_BLOCK)
			{
				if (i == 0 || i == h - 1)
					std::cout << M_RENDER_BORD_H;
				else if (j == 0 || j == w - 1)
					std::cout << M_RENDER_BORD_V;
				else
					std::cout << M_RENDER_BLOCK;
			}
			else if (ret == M_FLAG_E1)
				std::cout << M_RENDER_FLAG_E1;
			else if (ret == M_FLAG_E2)
				std::cout << M_RENDER_FLAG_E2;
			else if (ret == M_LION)
				std::cout << M_RENDER_LION;
			else if (ret == M_ANTILOPE)
				std::cout << M_RENDER_ANTILOPE;
			else
				std::cout << M_RENDER_EMPTY;

		}
		std::cout << std::endl;
	}
}
