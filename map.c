#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "room.h"
#include "monster.h"

struct Map * createMap() {
	struct Map * map = malloc(sizeof(struct Map)); 

	return map;
}

void initMap(struct Map * map) {
	// make rooms
	struct Room * hall = createRoom("The Great Hall");
	struct Room * throne = createRoom("The Throne Room");
	struct Room * arena = createRoom("The Arena");
	struct Room * kitchen = createRoom("The Kitchen");

	// link rooms
	hall->north = throne;

	throne->east = kitchen;
	throne->south = hall;
	throne->west = arena; 

	arena->east = throne;
	kitchen->west = throne;

	// add minotaur to arena
	arena->bad_guy = createMonster("Minotaur", 12);

	// set starting location
	map->start = hall;
	map->location = map->start;

}

struct Room * mapMove(struct Map * map, Direction direction) {
	struct Room * next;

	if (direction == NORTH && map->location->north) {
		next = map->location->north;
	} else if (direction == SOUTH && map->location->south) {
		next = map->location->south;
	} else if (direction == EAST && map->location->east) {
		next = map->location->east;
	} else if (direction == WEST && map->location->west) {
		next = map->location->west;
	} else {
		printf("You can't go in that direction.");
	}

	if (next) {
		map->location = next;
		lookRoom(map->location);
	}

	return map->location;
}

int attackMap(struct Map * map, int damage) {
	attackRoom(map->location, damage);
	return 0;
}
