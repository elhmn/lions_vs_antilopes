#ifndef ANTILOPE_CLASS_H
# define ANTILOPE_CLASS_H

# include "Object.class.h"

class	Antilope : public Object
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
** Member functions 
*/
	// Actions
	virtual void		update(void);
};

#endif
