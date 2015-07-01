#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "mud.h"
#include "map.h"
#include "monster.h"
#include "room.h"

int process_input(struct Map * game) {
	printf("\n> ");

	char ch[MAX_INPUT_LENGTH];

	fgets(ch, MAX_INPUT_LENGTH, stdin);

	// chomp trailing newline
	ch[strcspn(ch, "\n")] = 0;

	int damage = rand() % 4;

	if (strcmp(ch, "quit") == 0 || strcmp(ch, "q") == 0) {
		printf("The dungeon swirls and you wake up...\n");
		return 0;
	} else if (strcmp(ch, "a") == 0) {
		attackRoom(game->location, damage);
	} else if (strcmp(ch, "l") == 0) {
		lookRoom(game->location);
	} else if (strcmp(ch, "n") == 0) {
		mapMove(game, NORTH);
	} else if (strcmp(ch, "s") == 0) {
		mapMove(game, SOUTH);
	} else if (strcmp(ch, "e") == 0) {
		mapMove(game, EAST);
	} else if (strcmp(ch, "w") == 0) {
		mapMove(game, WEST);
	} else {
		printf("I have no idea what you're trying to do\n");
	}

	return 1;
}

int main(int argc, char * argv[]) {
	// initialize with some randomness
	srand(time(NULL));

	struct Map * game = createMap();

	initMap(game);

	lookRoom(game->location);

	while(process_input(game)) {
	}

	return 0;
}
