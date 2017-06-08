#ifndef TYPES_H
# define TYPES_H

# define TAB		'\t'

typedef struct		s_pos
{
	int			x;
	int			y;

	void		setPos(int x, int y)
	{
		this->x = x;
		this->y = y;
	};
}					t_pos;

enum				e_objType
{
	LION = 1,
	ANTILOPE,
	FLAG,
	BLOCK,
	NONE,
};

#endif
