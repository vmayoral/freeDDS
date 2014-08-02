/* OMG DDS QoSPolicy implementation */

#include "qos_policy.h"

QoSPolicy * new_QoSPolicy(const char *name, int priority)
{
  QoSPolicy *p = (QoSPolicy *) malloc(sizeof(QoSPolicy));
  p->priority = priority; 
  return p;
}

void delete_QoSPolicy(QoSPolicy *qos)
{
  free(qos);
}
