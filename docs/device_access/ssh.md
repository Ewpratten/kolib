---
sort: 3
---

# SSH

Once connected to the Kobo, and logged in as `root`, we will need to install `dropbear` as an SSH server. I maintain a project called [KoboSSH](https://github.com/Ewpratten/KoboSSH) that produces pre-compiled `dropbear` binaries for Kobos. If you would like to build `dropbear` yourself, read [the instructions](https://github.com/Ewpratten/KoboSSH#compiling-locally). For the sake of simplicity, we will use a pre-built binary in this tutorial. Simply run the following commands to install `dropbear`:

```sh
mkdir -p /mnt/onboard/opt/dropbear
cd /mnt/onboard/opt/dropbear
wget https://github.com/Ewpratten/KoboSSH/releases/download/2020.81/dropbearmulti
chmod +x dropbearmulti
```

now, generate SSH keys for the Kobo with:

```sh
./dropbearmulti dropbearkey -t dss -f dss_key
./dropbearmulti dropbearkey -t rsa -f rsa_key
./dropbearmulti dropbearkey -t ecdsa -f ecdsa_key
```

## Switching from Telnet to SSH

**This step requires you to be familiar with using VI or VIM**

Remember the `/opt/inetd.conf` file we deployed to the Kobo? It is now on the filesystem, and can be edited from the command line (`vi /opt/inetd.conf`). Delete the last line of the file, and replace it with:

```sh
22 stream tcp nowait root /mnt/onboard/opt/dropbear/dropbearmulti dropbear -i -r /mnt/onboard/opt/dropbear/dss_key -r /mnt/onboard/opt/dropbear/rsa_key -r /mnt/onboard/opt/dropbear/ecdsa_key -B
```

Save the file, and reboot. You can now log in to the Kobo with:

```sh
ssh root@<kobo_ip>
```
