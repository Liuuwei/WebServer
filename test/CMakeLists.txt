aux_source_directory(. SRC_LIST)

add_executable(server server.cc)
add_executable(back back.cc)
add_executable(http http.cc)
add_executable(__server __server.cc)
add_executable(__back __back.cc)

target_link_libraries(server WebServer)
target_link_libraries(back WebServer stdc++fs)
target_link_libraries(http WebServer)