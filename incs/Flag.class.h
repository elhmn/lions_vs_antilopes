#ifndef FLAG_CLASS_H
# define FLAG_CLASS_H

# include "Object.class.h"

class	Flag : public Object
{
	public :
/*
** Constructors
*/
	Flag(void);
	Flag(const Object &rhs);

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
};

#endif
