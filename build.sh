#!/usr/bin/env bash

WORKSPACE=`pwd`
PROTOC=protoc
THRIFT=thrift



file_list=`find $WORKSPACE -name *.proto`
for file_item in $file_list
do
    echo $file_item
    file_dirname=`dirname $file_item`
    $PROTOC --cpp_out=$file_dirname --proto_path=$file_dirname --proto_path=third-party/protobuf/include $file_item
done


file_list=`find $WORKSPACE -name *.thrift`
for file_item in $file_list
do
    echo $file_item
    file_dirname=`dirname $file_item`
    $THRIFT -r --gen cpp -out $file_dirname -I $file_dirname $file_item
done



rm `find  $WORKSPACE -name *.skeleton.cpp`
