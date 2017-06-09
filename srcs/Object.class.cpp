#include <iostream>
#include "Object.class.h"

/*
** Non member variables
*/

int			Object::_count = 0;
bool		Object::_verbose = false;

/*
** Constructors
*/

Object::Object(void)
{
	if (Object::_verbose)
	{
		std::cout << "Object constructor called !" << std::endl;
	}
	this->_type = NONE;
	//begin : send this section to the children
	this->setPos(0, 0);
	this->setTarget(-1, -1);
	this->_speed = 0;
	this->isHunting = false;
	//end
	Object::_count++;
}

Object::Object(const Object &rhs)
{
	if (Object::_verbose)
	{
		std::cout << "Object constructor called !" << std::endl;
	}
	this->_type = NONE;
	this->setPos(rhs.getPos().x, rhs.getPos().y);
	this->_speed = rhs.getSpeed();
}

/*
** Destructors
*/

Object::~Object(void)
{
	if (Object::_verbose)
	{
		std::cout << "Object destructor called !" << std::endl;
	}
	Object::_count--;
}

/*
** Setters
*/

void			Object::setPos(const int x, const int y)
{
	this->_pos.x = x;
	this->_pos.y = y;
}

void			Object::setTarget(const int x, const int y)
{
	this->_target.x = x;
	this->_target.y = y;
}

void			Object::setTarget(const t_pos target)
{
	this->_target.x = target.x;
	this->_target.y = target.y;
}

void			Object::setNextPos(const int x, const int y)
{
	this->_nextPos.x = x;
	this->_nextPos.y = y;
}

/*
** Getters
*/
const t_pos		&Object::getTarget(void) const
{
	return (this->_target);
}

const t_pos		&Object::getPos(void) const
{
	return (this->_pos);
}

const t_pos		&Object::getNextPos(void) const
{
	return (this->_nextPos);
}

const e_objType	Object::getType(void) const
{
	return (this->_type);
}

const float		Object::getSpeed(void) const
{
	return (this->_speed);
}

const int		Object::getCount(void)
{
	return (Object::_count);
}

/*
** Actions
*/

void			Object::update(void)
{
	std::cout << "Object update !" << std::endl;//_DEBUG_//
}
