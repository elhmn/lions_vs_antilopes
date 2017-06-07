#ifndef FLAG_CLASS_H
# define FLAG_CLASS_H

# include "Object.class.h"

class	Flag : public Object
{
	private :
/*
** Non Member variables
*/
	static bool			_verbose;

	public :
/*
** Constructors
*/
	Flag(void);
	Flag(const Flag &rhs);

/*
** Destructor
*/
	~Flag(void);

/*
** Operators overload
*/
	Flag &operator=(const Flag &rhs);

/*
** Member functions 
*/
	// Actions
	virtual void		update(void);
};

#endif
