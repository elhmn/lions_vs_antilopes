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
	const char			*_name;
	e_objType			_type;
	int					_points;
	int					_memberCount;
	Object				*_flag;// still don't know how to handle that
	Object				**_members;

	public :
/*
** Constructors
*/
	Team(void);
	Team(const char *name, e_objType type, int memberCount);
	Team(const Team &rhs);

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
	int					getMemberCount(void) const;
	const char			*getName(void) const;
	Object				*getFlag(void) const;
	Object				*getMember(int i) const;
	Object				**getMembers(void) const;

/*
** Actions
*/
	void				place(void) const;

};

#endif
