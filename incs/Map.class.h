#ifndef MAP_CLASS_H
# define MAP_CLASS_H

# include "types.h"
# include <iostream>

class	Map
{
	private :

/*
**	Non member variables
*/
	static bool			_verbose;

/*
** Member variables
*/
	char				**_tab;
	char				**_tabTmp;
	int					_width;
	int					_height;

	public :
/*
** Constructors
*/
	Map(void);
	Map(const char *filePath);
	Map(const Map &rhs);

/*
** Destructor
*/
	~Map(void);

/*
** Operators overload
*/
	Map &operator=(const Map &rhs);

/*
** Member functions
*/
	//Getters
	char				**getTab(void) const;
	int					getWidth(void) const;
	int					getHeight(void) const;

	//Actions
	void				reset(void);
};

std::ostream& operator<<(std::ostream& os, const Map& rhs);

#endif
