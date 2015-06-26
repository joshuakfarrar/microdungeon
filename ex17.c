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
			lookRoom(game->location);
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

	lookRoom(game->location);

	while(process_input(game)) {
	}

	return 0;
}
