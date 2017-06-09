#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include "error.h"
#include "Game.class.h"

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
**	rendermanager dummy source			    ok	
**	gamemanager dummy source				ok
**	objectmanager dummy source			 	ok
**	aimanager dummy source			 		ok
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
