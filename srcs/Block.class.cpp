#include "Block.class.h"
#include <iostream>

bool		Block::_verbose = false;

/*
** Constructors
*/

Block::Block(void)
{
	if (Block::_verbose)
	{
		std::cout << "Block constructor called" << std::endl;
	}
	//set the variables
}

/*
** Destructor
*/

Block::~Block(void)
{
	if (Block::_verbose)
	{
		std::cout << "Block destructor called" << std::endl;
	}
	//clean variables
}
