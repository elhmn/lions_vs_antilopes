#ifndef ANTILOPE_CLASS_H
# define ANTILOPE_CLASS_H

# include "Object.class.h"

# define ANTILOPES_MAX_LEADER	10
# define LEADER_RADIUS			2	

class	Antilope : public Object
{

	private :
/*
** Non Member variables
*/
	static bool			_verbose;
	static int			_leaderCount;
	static int			_nLeader;
	int					_leaderID;

	public :
/*
** Member variables
*/

	bool				_isLeader;

/*
** Constructors
*/
	Antilope(void);
	Antilope(const Antilope &rhs);

/*
** Destructor
*/
	~Antilope(void);

/*
** Operators overload
*/
	Antilope &operator=(const Antilope &rhs);

/*
** Getters
*/
	bool						getIsLeader(void) const;
	int							getLeaderID(void) const;
	static int					getLeaderCount(void);

/*
** Setters
*/
	void						setLeaderID(int id);
	
/*
** Member functions 
*/
	// Actions
	virtual void				update(void);
};

#endif
