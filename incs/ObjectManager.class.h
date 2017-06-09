#ifndef OBJECTMANAGER_CLASS_H
# define OBJECTMANAGER_CLASS_H

# include <ctime>

# define WAIT_CLOCK			50.

class		ObjectManager
{
	private :

/*
** Non member variables
*/

	static bool					_verbose;
	static ObjectManager		*_instance;

/*
** Member variables
*/

/*
** Constructors
*/
	ObjectManager(void);
	ObjectManager(const ObjectManager &rhs);

	public :
	clock_t						c_start;
/*
** Destructor
*/

	~ObjectManager(void);

/*
** Non member functions
*/

	// Singleton getInstance
	static ObjectManager		*getInstance(void);

/*
** Operators overload
*/
	ObjectManager &operator=(const ObjectManager &rhs);


/*
** Member functions
*/

	// Actions
	void						destroy(void);
	void						spawn(void);
	void						update(void);
};

#endif
