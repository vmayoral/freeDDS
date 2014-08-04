/* Basic skelethon tests */
#include <stdio.h>
#include "infrastructure/qos_policy.h"
#include "domain/domain_participant.h"
#include "publication/publisher.h"
#include "publication/data_writer.h"
#include "topic/topic.h"
#include "topic/data.h"

int main()
{
	// Create a QoS Policy
	QoSPolicy* myqos = new_QoSPolicy(10);
	
	// Create a domain participant
	DomainParticipant* dmp = new_DomainParticipant(myqos);

	// Create a publisher
	Publisher* publisher = new_Publisher(myqos, dmp);
	
	// Domain participant creates a topic called "foo"
	Topic* t = create_topic_DomainParticipant("foo", myqos, dmp);
	
	// Publisher creates a data writter to the topic foo
	//		a reference to the datawritter is stored in the publisher (ideally in a linked list)
	//		but the function returns the datawritter just created 
	DataWritter* dw = create_datawriter_Publisher(publisher, myqos, t)

	// Construct Data to be sent
	data = { .value = 12 
			// more fields
			};

	// Write the data
	write_DataWritter(dw, data);

	return 0

}