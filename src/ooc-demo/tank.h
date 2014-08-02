/* tank.h, the definition for the Tank class */
typedef struct Tank {
  /* attributes */
  char *name;
  int alive;
  int ammo;
  int armor;
 
  /* methods */
  void (*stats)(const struct Tank *);
  void (*fire_at)(struct Tank *, struct Tank *);
  void (*hit)(struct Tank *);
  void (*explode)(struct Tank *);
 
} Tank;
 
Tank * new_Tank(const char *);
void delete_Tank(Tank *);