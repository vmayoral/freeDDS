/* OMG DDS Topic interface */

#ifndef _TOPIC_H
#define _TOPIC_H

#include "domain/domain_participant.h"
#include "infrastructure/qos_policy.h"

typedef struct Topic {
  /* pseudo-attributes */
  char *name;
  QoSPolicy* qos;
  DomainParticipant* domain_participant;
  
} Topic;

  /* pseudo-methods */
Topic * new_Topic(const char *); /* Shouldn't be used */
void delete_Topic(Topic *); /* Shouldn't be used */
void set_qos_Topic(struct Topic *, QoSPolicy*);
QoSPolicy* get_qos_Topic(struct Topic *); 

#endif /* _TOPIC_H */