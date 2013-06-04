#!/bin/sh

# Ubuntu
# sudo apt-get install cmake openexr

# Mac OS X
brew install cmake openexr

mkdir build
cd build
cmake .. && make install
