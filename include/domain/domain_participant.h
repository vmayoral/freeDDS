/* OMG DDS DomainParticipant interface */

#ifndef _DOMAIN_PARTICIPANT_H
#define _DOMAIN_PARTICIPANT_H

#include "infrastructure/qos_policy.h"
#include "publication/publisher.h"
#include "subscription/subscriber.h"
#include "topic/topic.h"

typedef struct DomainParticipant {
  /* pseudo-attributes */
  QoSPolicy* qos;

} DomainParticipant;

/* pseudo-methods */
DomainParticipant * new_DomainParticipant(QoSPolicy*);
void delete_DomainParticipant(DomainParticipant *);
void set_qos_DomainParticipant(struct DomainParticipant *, QoSPolicy*);
QoSPolicy get_qos_DomainParticipant(struct DomainParticipant *);
Publisher* create_publisher_DomainParticipant(QoSPolicy*, struct DomainParticipant *);
Subscriber* create_subscriber_DomainParticipant(QoSPolicy*, struct DomainParticipant *);
Topic* create_topic_DomainParticipant(const char*, QoSPolicy*, struct DomainParticipant *);
/* not sure if needed in a minimal impl. */
// void create_contentfilteredtopic(struct DomainParticipant *); 

#endif /* _DOMAIN_PARTICIPANT_H */