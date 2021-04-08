FROM ubuntu:18.04
MAINTAINER Pritam Dash

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y git libtool-bin automake autoconf libexpat1-dev python-matplotlib python-serial python-wxgtk3.0 python-wxtools python-lxml python-scipy python-opencv ccache gawk git python-pip python-pexpect
RUN pip install future pymavlink MAVProxy

RUN git clone https://github.com/DependableSystemsLab/pid-piper.git  

EXPOSE 5762
