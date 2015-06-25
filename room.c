#include <stdio.h>
#include <stdlib.h>
#include "room.h"

struct Room * createRoom(char * name) {
	struct Room * room = malloc(sizeof(struct Room));

	room->name = name;

	return room;
}

int attackRoom(struct Room * room, int damage) {
	if ( room->bad_guy ) {
		return attackMonster(room->bad_guy, damage);
	} else {
		printf("There's nothing here!\n");
		return 0;
	}
}
