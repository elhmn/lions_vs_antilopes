#ifndef LOAD_MAP_H
# define LOAD_MAP_H

# define M_BLOCK			'1'
# define M_FLAG_L			'2'
# define M_FLAG_A			'3'
# define M_LION				'4'
# define M_ANTILOPE			'5'
# define M_EMPTY			' '
# define M_LEAD				'x'
# define M_JAM				'J'
# define M_L_GETFLAG		'<'
# define M_A_GETFLAG		'>'


# define LEVEL_PATH     	"./levels/main.lvl"

void						load_map(const char *filePath, char ***map, int *w, int *h);
char						**mapDup(char **map, int w, int h);
void						freeMap(char ***map, int w, int h);
void						showMap(char **map, int w, int h);

#endif
