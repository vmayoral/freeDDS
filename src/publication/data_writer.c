/* OMG DDS DataWriter implementation */

#include "publication/data_writer.h"
#include <stdio.h>
#include <stdlib.h>

DataWriter * new_DataWriter(QoSPolicy* qos, DomainParticipant* dmp, Topic* topic)
{
	DataWriter *p = (DataWriter *) malloc(sizeof(DataWriter));
	p->qos = qos; 
	p->domain_participant = dmp;
	p->topic = topic;
	return p;
}

void delete_DataWriter(DataWriter *self)
{
	// since the DataWriter is a wrapper of topic, it should free
	// the Topic instance as well
	delete_Topic(self->topic);
	free(self);
}

void set_qos_DataWriter(struct DataWriter *self, QoSPolicy* qos_policy)
{
	self->qos = qos_policy;
}

QoSPolicy* get_qos_DataWriter(struct DataWriter *self)
{
	return self->qos;
}

DataWriter* write_DataWriter(struct DataWriter * self, struct Data data);
{
	printf("Writing %d to topic %s\n", data.value, self->topic->name);
}