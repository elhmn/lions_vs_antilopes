#ifndef RENDERMANAGER_CLASS_H
# define RENDERMANAGER_CLASS_H

#define CLEAR()			printf("\033[H\033[2J")

# define M_RENDER_EMPTY				" "
# define M_RENDER_BORD_H			"-"
# define M_RENDER_BORD_V			"|"
# define M_RENDER_BLOCK				"."

#ifdef UNICODE
	# define M_RENDER_FLAG_E1		"◇"
	# define M_RENDER_FLAG_E2		"◆"
	# define M_RENDER_LION			"○"
	# define M_RENDER_ANTILOPE		"●"
# else
	#  define M_RENDER_FLAG_E1		"A"
	#  define M_RENDER_FLAG_E2		"L"
	#  define M_RENDER_LION			"a"
	#  define M_RENDER_ANTILOPE		"l"
# endif

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
