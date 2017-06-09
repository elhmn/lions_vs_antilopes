#include <iostream>
#include "GameManager.class.h"
#include "error.h"

/*
** Non member variables
*/

bool				GameManager::_verbose = false;
GameManager		*GameManager::_instance = NULL;

/*
** Constructors
*/

GameManager::GameManager(void)
{
	if (GameManager::_verbose)
	{
		std::cout << "GameManager constructor called !" << std::endl;
	}
}

/*
** Destructors
*/

GameManager::~GameManager(void)
{
	if (GameManager::_verbose)
	{
		std::cout << "GameManager destructor called" << std::endl;
	}
	//destroy every data
}

/*
** Singleton getInstance
*/

GameManager			*GameManager::getInstance(void)
{
	if (!GameManager::_instance)
	{
		if (!(GameManager::_instance = new GameManager()))
			ERROR("BAD ALLOC");
	}
	return (GameManager::_instance);
}

/*
** Actions
*/

void					GameManager::update(void)
{

	std::cout << "GameManager update !" << std::endl;//_DEBUG_//
}
