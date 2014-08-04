/* OMG DDS DomainParticipant implementation */

#include "domain/domain_participant.h"
#include <stdlib.h>

DomainParticipant * new_DomainParticipant(QoSPolicy* qos_policy) 
{
  DomainParticipant *dmp = (DomainParticipant *) malloc(sizeof(DomainParticipant));
  dmp->qos = qos_policy; 
  return dmp;
}

void delete_DomainParticipant(DomainParticipant *dmp)
{
  // dmp->qos doesn't have to be released
  free(dmp);
}

void set_qos_DomainParticipant(struct DomainParticipant *self, QoSPolicy* qos_policy)
{
  self->qos = qos_policy;
}

QoSPolicy get_qos_DomainParticipant(struct DomainParticipant * self)
{
  return self->qos;
}

Publisher* create_publisher_DomainParticipant(QoSPolicy* qos, struct DomainParticipant * self)
{
  TBD
}

Subscriber* create_subscriber_DomainParticipant(QoSPolicy* qos, struct DomainParticipant * self)
{
  TBD
}

Topic* create_topic_DomainParticipant(const char* name, QoSPolicy* qos, struct DomainParticipant *self)
{
  new_Topic("foo", qos, self);
}
