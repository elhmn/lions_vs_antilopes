#include <iostream>
#include "Game.class.h"
#include "error.h"

/*
** Non member variables
*/

bool			Game::_verbose = false;
Game			*Game::_instance = NULL;

/*
** Constructors
*/

Game::Game(void)
{
	if (Game::_verbose)
	{
		std::cout << "Game constructor called !" << std::endl;
	}
	this->_lions = NULL;
	this->_antilopes = NULL;
	this->_map = NULL;
	this->_objects = NULL;
	this->_aiManager = NULL;
	this->_renderManager = NULL;
	this->_gameManager = NULL;
	this->_objectManager = NULL;
}

/*
** Destructors
*/

Game::~Game(void)
{
	if (Game::_verbose)
	{
		std::cout << "Game destructor called" << std::endl;
	}
	//destroy every data
}

/*
** Singleton getInstance
*/

Game			*Game::getInstance(void)
{
	if (!Game::_instance)
	{
		if (!(Game::_instance = new Game()))
			ERROR("BAD ALLOC");
	}
	return (Game::_instance);
}

/*
** Getters
*/
Team			*Game::getLions(void) const
{
	return (this->_lions);
}

Team			*Game::getAntilopes(void) const
{
	return (this->_antilopes);
}

Map				*Game::getMap(void) const
{
	return (this->_map);
}

Object			**Game::getObjects(void) const
{
	return (this->_objects);
}

AIManager		*Game::getAIManager(void) const
{
	return (this->_aiManager);
}

RenderManager	*Game::getRenderManager(void) const
{
	return (this->_renderManager);
}

GameManager		*Game::getGameManager(void) const
{
	return (this->_gameManager);
}

ObjectManager	*Game::getObjectManager(void) const
{
	return (this->_objectManager);
}

/*
** Actions
*/

void			Game::init(void)
{
	std::cout << "I init !" << std::endl;//_DEBUG_//
}

void			Game::run(void)
{
	std::cout << "I run !" << std::endl;//_DEBUG_//
}

void			Game::clean(void)
{
	std::cout << "I clean !" << std::endl;//_DEBUG_//
}
