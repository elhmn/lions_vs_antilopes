#include "Map.class.h"
#include "load_map.h"
#include "types.h"

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

Map::Map(const char *filePath)
{
	if (Map::_verbose)
	{
		std::cout << "Map constructor called !" << std::endl;
	}
	load_map(filePath, &this->_tab, &this->_width, &this->_height);
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

/*
** Operator overload
*/

std::ostream& operator<<(std::ostream& os, const Map& rhs)
{
	int		i;
	int		h;

	i = -1;
	h = rhs.getHeight();
	os << "Map : " << std::endl;
	os << TAB << "width : " << rhs.getWidth() << std::endl;
	os << TAB << "heigth : " << rhs.getHeight() << std::endl;
	while (++i < h)
		os << TAB << rhs.getTab()[i] << std::endl;
	os << "END" << std::endl;
    return os;
}
