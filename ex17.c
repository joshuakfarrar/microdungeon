#include <stdio.h>
#include "map.h"
#include "monster.h"
#include "room.h"

int process_input(struct Map * game) {
	printf("\n> ");

	int ch = getchar();
	getchar();

	switch(ch) {
		case 'n':
			mapMove(game, NORTH);
			break;
		case 's':
			mapMove(game, SOUTH);
			break;
		case 'e':
			mapMove(game, EAST);
			break;
		case 'w':
			mapMove(game, WEST);
			break;
		case 'l':
			printf("%s\n\n", game->location->name);
			printf("You can go:\n");
			if (game->location->north) printf("NORTH\n");
			if (game->location->south) printf("SOUTH\n");
			if (game->location->east) printf("EAST\n");
			if (game->location->west) printf("WEST\n");
			break;
		case 'q':
			return 0;
			break;
		default:
			printf("%c\n", ch);
	}

	return 1;
}

int main(int argc, char * argv[]) {
	struct Map * game = createMap();

	initMap(game);

	while(process_input(game)) {
	}

	return 0;
}
