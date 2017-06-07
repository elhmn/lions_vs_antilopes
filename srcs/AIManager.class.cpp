#include <iostream>
#include "AIManager.class.h"
#include "error.h"

/*
** Non member variables
*/

bool				AIManager::_verbose = false;
AIManager		*AIManager::_instance = NULL;

/*
** Constructors
*/

AIManager::AIManager(void)
{
	if (AIManager::_verbose)
	{
		std::cout << "AIManager constructor called !" << std::endl;
	}
}

/*
** Destructors
*/

AIManager::~AIManager(void)
{
	if (AIManager::_verbose)
	{
		std::cout << "AIManager destructor called" << std::endl;
	}
	//destroy every data
}

/*
** Singleton getInstance
*/

AIManager			*AIManager::getInstance(void)
{
	if (!AIManager::_instance)
	{
		if (!(AIManager::_instance = new AIManager()))
			ERROR("BAD ALLOC");
	}
	return (AIManager::_instance);
}

/*
** Actions
*/

void					AIManager::simulate(void)
{
	std::cout << "AIManager simulate !" << std::endl;//_DEBUG_//
}
