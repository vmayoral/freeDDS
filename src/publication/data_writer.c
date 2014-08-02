/* OMG DDS DataWritter implementation */

#include "data_writer.h"
#include "stdio.h"

DataWritter * new_DataWritter(QoSPolicy* qos, DomainParticipant* dmp, Topic* topic)
{
	DataWritter *p = (DataWritter *) malloc(sizeof(DataWritter));
	p->qos = qos; 
	p->domain_participant = dmp;
	p->topic = topic;
	return p;
}

void delete_DataWritter(DataWritter *self)
{
	// since the DataWritter is a wrapper of topic, it should free
	// the Topic instance as well
	delete_Topic(self->topic);
	free(self);
}

void set_qos_DataWritter(struct DataWritter *self, QoSPolicy* qos_policy)
{
	self->qos = qos_policy;
}

QoSPolicy* get_qos_DataWritter(struct DataWritter *self)
{
	return self->qos;
}

DataWriter* write_DataWritter(struct DataWritter * self, struct Data data);
{
	printf("Writing %d to topic %s\n", data.value, self->topic->name);
}