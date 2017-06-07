#include <iostream>
#include "Game.class.h"
#include "error.h"
#include <unistd.h>
#include <time.h>

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

static void		setObjectList(Object ***objects)
{
	int			i;
	int			j;
	int			count;

	if (!objects)
		ERROR("objects set to null");
	i = -1;
	j = -1;
	count = Object::getCount();
	while (++i < count
			|| i < Game::getInstance()->getLions()->getMemberCount())
		objects[0][i] = Game::getInstance()->getLions()->getMember(++j);
	j = -1;
	i--;
	while (++i < count
			|| i < Game::getInstance()->getAntilopes()->getMemberCount())
		objects[0][i] = Game::getInstance()->getAntilopes()->getMember(++j);
}

void			Game::init(const char *levelPath)
{
	if (!(this->_map = new Map(levelPath)))
		ERROR("BAD ALLOC");
	if (!(this->_lions = new Team("lions", LION, 5)))
		ERROR("BAD ALLOC");
	if (!(this->_antilopes = new Team("antilope", ANTILOPE, 20)))
		ERROR("BAD ALLOC");
 	if (!(this->_objects
			= (Object**)malloc(sizeof(Object*) * Object::getCount())))
 		ERROR("BAD ALLOC");
	setObjectList(&this->_objects);
	this->_renderManager = RenderManager::getInstance();
	this->_aiManager = AIManager::getInstance();
	this->_gameManager = GameManager::getInstance();
	this->_objectManager = ObjectManager::getInstance();
}

void			Game::run(void)
{
	while (42)
	{
		this->_aiManager->simulate();
		this->_objectManager->update();
		this->_gameManager->update();
		this->_renderManager->render();
		//very basic FPS handler it could've been better
		usleep(SECOND / FPS);
	}
}

void			Game::clean(void)
{
	std::cout << "I clean !" << std::endl;//_DEBUG_//
}
