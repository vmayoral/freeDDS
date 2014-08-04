/* OMG DDS DataWriter interface */

#ifndef _DATA_WRITER_H
#define _DATA_WRITER_H

#include "domain/domain_participant.h"
#include "infrastructure/qos_policy.h"
#include "topic/data.h"
#include "topic/topic.h"


typedef struct DataWriter {
  /* pseudo-attributes */
  QoSPolicy qos;
  DomainParticipant domain_participant;  
  Topic* topic;
  
} DataWriter;

/* pseudo-methods */
DataWriter * new_DataWriter(QoSPolicy*, DomainParticipant*, Topic*); /* Shouldn't be used */
void delete_DataWriter(DataWriter *); /* Shouldn't be used */
void set_qos_DataWriter(struct DataWriter *, QoSPolicy*);
QoSPolicy* get_qos_DataWriter(struct DataWriter *);
void write_DataWriter(struct DataWriter *, struct Data);

#endif /* _DATA_WRITER_H */