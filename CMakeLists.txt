cmake_minimum_required(VERSION 3.7)
project(gingko)

set(CMAKE_CXX_STANDARD 11)





set(SOURCE_FILES
        gko-agent/include/bbts/agent/Task.h
        gko-agent/include/bbts/agent/TaskDB.h
        gko-agent/include/bbts/agent/TaskManager.h
        gko-agent/include/bbts/plugin/hdfs.h
        gko-agent/include/bbts/plugin/hdfstool.h
        gko-agent/include/bbts/tool/BBTSClient.h
        gko-agent/include/bbts/tool/ClusterDownloader.h
        gko-agent/include/bbts/tool/Downloader.h
        gko-agent/include/bbts/BBTSTorrentPlugin.h
        gko-agent/include/bbts/BTInfo.hpp
        gko-agent/include/bbts/common_def.h
        gko-agent/proto/configure.pb.h
        gko-agent/include/bbts/ConsistentHashRing.hpp
        gko-agent/include/bbts/constant_def.h
        gko-agent/include/bbts/CUrl.h
        gko-agent/include/bbts/encode.h
        gko-agent/include/bbts/ErrorCategory.h
        gko-agent/include/bbts/host_info_util.h
        gko-agent/include/bbts/LazySingleton.hpp
        gko-agent/include/bbts/log.h
        gko-agent/proto/message.pb.h
        gko-agent/include/bbts/number_util.h
        gko-agent/include/bbts/path.h
        gko-agent/include/bbts/pb_conf.h
        gko-agent/include/bbts/RegexMatch.hpp
        gko-agent/include/bbts/socket_util.h
        gko-agent/include/bbts/SpeedLimit.h
        gko-agent/include/bbts/statistics.h
        gko-agent/include/bbts/string_util.h
        gko-agent/include/bbts/subnet_mask.h
        gko-agent/include/bbts/Syms.h
        gko-agent/include/bbts/ThriftTracker.h
        gko-agent/include/bbts/torrent_file_util.h
        gko-agent/proto/TrackerConf.pb.h
        gko-agent/include/bbts/TypeLock.hpp
        gko-agent/include/bbts/UnixSocketClient.h
        gko-agent/include/bbts/UnixSocketConnection.h
        gko-agent/include/bbts/UnixSocketServer.h
        gko-agent/include/bbts/util.h
        gko-agent/include/bbts/WExitCode.h
        gko-agent/include/bbts/WorkerPool.h
        gko-agent/plugin/hdfstool.cpp
        gko-agent/src/bbts_agent.cpp
        gko-agent/src/BBTSClient.cpp
        gko-agent/src/BBTSTorrentPlugin.cpp
        gko-agent/src/ClusterDownloader.cpp
        gko-agent/proto/configure.pb.cpp
        gko-agent/src/CUrl.cpp
        gko-agent/src/delete_files.cpp
        gko-agent/src/Downloader.cpp
        gko-agent/src/dump_torrent.cpp
        gko-agent/src/encode.cpp
        gko-agent/src/ErrorCategory.cpp
        gko-agent/src/file_is_locked.cpp
        gko-agent/src/gko3.cpp
        gko-agent/src/host_info_util.cpp
        gko-agent/src/log.cpp
        gko-agent/src/make_torrent.cpp
        gko-agent/proto/message.pb.cpp
        gko-agent/src/number_util.cpp
        gko-agent/src/path.cpp
        gko-agent/src/socket_util.cpp
        gko-agent/src/SpeedLimit.cpp
        gko-agent/src/string_util.cpp
        gko-agent/src/subnet_mask.cpp
        gko-agent/src/Syms.cpp
        gko-agent/src/Task.cpp
        gko-agent/src/TaskDB.cpp
        gko-agent/src/TaskManager.cpp
        gko-agent/src/ThriftTracker.cpp
        gko-agent/proto/TrackerConf.pb.cpp
        gko-agent/src/UnixSocketClient.cpp
        gko-agent/src/UnixSocketConnection.cpp
        gko-agent/src/UnixSocketServer.cpp
        gko-agent/src/util.cpp
        gko-agent/src/WorkerPool.cpp
        )

add_executable(gingko ${SOURCE_FILES})

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



