#include "Team.class.h"
#include "Factory.class.h"
#include "Game.class.h"
#include "Map.class.h"
#include "error.h"
#include <iostream>
#include <cstdlib>
#include <time.h>

/*
** Non member variables
*/

bool		Team::_verbose = false;

/*
** Constructors
*/

Team::Team(void)
{
	if (Team::_verbose)
	{
		std::cout << "Team constructor called !" << std::endl;
	}
}

Team::Team(const char *name, e_objType type, int memberCount) : _name(name), _type(type), _memberCount(memberCount)
{
	int		i;

	i = -1;
	if (Team::_verbose)
	{
		std::cout << "Team constructor called !" << std::endl;
	}
	this->_points = 0;
	if (!(this->_members = (Object**)malloc(sizeof(Object*) * this->_memberCount)))
		ERROR("BAD ALLOC");
	while (++i < this->_memberCount)
		if (!(this->_members[i] = Factory::getInstance()->create(type)))
			ERROR("BAD ALLOC");
}

/*
** Destructors
*/

Team::~Team(void)
{
	if (Team::_verbose)
	{
		std::cout << "Team destructor called !" << std::endl;
	}
}

/*
** Setters
*/

/*
** Getters
*/
int				Team::getPoints(void) const
{
	return (this->_points);
}

int				Team::getMemberCount(void) const
{
	return(this->_memberCount);
}

const char		*Team::getName(void) const
{
	return (this->_name);
}

Object			*Team::getFlag(void) const
{
	return (this->_flag);
}

Object			*Team::getMember(int i) const
{
	if (i >= this->_memberCount)
		return (NULL);
	return (this->_members[i]);
}

Object			**Team::getMembers(void) const
{
	return (this->_members);
}

/*
** Actions
*/
void			Team::place(void)
{
	char	**map;
	char	car;
	int		w;
	int		h;
	int		count;
	int		i;
	int		r_x;
	int		r_y;
	
	i = -1;
	count = this->getMemberCount();
	map = Game::getInstance()->getMap()->getTab();
	w =  Game::getInstance()->getMap()->getWidth();
	h =  Game::getInstance()->getMap()->getHeight();
	srand(time(NULL));
	while (++i < this->getMemberCount())
	{
		do
		{
			r_x = rand() % w;
			r_y = rand() % h;
		}
		while (map[r_y][r_x] != M_EMPTY);
		this->getMember(i)->setPos(r_x, r_y);
		if (this->_type == LION)
			car = M_LION;
		else if (this->_type == ANTILOPE)
			car = M_ANTILOPE;
		else
			ERROR("Object type unknown");
		map[r_y][r_x] = car; 
	}
}
