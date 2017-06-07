#include "Factory.class.h"
#include "error.h"
#include <iostream>


/*
** Non member variables
*/

bool			Factory::_verbose = false;
Factory			*Factory::_instance = NULL;

/*
** Constructors
*/

Factory::Factory(void)
{
	if (Factory::_verbose)
	{
		std::cout << "Factory constructor called !" << std::endl;
	}
}

/*
** Destructors
*/

Factory::~Factory(void)
{
	if (Factory::_verbose)
	{
		std::cout << "Factory destructor called" << std::endl;
	}
	//destroy every data
}

/*
** Singleton getInstance
*/
Factory			*Factory::getInstance(void)
{
	if (!Factory::_instance)
	{
		if (!(Factory::_instance = new Factory()))
			ERROR("BAD ALLOC");
	}
	return (Factory::_instance);
}

/*
** Actions
*/

Object			*Factory::create(e_objType type)
{
	Object		*o;

	o = NULL;
	if (type == LION)
	{
		if (!(o = new Lion()))
			ERROR("BAD ALLOC");
	}
	else if (type == ANTILOPE)
	{
		if (!(o = new Antilope()))
			ERROR("BAD ALLOC");
	}
	//if i use finally use Flag
	else if (type == FLAG)
	{
		if (!(o = new Flag()))
			ERROR("BAD ALLOC");
	}
	return (o);
}
