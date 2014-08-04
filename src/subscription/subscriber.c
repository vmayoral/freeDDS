/* OMG DDS Subscriber implementation */

#include "subscription/subscriber.h"
#include <stdlib.h>

Subscriber* new_Subscriber(QoSPolicy* qos, DomainParticipant* dmp)
{
	Subscriber *p = (Subscriber *) malloc(sizeof(Subscriber));
	p->qos = qos; 
	p->domain_participant = dmp;
	return p;
}

void delete_Subscriber(Subscriber *self)
{	
	// ToDo release it one by one if it's a queue
	delete_DataReader(self->readers)
	free(self);
}

void set_qos_Subscriber(struct Subscriber *self, QoSPolicy* qos_policy)
{
	self->qos = qos_policy;
}

QoSPolicy* get_qos_Subscriber(struct Subscriber *self)
{
	return self->qos;
}

/*
	QoSPolicy instance pointer is passed because different DataWriters might have
	different timing contraints
*/
DataWriter* create_datareader_Subscriber(struct Subscriber *self, QoSPolicy* qos, Topic* topic);
{
	//ToDo queue it up and return a pointer to it
	self->readers = new_DataReader(qos, self->domain_participant, topic);
	return self->readers;
}