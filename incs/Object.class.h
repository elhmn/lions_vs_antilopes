#ifndef OBJECT_CLASS_H
# define OBJECT_CLASS_H

#include "types.h"

class		Object
{
	private:

/*
**	Non member variables
*/
	static int			_count; 

	protected:

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
	void				setType(const e_type type);
	void				setPos(const int x, const int y);
	void				setSprite1(const char sprite);
	void				setSprite2(const char sprite);
	void				setSpeed(float speed);

	public:

/*
** constructors
*/
	object(void);
	object(const object &rhs);

/*
** destructor
*/
	~object(void);

/*
** Operators overload
*/
	Object &operator=(const Object &rhs);

/*
** Member functions 
*/

	// Actions
	virtual void		update(void) const;


	// Getters
	e_objType			getType(void) const;
	t_pos				getPos(void) const;
	char				getSprite1(void) const;
	char				getSprite2(void) const;

/*
** Non member functions 
*/
	// Getters
	static int			getCount(void) const;
};

#endif
