# Data Reader
add_library( data_reader data_reader.c )
target_link_libraries(data_reader domain infrastructure data topic)

# Subscriber
add_library( subscription subscriber.c )
target_link_libraries(subscription domain infrastructure data topic data_reader)
