FROM debian:latest

# Get external deps
RUN apt-get update -y
RUN dpkg --add-architecture armhf
RUN apt-get update -y
RUN apt-get install crossbuild-essential-armhf cross-gcc-dev g++-arm-linux-gnueabihf gcc-arm-linux-gnueabihf nasm -y
RUN apt-get install build-essential gperf help2man bison texinfo flex gawk autoconf automake wget curl file libncurses-dev -y
RUN apt-get install git -y

# Pull in crosstool-ng
RUN git clone https://github.com/NiLuJe/crosstool-ng /crosstool_ng_sources

# Build crosstool-ng
WORKDIR /crosstool_ng_sources
RUN ./bootstrap
RUN ./configure
RUN make
RUN make install

# Set up a temp dir to configure crosstool in 
RUN mkdir -p /crosstool_cfg
WORKDIR /crosstool_cfg
RUN mkdir -p /home/crosstooluser/src
RUN ct-ng arm-kobo-linux-gnueabihf

# Set up a temp user for crosstool to use
# RUN adduser crosstooluser
# RUN chown crosstooluser:crosstooluser /crosstool_cfg
# RUN chown crosstooluser:crosstooluser /home/crosstooluser
# RUN chown crosstooluser:crosstooluser /home/crosstooluser/src
# USER crosstooluser
# RUN cat .config
RUN echo "CT_EXPERIMENTAL=y\n" >> .config
RUN echo "CT_ALLOW_BUILD_AS_ROOT=y\n" >> .config
RUN echo "CT_ALLOW_BUILD_AS_ROOT_SURE=y\n" >> .config
RUN mkdir -p /root/src
RUN ct-ng build
# USER root

# Load rawdraw deps
RUN apt-get install xorg-dev libx11-dev libxinerama-dev libxext-dev mesa-common-dev libglu1-mesa-dev -y
RUN apt-get install cmake -y
RUN apt-get install libx11-dev -y


# Pull in local files. Mainly to build the rest of the deps.
# RUN mkdir -p /kolib_sources
# WORKDIR /kolib_sources
# COPY . /kolib_sources

# # Build crosstool
# WORKDIR /kolib_sources/external/crosstool-ng
# RUN ./bootstrap
# RUN ./configure
# RUN make
# RUN make install

# # Fetch the XCC toolchian for kobo
# WORKDIR /kolib_sources
# RUN ./external/crosstool-ng/bin/bin/ct-ng arm-kobo-linux-gnueabihf
# RUN ./external/crosstool-ng/bin/bin/ct-ng build