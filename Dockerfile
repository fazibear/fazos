FROM gcc:9

ENV DEBIAN_FRONTEND=noninteractive

RUN dpkg --add-architecture i386
RUN apt-get update
RUN apt-get -yq install libc6-dev:i386 vim

RUN echo "PS1='🐳  \[\033[1;34m\]\w\[\033[0;35m\] \[\033[1;36m\]# \[\033[0m\]'" >> ~/.bashrc
