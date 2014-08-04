# Data Writter
add_library( data_writer data_writer.c )
target_link_libraries(data_writer domain infrastructure data topic)

# Publisher
add_library( publication publisher.c )
target_link_libraries(publication domain infrastructure data topic data_writer)
