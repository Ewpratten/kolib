---
sort: 2
---

# Telnet & FTP access

With our custom firmware update package almost finished, we can add the configuration required to expose Telnet and FTP servers from the device (Telnet is only required to bootstrap SSH). Create a file at `/opt/inetd.conf`, and fill it with the following:

```sh
# <service_name> <sock_type> <proto> <flags> <user> <server_path> <args>
# ftp	stream	tcp	nowait	root	/usr/sbin/tcpd		in.ftpd
# telnet	stream	tcp	nowait	root	/usr/sbin/telnetd	telnetd -l /bin/login
21 stream  tcp     nowait  root    /bin/busybox ftpd -w -S  /
23 stream tcp nowait root /bin/busybox telnetd -i

```

This tells the network manager to start up and expose an `ftpd` and `telnetd` process when the Kobo boots.

## Deploying the custom firmware

We can now build our `KoboRoot.tgz` file by running:

```sh
tar czf KoboRoot.tgz opt/inetd.conf opt/afterinit.sh etc/inittab
```

Plug in your Kobo, drop `KoboRoot.tgz` into `.kobo/` on the device, eject, unplug, and let the Kobo reboot.

## Enabling persistent networking

Kobo's generally only turn on Wifi when you are in the web browser or book store. To keep the connection up whenever the device is turned on, we will need to put the Kobo into "developer mode". Simply open the book search bar on the main page, "search" for `devmodeon`, and press "Go".

This enables an extra menu in `More > Settings > Device information` called "Developer options" (at the bottom of the last page). Open this and enable "Force Wifi ON".

## Connecting to the Kobo

To get temporary root access from your computer, run:

```sh
telnet <kobo_ip>
```

and log in as `root` (no password).
