/* tankgame.c, drives the class */
#include <stdio.h>
#include "tank.h"
 
int main(void) {
  Tank *tank_a = new_Tank("Alice");
  Tank *tank_b = new_Tank("Bob");
  Tank *tank_c = new_Tank("Carol");
 
  int alive_tanks = 3;
 
  while (alive_tanks > 1) {
    printf("\n");
    printf("a: ");
    tank_a->stats(tank_a);
    printf("b: ");
    tank_b->stats(tank_b);
    printf("c: ");
    tank_c->stats(tank_c);
 
    printf("Who fires? ");
    char first = getchar();
    getchar(); /* junky \n */
    Tank *first_tank;
    if (first == 'a') first_tank = tank_a;
    else if (first == 'b') first_tank = tank_b;
    else if (first == 'c') first_tank = tank_c;
    else {
      printf("No such tank!\n");
      continue;
    }
    printf("Whom at? ");
    char second = getchar();
    getchar(); /* junky \n */
    Tank *second_tank;
    if (second == 'a') second_tank = tank_a;
    else if (second == 'b') second_tank = tank_b;
    else if (second == 'c') second_tank = tank_c;
    else {
      printf("No such tank!\n");
      continue;
    }
 
    if (!first_tank->alive || !second_tank->alive) {
      printf("One of those tanks is dead!\n");
      continue;
    }
 
    printf("\n******************************\n");
    first_tank->fire_at(first_tank, second_tank);
    if (!second_tank->alive) {
      alive_tanks--;
    }
    printf("******************************\n");
  }
 
  if (tank_a->alive) {
    printf("%s is the winner!\n", tank_a->name);
  } else if (tank_b->alive) {
    printf("%s is the winner!\n", tank_b->name);
  } else if (tank_c->alive) {
    printf("%s is the winner!\n", tank_c->name);
  }
 
  delete_Tank(tank_a);
  delete_Tank(tank_b);
  delete_Tank(tank_c);
 
  return 0;
}