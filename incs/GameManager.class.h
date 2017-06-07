#ifndef GAMEMANAGER_CLASS_H
# define GAMEMANAGER_CLASS_H

class		GameManager
{
	private :

/*
** Non member variables
*/

	static bool					_verbose;
	static GameManager			*_instance;

/*
** Constructors
*/
	GameManager(void);
	GameManager(const GameManager &rhs);

	public :

/*
** Destructor
*/

	~GameManager(void);

/*
** Non member functions
*/

	// Singleton getInstance
	static GameManager			*getInstance(void) const;

/*
** Operators overload
*/
	GameManager &operator=(const GameManager &rhs);


/*
** Member functions
*/

	// Actions
	void						update(void);
};

#endif
