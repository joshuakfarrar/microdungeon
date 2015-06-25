#ifndef ROOM_H
#define ROOM_H

#include "monster.h"

struct Room {
	char * name;

	struct Monster * bad_guy;

	struct Room * north;
	struct Room * south;
	struct Room * east;
	struct Room * west;
};

struct Room * createRoom(char * name);
int attackRoom(struct Room * room, int damage);

#endif
