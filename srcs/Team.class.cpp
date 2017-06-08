#include "Team.class.h"
#include "Factory.class.h"
#include "Game.class.h"
#include "Antilope.class.h"
#include "Map.class.h"
#include "error.h"
#include <iostream>
#include <cstdlib>
#include <time.h>

/*
** Non member variables
*/

bool		Team::_verbose = false;

/*
** Constructors
*/

Team::Team(void)
{
	if (Team::_verbose)
	{
		std::cout << "Team constructor called !" << std::endl;
	}
}

Team::Team(const char *name, e_objType type, int memberCount) : _name(name), _type(type), _memberCount(memberCount)
{
	int		i;

	i = -1;
	if (Team::_verbose)
	{
		std::cout << "Team constructor called !" << std::endl;
	}
	this->_points = 0;
	if (!(this->_members = (Object**)malloc(sizeof(Object*) * this->_memberCount)))
		ERROR("BAD ALLOC");
	while (++i < this->_memberCount)
		if (!(this->_members[i] = Factory::getInstance()->create(type)))
			ERROR("BAD ALLOC");
}

/*
** Destructors
*/

Team::~Team(void)
{
	if (Team::_verbose)
	{
		std::cout << "Team destructor called !" << std::endl;
	}
}

/*
** Setters
*/

/*
** Getters
*/
int				Team::getPoints(void) const
{
	return (this->_points);
}

int				Team::getMemberCount(void) const
{
	return(this->_memberCount);
}

const char		*Team::getName(void) const
{
	return (this->_name);
}

const t_pos		&Team::getFlag(void) const
{
	return (this->_flag);
}

Object			*Team::getMember(int i) const
{
	if (i >= this->_memberCount)
		return (NULL);
	return (this->_members[i]);
}

Object			**Team::getMembers(void) const
{
	return (this->_members);
}

void			Team::getFlagLocation(void)
{
	int			i;
	int			j;
	int			w;
	int			h;
	bool		found;
	char		**map;

	i = -1;
	found = false;
	map = Game::getInstance()->getMap()->getTab();
	w =  Game::getInstance()->getMap()->getWidth();
	h =  Game::getInstance()->getMap()->getHeight();
	while (++i < h)
	{
		j = -1;
		while (++j < w)
		{
			if (this->_type == LION)
			{
				if (map[i][j] == M_FLAG_L)
				{
					std::cout << "LION" << std::endl;
					this->_flag.x = j;
					this->_flag.y = i;
					found = true;
					break ;
				}
			}
			if (this->_type == ANTILOPE)
			{
				if (map[i][j] == M_FLAG_A)
				{
					std::cout << "ANTILOPE" << std::endl;
					this->_flag.x = j;
					this->_flag.y = i;
					found = true;
					break ;
				}
			}
		}
	}
	if (!found)
		ERROR("MAP FLAG WRONG FORMAT");
}

/*
** Actions
*/
void			Team::place(void)
{
	Antilope	*a;
	t_pos		pos;
	int			radTries;
	int			sign;
	char		**map;
	char		car;
	int			w;
	int			h;
	int			count;
	int			i;
	int			r_x;
	int			r_y;
	int			tmp;
	
	i = -1;
	count = this->getMemberCount();
	map = Game::getInstance()->getMap()->getTab();
	w =  Game::getInstance()->getMap()->getWidth();
	h =  Game::getInstance()->getMap()->getHeight();
	srand(time(NULL));
	radTries = 0;
	while (++i < this->getMemberCount())
	{
		if (this->_type == LION)
			car = M_LION;
		else if (this->_type == ANTILOPE)
			car = M_ANTILOPE;
		else
			ERROR("Object type unknown");
		do
		{
			r_x = rand() % w;
			if (car == M_ANTILOPE || car == M_LEAD)
			{
				if (i < Antilope::getLeaderCount())
				{
					car = M_LEAD;
					r_y = (rand() % h / 2) + h / 2;
				}
				else
				{
					if (radTries >= 100)
					{
						r_y = (rand() % h / 2) + h / 2;
						radTries = 0;
					}
					else
					{
						//choose a leader
						pos = this->_members[(tmp = rand() % Antilope::getLeaderCount())]->getPos();
						a = dynamic_cast<Antilope*>(this->_members[i]);
						a->setLeaderID(tmp);
						sign = (rand() % 2) ? -1 : 1;
						r_x = pos.x + (rand() % LEADER_RADIUS) * sign;
						r_y = pos.y + (rand() % LEADER_RADIUS) * sign;
						radTries++;
					}
				}
			}
			else
				r_y = rand() % h / 2;
		}
		while (r_x >= w || r_x < 0 || r_y >= h || r_y < 0 || map[r_y][r_x] != M_EMPTY);
		this->getMember(i)->setPos(r_x, r_y);
		map[r_y][r_x] = car; 
	}
}
