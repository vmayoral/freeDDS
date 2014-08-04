# Domain library
add_library( domain domain_participant.c )
target_link_libraries(domain infrastructure)