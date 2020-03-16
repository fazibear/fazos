#!/bin/bash 
DIR="/src"

docker run -v $PWD:$DIR -w$DIR -it kernel_build ./build.sh $1
