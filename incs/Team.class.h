#ifndef TEAM_CLASS_H
# define TEAM_CLASS_H

# include "Object.class.h"

class	Team
{
	private :

/*
**	Non member variables
*/	
	static bool			_verbose;

/*
** Member variables
*/
	int					_points;
	int					_alifeCount;
	int					_memberCount;
	char				*_name;
	Object				*_flag;
	Object				*_members;

	public :
/*
** Constructors
*/
	Team(void);
	Team(const Object &rhs);

/*
** Destructor
*/
	~Team(void);

/*
** Operators overload
*/
	Team &operator=(const Team &rhs);

/*
** Member functions
*/
	//Getters
	int					getPoints(void) const;
	int					getAlifeCount(void) const;
	int					getMemberCount(void) const;
	char				getName(void) const;
	Object				*getFlag(void) const;
	Object				*getMember(int i) const;
	Object				**getMembers(void) const;
};

#endif
