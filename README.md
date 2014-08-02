freeDDS
=======

An open source Data Distribution Service (DDS) minimal implementation for embedded devices.

The code has been designed according to the DDS specification and it is structured in 5 modules ("Data Distribution Service for Real-time Systems, v1.2", pg. 24):

>- The Infrastructure Module (`src/infraestructure`) defines the abstract classes and the interfaces that are refined by the other modules. It also
provides support for the two interaction styles (notification- and wait- based) with the middleware.
- The Domain Module (`src/domain`) contains the DomainParticipant class that acts as an entry-point of the Service and acts as a
factory for many of the classes. The DomainParticipant also acts as a container for the other objects that make up the
Service.
- The Topic-Definition Module  (`src/topic`) contains the Topic, ContentFilteredTopic, and MultiTopic classes, the TopicListener
interface, and more generally, all that is needed by the application to define Topic objects and attach QoS policies to
them.
- The Publication Module (`src/publication`) contains the Publisher and DataWriter classes as well as the PublisherListener and
DataWriterListener interfaces, and more generally, all that is needed on the publication side.
- The Subscription Module (`src/subscription`) contains the Subscriber, DataReader, ReadCondition, and QueryCondition classes, as well
as the SubscriberListener and DataReaderListener interfaces, and more generally, all that is needed on the
subscription side.


### Design considerations:


- The code has been programmed in *ANSI C - C99*.
- Each one of the abstract concepts mentioned in the DDS standard has been coded using a _pseudo-OOP_ mechanism containing _pseudo-attributes_ and _pseudo-methods_. E.g., the header of the `Topic` interface:

```c
typedef struct Topic {
  /* pseudo-attributes */
  char *name;
  QoSPolicy* qos;
  DomainParticipant* domain_participant;
 
} Topic;

  /* pseudo-methods */
Topic * new_Topic(const char *);
void delete_Topic(Topic *);
void set_qos_Topic(struct Topic *, QoSPolicy*);
QoSPolicy* get_qos_Topic(struct Topic *); 
```

- In order to make the implementation suitable to _deep-embedded_ systems with low RAM characteristics, the code passes memory pointers instead of making local copies.

![](http://osrfoundation.org/assets/images/osrf_masthead.png)