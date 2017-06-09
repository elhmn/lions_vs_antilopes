#ifndef RENDERMANAGER_CLASS_H
# define RENDERMANAGER_CLASS_H

#define CLEAR()			std::cout <<"\033[H\033[2J"

# define M_RENDER_EMPTY				" "
# define M_RENDER_BORD_H			"-"
# define M_RENDER_BORD_V			"|"
# define M_RENDER_BLOCK				"."

// ☻ ☺  when got flag in Unicode

#ifdef UNICODE
	#  define M_RENDER_FLAG_L		"◇"
	#  define M_RENDER_FLAG_A		"◆"
	#  define M_RENDER_LION			"○"
	#  define M_RENDER_ANTILOPE		"●"
	#  define M_RENDER_LEAD			"♚"
	#  define M_RENDER_JAM			"⊕"
# else
	#  define M_RENDER_FLAG_L		"L"
	#  define M_RENDER_FLAG_A		"A"
	#  define M_RENDER_LION			"l"
	#  define M_RENDER_ANTILOPE		"a"
	#  define M_RENDER_LEAD			"e"
	#  define M_RENDER_JAM			"*"
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
