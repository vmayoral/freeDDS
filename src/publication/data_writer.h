/* OMG DDS DataWritter interface */

#ifndef _DATA_WRITER_H
#define _DATA_WRITER_H

#include "../domain/domain_participant.h"
#include "../infraestructure/qos_policy.h"
#include "../topic/data.h"
#include "../topic/topic.h"


typedef struct DataWritter {
  /* pseudo-attributes */
  QoSPolicy qos;
  DomainParticipant domain_participant;  
  Topic* topic;
  
} DataWritter;

/* pseudo-methods */
DataWritter * new_DataWritter(QoSPolicy*, DomainParticipant*, Topic*);
void delete_DataWritter(DataWritter *);
void set_qos_DataWritter(struct DataWritter *, QoSPolicy*);
QoSPolicy* get_qos_DataWritter(struct DataWritter *);
void write_DataWritter(struct DataWritter *, struct Data);

#endif /* _DATA_WRITER_H */