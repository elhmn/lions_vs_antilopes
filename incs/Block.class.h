#ifndef BLOCK_CLASS_H
# define BLOCK_CLASS_H

# include "Object.class.h"

class	Block : public Object
{
	public :
/*
** Constructors
*/
	Block(void);
	Block(const Object &rhs);

/*
** Destructor
*/
	~Block(void);

/*
** Operators overload
*/
	Block &operator=(const Block &rhs);

/*
** Member functions 
*/
};

#endif
