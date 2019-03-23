#!/bin/bash

LIB_NAME="googletest"
GTEST="gtest"
SERVER_PREFIX="https://github.com/google/googletest/archive"
RELEASE_NAME="release-1.8.1"
EXT=".zip"

mkdir $LIB_NAME
cd $LIB_NAME

echo "Fetching $RELEASE_NAME..."
wget -q "$SERVER_PREFIX/$RELEASE_NAME$EXT" $OUT_REDIR

echo "Unzipping,.."
unzip -q $RELEASE_NAME$EXT

mv "$LIB_NAME-$RELEASE_NAME/$LIB_NAME/include/$GTEST/" ./
rm -rf "$LIB_NAME-$RELEASE_NAME" $RELEASE_NAME$EXT
echo "Done."

