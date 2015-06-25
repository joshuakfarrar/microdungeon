#include <stdio.h>
#include <stdlib.h>
#include "monster.h"

struct Monster * createMonster(char * name, int health) {
	struct Monster * monster = malloc(sizeof(struct Monster));

	monster->name = name;
	monster->health = health;

	return monster;
}

int attackMonster(struct Monster * monster, int damage) {
	printf("You attack %s!\n", monster->name);

	monster->health -= damage;

	if (monster->health > 0) {
		printf("%s is still alive.\n", monster->name);
		return 0;
	} else {
		printf("You killed %s!\n", monster->name);
		destroyMonster(monster);
		return 1;
	}
}

void destroyMonster(struct Monster * monster) {
	free(monster);
}
