/* Basic skelethon tests */
#include <stdio.h>
#include "infrastructure/qos_policy.h"
#include "domain/domain_participant.h"
#include "subscription//subscriber.h"
#include "subscription//data_reader.h"
#include "topic/topic.h"
#include "topic/data.h"

int main()
{
	// Create a QoS Policy
	QoSPolicy* myqos = new_QoSPolicy(10);
	
	// Create a domain participant
	DomainParticipant* dmp = new_DomainParticipant(myqos);

	// Create a subscriber
	Subscriber* subscriber = new_Subscriber(myqos, dmp);
	
	// Domain participant creates a topic called "foo"
	Topic* t = create_topic_DomainParticipant("foo", myqos, dmp);
	
	// Subscriber creates a data reader to the topic foo
	//		a reference to the data reader is stored in the subscriber (ideally in a linked list)
	//		but the function returns the data reader just created 
	DataReader* dr = create_datareader_Subscriber(subscriber, myqos, t)

	// Read the data
	Data* data = read_DataReader(dr)

	return 0

}