#!/usr/bin/env bash

workspace=$( cd $(dirname $0) && pwd)
cd ${workspace}

[ -d torrent_build ] && rm -rf torrent_build


mkdir torrent_build
cd torrent_build

../libtorrent-rasterbar/configure \
  --prefix=${workspace}/third-party/torrent \
  --with-boost=${workspace}/third-party/boost \
  --with-openssl=/opt/compiler/gcc-4.8.2 \
  --enable-debug=no \
  --disable-dht \
  --disable-geoip \
  --disable-deprecated-functions \
  --enable-examples=no \
  --disable-encryption \
  --enable-tests=no \
  --enable-static=yes \
  --enable-shared=no \


make -j8














