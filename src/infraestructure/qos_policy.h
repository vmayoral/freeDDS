/* OMG DDS QoSPolicy interface */

#ifndef _QOS_POLICY_H
#define _QOS_POLICY_H

typedef struct QoSPolicy {
  /* attributes */
  int priority;
  
} QoSPolicy;

QoSPolicy * new_QoSPolicy(const char *, int);
void delete_QoSPolicy(QoSPolicy *);

#endif /* _QOS_POLICY_H */