#include "Lion.class.h"
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

void		Lion::update(void)
{
	std::cout << "Lion update !" << std::endl;//_DEBUG_//
}
