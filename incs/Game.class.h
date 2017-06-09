#ifndef GAME_CLASS_H
# define GAME_CLASS_H

# include "AIManager.class.h"
# include "RenderManager.class.h"
# include "GameManager.class.h"
# include "ObjectManager.class.h"
# include "Team.class.h"
# include "Object.class.h"
# include "Map.class.h"
# include "load_map.h"

# define FPS				30
# define SECOND				1000000.
# define ANTILOPES_COUNT	30
# define LIONS_COUNT		8

class		Game
{
	private :

/*
** Non member variables
*/

	static bool			_verbose;
	static Game			*_instance;


/*
** Member variables
*/

	// Game Attibutes
	Team				*_lions;
	Team				*_antilopes;
	Map					*_map;
	Object				**_objects;

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

	public :

/*
** Member variables
*/
	bool		reset;
/*
** Destructor
*/

	~Game(void);

/*
** Non member functions
*/

	// Singleton getInstance
	static Game			*getInstance(void);

/*
** Operators overload
*/
	Game &operator=(const Game &rhs);


/*
** Member functions
*/

	// Actions
	void				init(const char *levelPath = LEVEL_PATH);
	void				load(void);
	void				reload(void);
	void				run(void);
	void				clean(void);


	// Getters
	Team				*getLions(void) const;
	Team				*getAntilopes(void) const;
	Map					*getMap(void) const;
	Object				**getObjects(void) const;
	AIManager			*getAIManager(void) const;
	RenderManager		*getRenderManager(void) const;
	GameManager			*getGameManager(void) const;
	ObjectManager		*getObjectManager(void) const;
};

#endif
