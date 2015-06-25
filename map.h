#ifndef MAP_H
#define MAP_H

#include "room.h"

typedef enum {
	NORTH, SOUTH, EAST, WEST
} Direction;

struct Map {
	struct Room * start;
	struct Room * location;
};

struct Map * createMap();
void initMap(struct Map * map);
struct Room * mapMove(struct Map * map, Direction direction);
int attackMap(struct Map * map, int damage);

#endif
