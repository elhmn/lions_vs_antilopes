#ifndef OBJECT_CLASS_H
# define OBJECT_CLASS_H

#include "types.h"

class		Object
{
	private :

/*
**	Non member variables
*/
	static int			_count; 

	protected :

/*
**	Non member variables
*/
	
	static bool			_verbose;

/*
** Member variables 
*/

	e_objType			_type;
	t_pos				_pos;
	float				_speed;
	char				_sprite1;
	char				_sprite2;

/*
** Member functions 
*/

// Setters
	void				setType(const e_objType type);
	void				setSprite1(const char sprite);
	void				setSprite2(const char sprite);
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
	const char			getSprite1(void) const;
	const char			getSprite2(void) const;
	const float			getSpeed(void) const;

	// Setters
	void				setPos(const int x, const int y);
/*
** Non member functions 
*/
	// Getters
	static const int	getCount(void);
};

#endif
