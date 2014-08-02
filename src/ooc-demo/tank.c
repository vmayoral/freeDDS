/* tank.c, the implementation of the Tank class */
#include <stdio.h> /* printf */
#include <stdlib.h> /* malloc, free */
#include <string.h> /* strlen, strcpy */
#include "tank.h"
 
static void stats(const Tank *self) {
  if (self->alive) {
    printf("%s (%i armor, %i shells)\n", self->name, self->armor, self->ammo);
  } else {
    printf("%s (DEAD)\n", self->name);
  }
}
 
static void fire_at(Tank *self, Tank *enemy) {
  if (self->ammo > 0) {
    self->ammo -= 1;
    printf("%s fires on %s\n", self->name, enemy->name);
    enemy->hit(enemy);
  } else {
    printf("%s has no shells!\n", self->name);
  }
}
 
static void hit(Tank *self) {
  self->armor -= 20;
  printf("%s is hit!\n", self->name);
  if (self->armor <= 0) {
    self->explode(self);
  }
}
 
static void explode(Tank *self) {
  self->alive = 0;
  printf("%s explodes!\n", self->name);
}
 
Tank * new_Tank(const char *name) {
  Tank *tank = (Tank *) malloc(sizeof(Tank));
 
  tank->name = (char *) malloc((strlen(name) + 1)* sizeof(char));
  strcpy(tank->name, name);
  tank->alive = 1;
  tank->ammo = 5;
  tank->armor = 60;
 
  tank->stats = stats;
  tank->fire_at = fire_at;
  tank->hit = hit;
  tank->explode = explode;
 
  return tank;
}
 
void delete_Tank(Tank * tank) {
  free(tank->name);
  free(tank);
}