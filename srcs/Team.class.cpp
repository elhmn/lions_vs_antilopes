#include "Team.class.h"
#include <iostream>
#include "Factory.class.h"
#include "error.h"

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
	return (this->_points);
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
