#include "Antilope.class.h"
#include <cstdlib>
#include <time.h>
#include <iostream>

bool		Antilope::_verbose = false;
int			Antilope::_leaderCount = 0;
int			Antilope::_nLeader = 0;

/*
** Constructors
*/

Antilope::Antilope(void)
{

	if (Antilope::_verbose)
	{
		std::cout << "Antilope constructor called" << std::endl;
	}
	this->init();
}

/*
** Destructor
*/

Antilope::~Antilope(void)
{
	if (Antilope::_verbose)
	{
		std::cout << "Antilope destructor called" << std::endl;
	}
	//clean variables
}

/*
** Getters
*/
bool					Antilope::getIsLeader(void) const
{
	return (this->_isLeader);
}

int						Antilope::getLeaderID(void) const
{
	return (this->_leaderID);
}

int						Antilope::getLeaderCount(void)
{
	return (Antilope::_leaderCount);
}

/*
** Setters
*/
void					Antilope::setLeaderID(int id)
{
	this->_leaderID = id;
}

/*
** Actions
*/
void					Antilope::init(void)
{
	srand(time(NULL));
	if (!Antilope::_nLeader)
		Antilope::_nLeader = (rand() % ANTILOPES_MAX_LEADER + 1) + 1;
	Object::init();
	this->_leaderID = -1;
	this->_isLeader = false;
	this->_speed = 1000;
	this->setTarget(-1, -1);
	this->_type = ANTILOPE;
	if (Antilope::_leaderCount < _nLeader)
	{
		this->_isLeader = true;
		++Antilope::_leaderCount;
	}
}

void					Antilope::resetLeaderCount(void)
{
	Antilope::_leaderCount = 0;
}
