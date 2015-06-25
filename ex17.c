#include <stdio.h>
#include "monster.h"
#include "room.h"

int main(int argc, char * argv[]) {
	struct Monster * monster = createMonster("Joshurawr", 12);
	printf("Created %s!\n", monster->name);
	attackMonster(monster, 10);
	attackMonster(monster, 10);
	destroyMonster(monster);
	return 0;
}
