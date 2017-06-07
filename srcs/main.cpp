#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include "error.h"
#include "Game.class.h"

#define SIZE_H			30
#define SIZE_W			60
#define FPS				30
#define SECOND			1000000.
#define CLEAR()			printf("\033[H\033[2J")
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
**	object dummy source						...
**	lion dummy source						...
**	antilope dummy source					...
**	flag dummy source						...
**	block dummy source						...
**	team dummy source						...
**	map dummy source						...
**	rendermanager dummy source				...
**	gamemanager dummy source				...
**	objectmanager dummy source			 	...
**	aimanager dummy source			 		...
*/

int		main(void)
{
	Game		*game;

	if (!(game = Game::getInstance()))
		ERROR("game set to NULL");
	game->init();
	game->run();
	game->clear();
	return (0);
}
