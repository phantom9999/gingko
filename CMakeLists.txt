cmake_minimum_required(VERSION 2.8)
project(gingko)

set(CMAKE_CXX_STANDARD 11)

########################################################################
# 设置依赖
set(CMAKE_CXX_FLAGS "-g -fPIC -Wall -pipe -w -fpermissive -Wno-deprecated -Wno-unused-function -Wno-unused-parameter -Wno-invalid-offsetof -Winline -Wpointer-arith -Wwrite-strings -Woverloaded-virtual -ftemplate-depth-128 -Wreorder -Wswitch -Wformat")

set(
        third
        /third-party/boost
        /third-party/gflags
        /third-party/glog
        /third-party/hiredis
        /third-party/json-cpp
#        /third-party/libcurl
        /third-party/libevent
        /third-party/protobuf
        /third-party/thrift
        /third-party/log4cpp
        /third-party/gtest
        /third-party/torrent
)
add_definitions(
        -DBOOST_ASIO_SEPARATE_COMPILATION
        -DHAVE_NETINET_IN_H
#        -DBOOST_ASIO_HEADER_ONLY
)

include_directories(libtorrent-rasterbar/include)
include_directories(libtorrent-rasterbar/include/libtorrent)

foreach (item ${third})
    set(include_dir "${include_dir}:${PROJECT_SOURCE_DIR}${item}/include")
    set(lib_dir "${lib_dir}:${PROJECT_SOURCE_DIR}${item}/lib")
    include_directories(${PROJECT_SOURCE_DIR}${item}/include)
    link_directories(${PROJECT_SOURCE_DIR}${item}/lib)
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
        -Xlinker "-("
        minihttpd
        gtest
        gtest_main
        glog
        event
        pthread
        -Xlinker "-)"
)

add_executable(
        eventloop_test
        minihttpd/sample/eventloop_test.cpp
)
target_link_libraries(
        eventloop_test
        minihttpd
        glog
        event
        pthread
)

add_executable(
        httpd_test
        minihttpd/sample/httpd_test.cpp
)
target_link_libraries(
        httpd_test
        minihttpd
        glog
        event
        pthread
)

add_executable(
        timer_in_mt_test
        minihttpd/sample/timer_in_mt_test.cpp
)
target_link_libraries(
        timer_in_mt_test
        minihttpd
        glog
        event
        pthread
)

add_executable(
        timer_test
        minihttpd/sample/timer_test.cpp
)
target_link_libraries(
        timer_test
        minihttpd
        glog
        event
        pthread
)

########################################################################
include_directories(bbts_protocol)
aux_source_directory(bbts_protocol BBTS_PROTOCOL)
add_library(
        bbts_protocol
        ${BBTS_PROTOCOL}
)


########################################################################
###########gko-tracker########
include_directories(
        gko-tracker/include
)

aux_source_directory(gko-tracker/src TRACKER_SRC)
add_executable(
        gko-tracker
        ${TRACKER_SRC}
)

target_link_libraries(
        gko-tracker
        -Xlinker "-("
        pthread
        glog
        thrift
        thriftnb
        protobuf
        hiredis
        boost_thread
        boost_system
        gflags
        event
        bbts_protocol
        minihttpd
        ssl
        crypto
        -Xlinker "-)"


)



ADD_EXECUTABLE(client_mock_infohash gko-tracker/clientmock/client_mock_infohash.cpp)
TARGET_LINK_LIBRARIES(client_mock_infohash bbts_protocol thrift boost_system)

ADD_EXECUTABLE(client_mock gko-tracker/clientmock/client_mock.cpp)
TARGET_LINK_LIBRARIES(client_mock bbts_protocol pthread thrift boost_system boost_thread)

ADD_EXECUTABLE(client_mock_s gko-tracker/clientmock/client_mock_s.cpp)
TARGET_LINK_LIBRARIES(client_mock_s bbts_protocol pthread thrift boost_system boost_thread)

ADD_EXECUTABLE(ControlByInfohash gko-tracker/clientmock/ControlByInfohash.cpp)
TARGET_LINK_LIBRARIES(ControlByInfohash bbts_protocol thrift boost_system boost_thread)

##########################################################################
include_directories(gko-group)
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
############ gko-agent ##########
include_directories(gko-agent/include)
include_directories(gko-agent/proto)
aux_source_directory(gko-agent/src AGENT_SRC)
aux_source_directory(gko-agent/proto AGENT_PROTO_SRC)
add_executable(
        gko-agent
        ${AGENT_SRC}
        ${AGENT_PROTO_SRC}
)
target_link_libraries(
        gko-agent
        -Xlinker "-("
        log4cpp
        thrift
        boost_system
        boost_thread
        boost_regex
        torrent-rasterbar
        sqlite3
        dl
        pthread
        curl
        gko-group
        bbts_protocol
        ssl
        protobuf
        crypto
        -Xlinker "-)"

)



