#ifndef BLOCK_CLASS_H
# define BLOCK_CLASS_H

class	Block : public Object
{
	public :
/*
** Constructors
*/
	Block(void);
	Block(const object &rhs);

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
