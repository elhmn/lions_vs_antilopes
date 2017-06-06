#ifndef FLAG_CLASS_H
# define FLAG_CLASS_H

class	Flag : public Object
{
	public :
/*
** Constructors
*/
	Flag(void);
	Flag(const object &rhs);

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
