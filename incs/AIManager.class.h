#ifndef AIMANAGER_CLASS_H
# define AIMANAGER_CLASS_H

class		AIManager
{
	private :

/*
** Non member variables
*/

	static bool					_verbose;
	static AIManager		*_instance;

/*
** Member variables
*/

/*
** Constructors
*/
	AIManager(void);
	AIManager(const AIManager &rhs);

	public :

/*
** Destructor
*/

	~AIManager(void);

/*
** Non member functions
*/

	// Singleton getInstance
	static AIManager		*getInstance(void);

/*
** Operators overload
*/
	AIManager &operator=(const AIManager &rhs);


/*
** Member functions
*/

	// Actions
	void						simulate(void);
};

#endif
