/* OMG DDS QoSPolicy implementation */

#include "infrastructure/qos_policy.h"
#include <stdlib.h>

QoSPolicy * new_QoSPolicy(int priority)
{
  QoSPolicy *p = (QoSPolicy *) malloc(sizeof(QoSPolicy));
  p->priority = priority; 
  return p;
}

void delete_QoSPolicy(QoSPolicy *qos)
{
  free(qos);
}
