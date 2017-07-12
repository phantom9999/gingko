cmake_minimum_required(VERSION 3.7)
project(gingko)

set(CMAKE_CXX_STANDARD 11)

########################################################################
# 设置依赖

set(
        third
        /usr/
)

include_directories(libtorrent-rasterbar/include)

foreach (item ${third})
    set(include_dir "${include_dir}:${PROJECT_SOURCE_DIR}${item}/include")
    set(lib_dir "${lib_dir}:${PROJECT_SOURCE_DIR}${item}/lib")
endforeach ()

set(CMAKE_INCLUDE_PATH ${include_dir})
set(CMAKE_LIBRARY_PATH ${lib_dir})


########################################################################
# sqlite
include_directories(sqlite)
add_library(
        sqlite3
        sqlite/sqlite3.c
)
add_executable(
        sqlite3-cmd
        sqlite/shell.c
)
target_link_libraries(
        sqlite3-cmd
        sqlite3
        pthread
        dl
)

########################################################################
# minihttpd
include_directories(minihttpd/include)
aux_source_directory(minihttpd/src MINIHTTPD_SRC)
aux_source_directory(minihttpd/test MINIHTTPD_TEST)

add_library(
        minihttpd
        ${MINIHTTPD_SRC}
)

add_executable(
        minihttpd_test
        ${MINIHTTPD_TEST}
)

target_link_libraries(
        minihttpd_test
        minihttpd
        gtest
)

add_executable(
        eventloop_test
        minihttpd/sample/eventloop_test.cpp
)
target_link_libraries(
        eventloop_test
        minihttpd
)

add_executable(
        httpd_test
        minihttpd/sample/httpd_test.cpp
)
target_link_libraries(
        httpd_test
        minihttpd
)

add_executable(
        timer_in_mt_test
        minihttpd/sample/timer_in_mt_test.cpp
)
target_link_libraries(
        timer_in_mt_test
        minihttpd
)

add_executable(
        timer_test
        minihttpd/sample/timer_test.cpp
)
target_link_libraries(
        timer_test
        minihttpd
)

########################################################################
include_directories(bbts_protocol)
aux_source_directory(bbts_protocol BBTS_PROTOCOL)
add_library(
        bbts_protocol
        ${BBTS_PROTOCOL}
)


########################################################################
include_directories(
        gko-tracker/include
)

aux_source_directory(gko-tracker/src TRACKER_SRC)
add_executable(
        gko-tracker
        ${TRACKER_SRC}
)



ADD_EXECUTABLE(client_mock_infohash gko-tracker/clientmock/client_mock_infohash.cpp)
TARGET_LINK_LIBRARIES(client_mock_infohash bbts_protocol)

ADD_EXECUTABLE(client_mock gko-tracker/clientmock/client_mock.cpp)
TARGET_LINK_LIBRARIES(client_mock bbts_protocol)

ADD_EXECUTABLE(client_mock_s gko-tracker/clientmock/client_mock_s.cpp)
TARGET_LINK_LIBRARIES(client_mock_s bbts_protocol)

ADD_EXECUTABLE(ControlByInfohash gko-tracker/clientmock/ControlByInfohash.cpp)
TARGET_LINK_LIBRARIES(ControlByInfohash bbts_protocol)

##########################################################################
include_directories(gko-group/src)
include_directories(gko-group/proto)
include_directories(gko-group/thrift)

aux_source_directory(gko-group/src GROUP_SRC)
aux_source_directory(gko-group/proto GROUP_PROTO_SRC)
aux_source_directory(gko-group/thrift GROUP_THRIFT_SRC)
add_library(
        gko-group
        ${GROUP_SRC}
        ${GROUP_PROTO_SRC}
        ${GROUP_THRIFT_SRC}
)

##########################################################################
include_directories(gko-agent/include)
aux_source_directory(gko-agent/src AGENT_SRC)
add_executable(
        gko-agent
        ${AGENT_SRC}
)



