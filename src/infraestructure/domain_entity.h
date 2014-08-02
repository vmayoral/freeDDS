/* OMG DDS DomainEntity interface */

#ifndef _DOMAIN_ENTITY_H
#define _DOMAIN_ENTITY_H

#include "../domain/domain_participant.h"
#include "qos_policy.h"

typedef struct DomainEntity {
  /* attributes */
  char *name;
  QoSPolicy qos;
  DomainParticipant domain_participant;
 
  /* methods */
  void (*enable)(const struct DomainEntity *);
  void (*set_qos)(struct DomainEntity *);
  void (*get_qos)(struct DomainEntity *);
  void (*get_listener)(struct DomainEntity *);
  void (*set_listener)(struct DomainEntity *);
 
} DomainEntity;

#endif /* _DOMAIN_ENTITY_H */