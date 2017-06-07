#include <iostream>
#include "ObjectManager.class.h"
#include "error.h"

/*
** Non member variables
*/

bool				ObjectManager::_verbose = false;
ObjectManager		*ObjectManager::_instance = NULL;

/*
** Constructors
*/

ObjectManager::ObjectManager(void)
{
	if (ObjectManager::_verbose)
	{
		std::cout << "ObjectManager constructor called !" << std::endl;
	}
}

/*
** Destructors
*/

ObjectManager::~ObjectManager(void)
{
	if (ObjectManager::_verbose)
	{
		std::cout << "ObjectManager destructor called" << std::endl;
	}
	//destroy every data
}

/*
** Singleton getInstance
*/

ObjectManager			*ObjectManager::getInstance(void)
{
	if (!ObjectManager::_instance)
	{
		if (!(ObjectManager::_instance = new ObjectManager()))
			ERROR("BAD ALLOC");
	}
	return (ObjectManager::_instance);
}

/*
** Actions
*/

void					ObjectManager::destroy(void)
{
	std::cout << "ObjectManager destroy !" << std::endl;//_DEBUG_//
}

void					ObjectManager::spawn(void)
{
	std::cout << "ObjectManager spwan !" << std::endl;//_DEBUG_//
}

void					ObjectManager::update(void)
{
	std::cout << "ObjectManager update !" << std::endl;//_DEBUG_//
}
