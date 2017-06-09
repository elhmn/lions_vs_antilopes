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
	int					_memberCount;
	t_pos				_flag;
	Object				**_members;

	public :
	t_pos				originFlag;
	bool				hasFlag;
	bool				ownFlag;
	int					points;
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
	int					getMemberCount(void) const;
	const char			*getName(void) const;
	const t_pos			&getFlag(void) const;
	Object				*getMember(int i) const;
	Object				**getMembers(void) const;

	//Setters
	void				setFlag(t_pos pos);
/*
** Actions
*/
	void				getFlagLocation(void);
	void				place(void);
	void				init(void);

};

#endif
