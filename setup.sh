#!/bin/bash

git clone -b 'v0.2.14-p0' --single-branch --depth 1 https://github.com/Dobiasd/FunctionalPlus
cd FunctionalPlus
mkdir -p build && cd build
cmake ..
make && sudo make install
cd ../..

git clone -b '3.3.9' --single-branch --depth 1 https://gitlab.com/libeigen/eigen.git
cd eigen
mkdir -p build && cd build
cmake ..
make && sudo make install
sudo ln -s /usr/local/include/eigen3/Eigen /usr/local/include/Eigen
cd ../..

git clone -b 'v3.9.1' --single-branch --depth 1 https://github.com/nlohmann/json
cd json
mkdir -p build && cd build
cmake -DBUILD_TESTING=OFF ..
make && sudo make install
cd ../..

git clone https://github.com/Dobiasd/frugally-deep
cd frugally-deep
mkdir -p build && cd build
cmake ..
make && sudo make install
cd ../..
