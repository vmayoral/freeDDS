# Publisher
add_executable(publisher skeleton_publisher.c)
target_link_libraries(publisher publication )

# Subscriber
add_executable(subscriber skeleton_subscriber.c)
target_link_libraries(subscriber subscription )
