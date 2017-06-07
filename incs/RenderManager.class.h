#ifndef RENDERMANAGER_CLASS_H
# define RENDERMANAGER_CLASS_H

class		RenderManager
{
	private :

/*
** Non member variables
*/

	static bool					_verbose;
	static RenderManager		*_instance;

/*
** Member variables
*/

/*
** Constructors
*/
	RenderManager(void);
	RenderManager(const RenderManager &rhs);

	public :

/*
** Destructor
*/

	~RenderManager(void);

/*
** Non member functions
*/

	// Singleton getInstance
	static RenderManager		*getInstance(void);

/*
** Operators overload
*/
	RenderManager &operator=(const RenderManager &rhs);


/*
** Member functions
*/

	// Actions
	void						render(void);
};

#endif
