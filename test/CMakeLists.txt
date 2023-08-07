aux_source_directory(. SRC_LIST)

add_executable(test test.cc)
add_executable(http http.cc)

target_link_libraries(test WebServer muduo_net muduo_base)
target_link_libraries(http WebServer)