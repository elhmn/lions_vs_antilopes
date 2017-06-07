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
	this->setPos(x, y);
}
