#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

#define SIZE_H			30
#define SIZE_W			60
#define FPS				30
#define SECOND			1000000.
#define CLEAR()			printf("\033[H\033[2J")
// FLAGS ◇ ◆

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
