#ifndef ROOM_H
#define ROOM_H

#include "monster.h"

struct Room {
	Monster * bad_guy;

	struct Room * north;
	struct Room * south;
	struct Room * east;
	struct Room * west;
}

#endif
