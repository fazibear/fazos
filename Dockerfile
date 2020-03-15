FROM gcc:9

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update
RUN apt-get -yq install nasm vim
