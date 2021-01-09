# KoLib

KoLib is a modern c++ library to assist in development of software targeting [Kobo](https://www.kobo.com/) products.

## The Toolchain

Kobo devices are ARM devices (specifically `arm-kobo-linux-gnueabihf`, running *very old* Linux kernels). This requires a custom cross-compile toolchain. To simplify my setup, I have build a [docker container](./toolchain/Dockerfile) that contains everything needed to compile software for a Kobo. Almost all compile commands are run through the scripts located in `toolchain/`, which in turn spin up the docker image, mount the project, and execute whatever you specify.

### Deploying to a Kobo

Included in `toolcahin/` is a script called `kobodeploy`. This script requires [KoboSSH](https://github.com/Ewpratten/KoboSSH) to be installed on the targeted device, and the following services exposed from the device:

```text
21/tcp -> ftp
22/tcp -> ssh
```

Assuming this is true, you can easily deploy any file you want to the Kobo's deploy directory (`/mnt/onboard/deploy`) by running:

```sh
./toolchain/kobodeploy <kobo_ip> <file>
```

## Building KoLib

### Cloning

This repository uses submodules, and must be cloned with:

```sh
git clone --recursive https://github.com/Ewpratten/kolib.git
```

### Compiling

The KoLib toolcahin is built on docker, so docker must be installed on the development system. You'll also want to pull the toolchain image with:

```sh
docker pull ewpratten/kolib_toolchain:crosstools
```

Building KoLib is fairly simple. Just make sure you are in the project root, then run:

```sh
mkdir build
./toolchain/cmake
./toolchain/make
```
