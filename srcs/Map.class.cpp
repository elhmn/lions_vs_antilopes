#include "Map.class.h"
#include <iostream>

/*
** Non member variables
*/

bool		Map::_verbose = false;

/*
** Constructors
*/

Map::Map(void)
{
	if (Map::_verbose)
	{
		std::cout << "Map constructor called !" << std::endl;
	}
}

/*
** Destructors
*/

Map::~Map(void)
{
	if (Map::_verbose)
	{
		std::cout << "Map destructor called !" << std::endl;
	}
}

/*
** Setters
*/

/*
** Getters
*/

char				**Map::getTab(void) const
{
	return (this->_tab);
}

int					Map::getWidth(void) const
{
	return (this->_width);
}

int					Map::getHeight(void) const
{
	return (this->_height);
}
