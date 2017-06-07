#include "Flag.class.h"
#include <iostream>

bool		Flag::_verbose = false;

/*
** Constructors
*/

Flag::Flag(void)
{
	if (Flag::_verbose)
	{
		std::cout << "Flag constructor called" << std::endl;
	}
	//set the variables
}

/*
** Destructor
*/

Flag::~Flag(void)
{
	if (Flag::_verbose)
	{
		std::cout << "Flag destructor called" << std::endl;
	}
	//clean variables
}

void		Flag::update(void)
{
	std::cout << "Flag update !" << std::endl;//_DEBUG_//
}
