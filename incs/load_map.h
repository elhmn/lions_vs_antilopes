#ifndef LOAD_MAP_H
# define LOAD_MAP_H

# define M_BLOCK			'1'
# define M_FLAG_E1			'2'
# define M_FLAG_E2			'3'
# define M_LION				'4'
# define M_ANTILOPE			'5'
# define M_EMPTY			' '

# define LEVEL_PATH     	"./levels/main.lvl"

void						load_map(const char *filePath, char ***map, int *w, int *h);

#endif
