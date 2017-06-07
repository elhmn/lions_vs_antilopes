#ifndef BLOCK_CLASS_H
# define BLOCK_CLASS_H

# include "Object.class.h"

class	Block : public Object
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
	Block(void);
	Block(const Block &rhs);

/*
** Destructor
*/
	~Block(void);

/*
** Operators overload
*/
	Block &operator=(const Block &rhs);
};

#endif
