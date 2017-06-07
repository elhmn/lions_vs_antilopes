#ifndef TYPES_H
# define TYPE_H

typedef struct		s_pos
{
	int			x;
	int			y;
}					t_pos;

enum				e_objType
{
	LION = 0,
	ANTILOPE,
	FLAG,
	BLOCK,
	NONE,
};

#endif
