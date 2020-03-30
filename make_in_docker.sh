#!/bin/bash 
DIR="/build"

docker run -v $PWD:$DIR -w$DIR -it kernel_build make $1
