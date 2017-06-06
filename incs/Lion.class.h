#ifndef LION_CLASS_H
# define LION_CLASS_H

class	Lion : public Object
{
	public :
/*
** Constructors
*/
	Lion(void);
	Lion(const object &rhs);

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
