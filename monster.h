#ifndef MONSTER_H
#define MONSTER_H

struct Monster {
	char * name;
	int health;
};

struct Monster * createMonster(char * name, int health);
void destroyMonster(struct Monster * monster);
int attackMonster(struct Monster * monster, int damage);

#endif
