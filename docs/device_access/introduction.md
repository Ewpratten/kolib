---
sort: 1
---

# Introduction

**There is always a chance that you can brick your device following these tutorials. Follow at your own risk**

Kobo devices have a firmware update mechanism that can be easily exploited. This exploit is the basis of all Kobo modifications, and is fairly simple to execute.

When a Kobo boots, it performs a quick check for a file called `KoboRoot.tgz` located in `/mnt/onboard/.kobo` on the device. Any contents of this archive will directly be extracted into the device's root. This is how "sync updates" are performed. Luckily for us, this file is never signed, and `/mnt/onboard` is the directory that is exposed when plugging a Kobo into a computer with a USB cable. Until we have remote access to the device, all system modifications are performed by dropping custom update files onto the device, then rebooting.

For the following steps, you'll want to create an empty directory somewhere on your computer, and treat is as the system root (the same as `/`). We will compress it later, and deploy it to the Kobo.

## Injecting custom startup code

We want to have control over what happens when the Kobo is booted. To do this, we need to add code to the system init process. Create a file in your local system root directory at `/etc/inittab`, and add the following to it:

```sh
# This is run first except when booting in single-user mode.

# The following lines are default Kobo system init setup
::sysinit:/etc/init.d/rcS
::respawn:/sbin/getty -L ttymxc0 115200 vt100
::ctrlaltdel:/sbin/reboot
::shutdown:/bin/umount -a -r
::restart:/sbin/init

# Run custom code after init
::sysinit:/bin/sh /opt/afterinit.sh
::respawn:/usr/sbin/inetd -f /opt/inetd.conf
```

The last line is going to run our init script. Speaking of which, you'll want to create this script at `/opt/afterinit.sh`, and fill it with the following:

```sh
mkdir -p /dev/pts
mount -t devpts devpts /dev/pts
```

This will enable pseudoterminals on the Kobo (a requirement for Telnet).