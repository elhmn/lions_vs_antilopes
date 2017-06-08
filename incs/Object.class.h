#ifndef OBJECT_CLASS_H
# define OBJECT_CLASS_H

#include "types.h"

class		Object
{
	private :

/*
**	Non member variables
*/

	protected :

/*
**	Non member variables
*/
	
	static bool			_verbose;
	static int			_count; 

/*
** Member variables 
*/

	e_objType			_type;
	t_pos				_pos;
	t_pos				_nextPos;
	float				_speed;
	bool				_hasFlag;

/*
** Member functions 
*/

// Setters
	void				setType(const e_objType type);
	void				setSpeed(float speed);

	public :
	
/*
** Constructors
*/
	Object(void);
	Object(const Object &rhs);

/*
** Destructor
*/
	~Object(void);

/*
** Operators overload
*/
	Object &operator=(const Object &rhs);

/*
** Member functions 
*/

	// Actions
 	virtual void		update(void);


	// Getters
	const e_objType		getType(void) const;
	const t_pos			&getPos(void) const;
	const t_pos			&getNextPos(void) const;
	const float			getSpeed(void) const;

	// Setters
	void				setPos(const int x, const int y);
	void				setNextPos(const int x, const int y);
/*
** Non member functions 
*/
	// Getters
	static const int	getCount(void);
};

#endif
