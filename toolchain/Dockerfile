FROM debian:latest

# Get external deps
RUN apt-get update -y
RUN dpkg --add-architecture armhf
RUN apt-get update -y
RUN apt-get install crossbuild-essential-armhf cross-gcc-dev g++-arm-linux-gnueabihf gcc-arm-linux-gnueabihf nasm -y
RUN apt-get install build-essential gperf help2man bison texinfo flex gawk autoconf automake wget curl file libncurses-dev -y

# Pull in local files. Mainly to build the rest of the deps.
RUN mkdir -p /kolib_sources
WORKDIR /kolib_sources
COPY . /kolib_sources

# Build crosstool
WORKDIR /kolib_sources/external/crosstool-ng
RUN ./bootstrap
RUN ./configure
RUN make
RUN make install

# Fetch the XCC toolchian for kobo
WORKDIR /kolib_sources
RUN ./external/crosstool-ng/bin/bin/ct-ng arm-kobo-linux-gnueabihf
RUN ./external/crosstool-ng/bin/bin/ct-ng build