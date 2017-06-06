#ifndef ANTILOPE_CLASS_H
# define ANTILOPE_CLASS_H

class	Antilope : public Object
{
	public :
/*
** Constructors
*/
	Antilope(void);
	Antilope(const object &rhs);

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
