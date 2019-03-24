#!/bin/bash

# How to build Googletest - http://www.deanbodenham.com/learn/cpp-googletest.html

LIB_NAME="googletest"
SERVER_PREFIX="https://github.com/google/googletest/archive"
RELEASE_NAME="release-1.8.1"
EXT=".zip"

mkdir $LIB_NAME
cd $LIB_NAME

echo "Fetching $RELEASE_NAME..."
wget -q "$SERVER_PREFIX/$RELEASE_NAME$EXT" $OUT_REDIR

echo "Unzipping,.."
unzip -q $RELEASE_NAME$EXT

mv "$LIB_NAME-$RELEASE_NAME/$LIB_NAME/" ./
rm -rf "$LIB_NAME-$RELEASE_NAME" $RELEASE_NAME$EXT

echo "Building Googletest..."
cd $LIB_NAME
g++ -isystem ${PWD}/include -I${PWD} -pthread -c ${PWD}/src/gtest-all.cc 
ar -rv libgtest.a gtest-all.o

# ls *.a -> should return libgtest.a
cd ./make
make

echo "Done."

