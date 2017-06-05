#ifndef COORD_CLASS_HPP
# define COORD_CLASS_HPP

# include <iostream>


class		Coord
{
	private:
	float				_x;
	float				_y;
	float				_z;
	static bool			_verbose;

	public:
//Constructors
	Coord(void);
	Coord(const Coord &rhs);
//	Coord &operator=(const Coord &rhs);

// Destructor
	~Coord(void);

// Getters
	float				getX(void) const;
	float				getY(void) const;
	float				getZ(void) const;
	static bool			getVerbose(void);

//Setters
	void				setX(float x);
	void				setY(float y);
	void				setZ(float z);

// Others
	void				dumpCoord(void) const;
};

#endif
