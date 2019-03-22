#!/bin/bash

LIB_NAME="googletest"
SERVER_PREFIX="https://github.com/google/googletest/archive"
RELEASE_NAME="release-1.8.1"
EXT=".zip"

mkdir $LIB_NAME
cd $LIB_NAME
wget "$SERVER_PREFIX/$RELEASE_NAME$EXT"
unzip $RELEASE_NAME$EXT
echo $PWD
mv "./$LIB_NAME-$RELEASE_NAME/$LIB_NAME/include/gtest/*" "../$LIB_NAME"
rm -rf "$LIB_NAME-$RELEASE_NAME" $RELEASE_NAME

