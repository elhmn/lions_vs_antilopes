#ifndef GAME_CLASS_H
# define GAME_CLASS_H

class		Game
{
	private:

/*
** Non member variables
*/

	static bool			_verbose;
	static Game			*_instance;


/*
** Member variables 
*/

	// Game Attibutes
	Team				*_Lions;
	Team				*_Antilopes;
	Map					*_map;
	Object				*_objects;

	// Managers
	AIManager			*_aiManager;
	RenderManager		*_renderManager;
	GameManager			*_gameManager;
	ObjectManager		*_objectManager;

/*
** Constructors
*/
	Game(void);
	Game(const Game &rhs);

	public:

/*
** Destructor
*/

	~Game(void);

/*
** Non member functions
*/

	// Singleton getInstance
	static Game			*getInstance(void) const;

/*
** Operators overload
*/
	Game &operator=(const Game &rhs);


/*
** Member functions 
*/

	// Actions
	void				init(void);
	void				run(void);
	void				clear(void);


	// Getters
	Team				*getLions(void) const;
	Team				*getAntilopes(void) const;
	Map					*getMap(void) const;
	Object				*getObjects(void) const;
	AIManager			*getAIManager(void) const;
	RenderManager		*getRenderManager(void) const;
	GameManager			*getGameManager(void) const;
	ObjectManager		*getObjectManager(void) const;
};

#endif
