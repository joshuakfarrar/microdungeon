#include <stdio.h>
#include <stdlib.h>
#include "room.h"
#include "monster.h"

struct Room * createRoom(char * name) {
	struct Room * room = malloc(sizeof(struct Room));

	room->name = name;

	return room;
}

int attackRoom(struct Room * room, int damage) {
	printf("Attacking room\n");
	if (room->bad_guy != NULL) {
		int result = attackMonster(room->bad_guy, damage);
		if (result == 1) {
			destroyMonster(room->bad_guy);
			room->bad_guy = NULL;
		}
		return result;
	} else {
		printf("There's nothing here!\n");
		return 0;
	}
}

void lookRoom(struct Room * room) {
	printf("\x1b[32m%s\x1b[0m\n", room->name);
	printf("\x1b[30;1m-------------------------------------------------------\x1b[0m\n\n");

	printf("You can go:");
	if (room->north) printf(" north");
	if (room->south) printf(" south");
	if (room->east) printf(" east");
	if (room->west) printf(" west");

	if (room->bad_guy) {
		printf("\n\x1b[35;1mA %s stares you down\x1b[0m\n", room->bad_guy->name);
	}
}
