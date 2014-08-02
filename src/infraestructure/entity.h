/* OMG DDS Entity interface */

#ifndef _ENTITY_H
#define _ENTITY_H

#include "qos_policy.h"

typedef struct Entity {
  /* attributes */
  char *name;
  QoSPolicy qos;
 
  /* methods */
  void (*enable)(const struct Entity *);
  void (*set_qos)(struct Entity *);
  void (*get_qos)(struct Entity *);
  void (*get_listener)(struct Entity *);
  void (*set_listener)(struct Entity *);
 
} Entity;

#endif /* _ENTITY_H */