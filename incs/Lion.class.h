#ifndef LION_CLASS_H
# define LION_CLASS_H

# include "Object.class.h"

class	Lion : public Object
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
	Lion(void);
	Lion(const Lion &rhs);

/*
** Destructor
*/
	~Lion(void);

/*
** Operators overload
*/
	Lion &operator=(const Lion &rhs);

/*
** Member functions 
*/
	// Actions
	virtual void		update(void);
};

#endif
