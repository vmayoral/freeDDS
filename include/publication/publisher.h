/* OMG DDS Publisher interface */

#ifndef _PUBLISHER_H
#define _PUBLISHER_H

#include "domain/domain_participant.h"
#include "infrastructure/qos_policy.h"
#include "publication/data_writer.h"

typedef struct Publisher {
  /* pseudo-attributes */
  QoSPolicy* qos;
  DomainParticipant* domain_participant;
  // ToDo, change this to a linked list or some similar dynamically allocated data structure  
  // For now only one is linked
  DataWriter* writters;
  
} Publisher;

/* pseudo-methods */
Publisher * new_Publisher(QoSPolicy*, DomainParticipant*);
void delete_Publisher(Publisher *);
void set_qos_Publisher(struct Publisher *, QoSPolicy*);
QoSPolicy* get_qos_Publisher(struct Publisher *);
// QoSPolicy instance pointer is passed because different DataReaders might have
// different timing contraints
DataWriter* create_datawriter_Publisher(struct Publisher *, QoSPolicy*, Topic*);

#endif /* _PUBLISHER_H */