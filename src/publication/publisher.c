/* OMG DDS Publisher implementation */

#include "publisher.h"

Publisher * new_Publisher(QoSPolicy* qos, DomainParticipant* dmp)
{
	Publisher *p = (Publisher *) malloc(sizeof(Publisher));
	p->qos = qos; 
	p->domain_participant = dmp;
	return p;
}

void delete_Publisher(Publisher *self)
{
	// ToDo, delete one by one if they are in a queue
	delete_DataWritter(self->writters);
	free(self);
}

void set_qos_Publisher(struct Publisher *self, QoSPolicy* qos_policy)
{
	self->qos = qos_policy;
}

QoSPolicy* get_qos_Publisher(struct Publisher *self)
{
	return self->qos;
}

/*
	QoSPolicy instance pointer is passed because different DataWriters might have
	different timing contraints
*/
DataWriter* create_datawriter_Publisher(struct Publisher *self, QoSPolicy* qos, Topic* topic);
{
	//ToDo queue it up and return a pointer to it
	self->writters = new_DataWritter(qos, self->domain_participant, topic);
	return self->writters;
}