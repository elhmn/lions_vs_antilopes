#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include "error.h"
#include "Game.class.h"
#include "Object.class.h"//_DEBUG_//
#include "Lion.class.h"//_DEBUG_//
#include "load_map.h"//_DEBUG_//


#define SIZE_H			30
#define SIZE_W			60
// #define FPS				30
// #define SECOND			1000000.
// #define CLEAR()			printf("\033[H\033[2J")
// FLAGS ◇ ◆

/*
int		main(int ac, char **av)
{
	int		i;
	int		j;
	int		ret;

	(void)ac;
	(void)av;
	srand(time(NULL));
	while (42)
	{
		i = -1;
		CLEAR();
		while (++i < SIZE_H)
		{
			j = -1;
			while (++j < SIZE_W)
			{
				if (i == 0 || j == 0 || i == SIZE_H - 1 || j == SIZE_W - 1)
				{
					if (i == 0 || i == SIZE_H - 1)
						printf("-");
					else if (j == 0 || j == SIZE_W - 1)
						printf("|");
				}
				else if ((ret = rand() % 100) < 2)
				{
					printf("●");
				}
				else if (ret > 98)
				{
					printf("○");
				}
				else
					printf(" ");
			}
			printf("\n");
		}
		usleep(SECOND / FPS);
	}
}
*/

/*
** TODO
**
**	game header								ok
**	object header							ok
**	lion header								ok
**	antilope header							ok
**	flag header								ok
**	block header							ok
**	team header								ok
**	map header								ok
**	rendermanager header					ok
**	gamemanager header						ok
**	objectmanager header				 	ok
**	aimanager header			 			ok	
**
**	Then implement the actual cpp source
**
**	game dummy source						ok
**	object dummy source						ok	
**	lion dummy source						ok
**	antilope dummy source					ok
**	flag dummy source						ok
**	block dummy source						ok
**	team dummy source						ok
**	map dummy source						ok
**	rendermanager dummy source				...
**	gamemanager dummy source				...
**	objectmanager dummy source			 	...
**	aimanager dummy source			 		...
**
** May be delete Blocks
*/

int		main(int ac, char **av)
{
	Game		*game;

	if (!(game = Game::getInstance()))
		ERROR("game set to NULL");
	if (ac > 1)
		game->init(av[1]);
	else
		game->init();
	game->run();
	game->clean();
	return (0);
}
