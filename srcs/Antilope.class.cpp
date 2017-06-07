#include "Antilope.class.h"
#include <iostream>

bool		Antilope::_verbose = false;

/*
** Constructors
*/

Antilope::Antilope(void)
{
	if (Antilope::_verbose)
	{
		std::cout << "Antilope constructor called" << std::endl;
	}
	//set the variables
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

void		Antilope::update(void)
{
	std::cout << "Antilope update !" << std::endl;//_DEBUG_//
}
