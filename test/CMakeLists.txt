aux_source_directory(. SRC_LIST)

add_executable(test test.cc)
add_executable(http http.cc)
add_executable(main main.cc)

target_link_libraries(test WebServer)
target_link_libraries(http WebServer)