#include <stdio.h>
#include "monster.h"
#include "room.h"

int main(int argc, char * argv[]) {
	struct Room * room = createRoom("Great Hall");

	struct Monster * monster = createMonster("Joshurawr", 12);
	printf("Created %s!\n", monster->name);

	room->bad_guy = monster;

	attackRoom(room, 10);
	attackRoom(room, 10);

	return 0;
}
