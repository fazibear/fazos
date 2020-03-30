#!/bin/bash 
DIR="/build"

docker run -v$HOME/vim:/root/.vim -v $PWD:$DIR -w$DIR -it kernel_build bash
