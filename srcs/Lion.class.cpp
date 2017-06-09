#include "Lion.class.h"
#include "types.h"
#include <iostream>

bool		Lion::_verbose = false;

/*
** Constructors
*/

Lion::Lion(void)
{
	if (Lion::_verbose)
	{
		std::cout << "Lion constructor called" << std::endl;
	}
	this->init();
	//set the variables
}

/*
** Destructor
*/

Lion::~Lion(void)
{
	if (Lion::_verbose)
	{
		std::cout << "Lion destructor called" << std::endl;
	}
	//clean variables
}

void		Lion::init(void)
{
	Object::init();
	this->_speed = 1;
	this->_type = LION;
}
