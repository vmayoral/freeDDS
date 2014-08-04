/* OMG DDS Topic implementation */

#include "topic/topic.h"
#include <string.h>
#include <stdlib.h>

Topic * new_Topic(const char *name, QoSPolicy* qos, DomainParticipant domain_participant)
{
  Topic* topic = (Topic*) malloc(sizeof(Topic));
  topic->name =  (char *) malloc((strlen(name) + 1)* sizeof(char));
  strcpy(topic->name, name);
  topic->qos = qos;
  topic->domain_participant = domain_participant;
  return topic;
}

void delete_Topic(Topic *t)
{
  free(t->name);
  // Domain participant and qos shouldn't be released here
  free(t);
}

void set_qos_Topic(struct Topic *t, QoSPolicy* qos)
{
  t->qos = qos;
}

QoSPolicy* get_qos_Topic(struct Topic *t)
{
  return t->qos;
} 
