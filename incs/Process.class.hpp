#ifndef PROCESS_CLASS_HPP
# define PROCESS_CLASS_HPP

# include <iostream>
# include "Camera.class.hpp"
# include "Coord.class.hpp"

class	Process
{
	private:
	static Process			*_instance;
	static bool				_verbose;
	Camera					*_c1;
	Camera					*_c2;

// Constructors
	Process(void);
	Process(const Process &rhs);

	public:
//	Process &operator=(const Process &rhs);

// Destructor
	~Process(void);

// Actions
	void					parse(char **argv);
	Coord					*getPointCoordinate(void);

// Getters
	static bool				getVerbose(void);
	static Process			*getInstance(void);
	Camera					*getC1(void) const;
	Camera					*getC2(void) const;
};

#endif
