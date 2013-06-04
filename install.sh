#!/bin/sh

# Ubuntu
# sudo apt-get install cmake libopenexr-dev

# Mac OS X
# brew install cmake openexr

rm -rf build
mkdir build
cd build
cmake .. && make install
