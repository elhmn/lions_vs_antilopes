#ifndef CAMERA_CLASS_HPP
# define CAMERA_CLASS_HPP

# include <iostream>
# include "Coord.class.hpp"


class		Camera
{
	private:
	Coord 				*_orientation;
	Coord 				*_point;
	static bool			_verbose;

	public:

//Constructors
	Camera(void);
	Camera(const Camera &rhs);
//	Camera &operator=(const Camera &rhs);

// Destructor
	~Camera(void);

// Getters
	Coord				*getPoint(void) const;
	Coord				*getOrientation(void) const;
	static bool			getVerbose(void);

// Setters
	void				setPoint(Coord *c);
	void				setOrientation(Coord *c);

//Others
	void				dumpCamera(void);
};

#endif
