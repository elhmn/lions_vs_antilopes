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
	this->_speed = 0;
	this->_sprite1 = '\0';
	this->_sprite2 = '\0';
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
	this->_sprite1 = rhs.getSprite1();
	this->_sprite2 = rhs.getSprite2();
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

/*
** Getters
*/

const t_pos		&Object::getPos(void) const
{
	return (this->_pos);
}

const e_objType	Object::getType(void) const
{
	return (this->_type);
}

const char		Object::getSprite1(void) const
{
	return (this->_sprite1);
}

const char		Object::getSprite2(void) const
{
	return (this->_sprite2);
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
