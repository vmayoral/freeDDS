/* OMG DDS Subscriber interface */

#ifndef _SUBSCRIBER_H
#define _SUBSCRIBER_H

#include "domain/domain_participant.h"
#include "infrastructure/qos_policy.h"
#include "subscription/data_reader.h"
#include "topic/topic.h"

typedef struct Subscriber {  
  /* pseudo-attributes */
  QoSPolicy* qos;
  DomainParticipant* domain_participant;
  // ToDo, change this to a linked list or some similar, dynamically allocated data structure
  // For now only one is linked
  DataReader* readers;
  
} Subscriber;

/* pseudo-methods */
Subscriber * new_Subscriber(QoSPolicy*, DomainParticipant*);
void delete_Subscriber(Subscriber *);
void set_qos_Subscriber(struct Subscriber *, QoSPolicy*);
QoSPolicy* get_qos_Subscriber(struct Subscriber *);
DataReader* create_datareader_Subscriber(struct Subscriber *, QoSPolicy*, Topic*);


#endif /* _SUBSCRIBER_H */