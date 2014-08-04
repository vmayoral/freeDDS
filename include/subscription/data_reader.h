/* OMG DDS DataReader interface */

#ifndef _DATA_READER_H
#define _DATA_READER_H

#include "domain/domain_participant.h"
#include "infrastructure/qos_policy.h"
#include "topic/data.h"
#include "topic/topic.h"

typedef struct DataReader {
  /* pseudo-attributes */
  QoSPolicy* qos;
  DomainParticipant* domain_participant;
  Topic* topic;
  
} DataReader;

/* pseudo-methods */
DataReader * new_DataReader(QoSPolicy*, DomainParticipant*);
void delete_DataReader(DataReader *);
void set_qos_DataReader(struct DataReader *, QoSPolicy*);
QoSPolicy* get_qos_DataReader(struct DataReader *);
Data* read_DataReader(struct DataReader *);
int on_data_available_DataReader(struct DataReader *); 

#endif /* _DATA_READER_H */