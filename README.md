freeDDS
=======

_freeDDS_ is an open source Data Distribution Service (DDS) minimal implementation for embedded devices that should run on _bare-metal_.

### Milestones
This section gives an overview of the milestones needed to complete freeDDS. It also provides an effort to approximate the time needs for each one of the tasks:

- [x] Quick overview/understand fo the OMG DDS standart `[1 week]`
    - [ ] Read/understand deeply the OMG DDS standart `[2 weeks]`
- [ ] Implement a basic skelethon for the DDS classes `[1 week]`
- [ ] Use the POSIX network stack to create a simple UDP/IP publisher/subscriber example `[ <1 week ]`
- [ ] Read/understand the OMG RTPS protocol `[2 weeks ]`
- [ ] Implement the RTPS layer for freeDDS `[ 3 weeks]`
    - [ ] Assess the RT aspects of the overall DDS implementation `[ 2 weeks]` 
- [ ] Evaluate the overall implementation (wireshark) and do interfacing tests with other DDSs `[ 2 weeks]`
- [ ] ROS client nano library client API `[ 2 weeks]` 
- [ ] ROS 2 Desktop <-> ROS 2 Embedded tests `[ 4 weeks]`

Total estimated `20 weeks`.

### Code structure
The code has been designed according to the DDS specification and it is structured in 5 modules ("Data Distribution Service for Real-time Systems, v1.2", pg. 24):

>- The Infrastructure Module (`src/infrastructure`) defines the abstract classes and the interfaces that are refined by the other modules. It also
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


- The code has been programmed in *ANSI C - C11* ([link to a draft](http://www.open-std.org/jtc1/sc22/wg14/www/docs/n1570.pdf)).
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

- In order to make the implementation suitable to _deep-embedded_ systems with low RAM characteristics, the code passes memory pointers instead of making local copies and dynamic memory will be only used in an intial allocation phase.

![](http://osrfoundation.org/assets/images/osrf_masthead.png)