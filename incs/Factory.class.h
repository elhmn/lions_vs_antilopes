#ifndef FACTORY_CLASS_H
# define FACTORY_CLASS_H

# include "Object.class.h"
# include "Lion.class.h"
# include "Antilope.class.h"
# include "types.h"

class	Factory
{
	private :

/*
** Non member variables
*/

	static bool			_verbose;
	static Factory		*_instance;

/*
** Constructors
*/
	Factory(void);
	Factory(const Factory &rhs);

	public :

/*
** Destructor
*/

	~Factory(void);

/*
** Non member functions
*/

	// Singleton getInstance
	static Factory			*getInstance(void);

/*
** Operators overload
*/
	Factory &operator=(const Factory &rhs);


/*
** Member functions
*/
	Object	*create(e_objType type);
};

#endif
