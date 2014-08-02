/* OMG DDS DataReader implementation */

#include "data_reader.h"
#include "stdio.h"

DataReader * new_DataReader(QoSPolicy* qos, DomainParticipant* dmp, Topic* topic)
{
	DataReader *p = (DataReader *) malloc(sizeof(DataReader));
	p->qos = qos; 
	p->domain_participant = dmp;
	p->topic = topic;
	return p;
}

void delete_DataReader(DataReader *self)
{
	// since the DataReader is a wrapper of topic, it should free
	// the Topic instance as well
	delete_Topic(self->topic);
	free(self);
}

void set_qos_DataReader(struct DataReader *self, QoSPolicy* qos_policy)
{
	self->qos = qos_policy;
}

QoSPolicy* get_qos_DataReader(struct DataReader *self)
{
	return self->qos;
}

Data* read_DataReader(struct DataReader *)
{
	printf("Reading from topic %s\n", self->topic->name);
	return NULL; //Fix
}

bool on_data_available_DataReader(struct DataReader *)
{
	return false;
}
