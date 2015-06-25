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
