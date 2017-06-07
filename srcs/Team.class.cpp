#include "Team.class.h"
#include <iostream>

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

int				Team::getAlifeCount(void) const
{
	return (this->_alifeCount);
}

int				Team::getMemberCount(void) const
{
	return (this->_points);
}

char			*Team::getName(void) const
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
