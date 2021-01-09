---
---

# Welcome to the KoLib documentation!

This documentation set contains documentation for [KoLib](https://github.com/Ewpratten/kolib) and general Kobo hacking/software modification.

## You can hack a Kobo?

*Yes*. Like pretty much anything you can interact with these days, Kobo e-readers are actually just low-power Linux devices. In this specific case, Kobos run an ancient (see: `2.6.35`) Linux kernel based on [BusyBox](https://www.busybox.net/). Interestingly, every Kobo I have encountered uses the same CPU architecture and OS. This allows for fairly simple software distribution across the entire fleet of Kobo e-readers. This means that as long as your compiler targets 32-bit `armv7l`, you should be able to write software for a Kobo.

## What's KoLib?

KoLib is a C++ software library I maintain that exposes a simple API for interacting with Kobo system settings and hardware. In it's current state, KoLib is fairly simple, but I plan to extend it's functionalities over time. [Pull requests](https://github.com/Ewpratten/kolib/pulls) on GitHub are always welcome to speed up this process. KoLib is licensed under GPLv3. The planned features include:

 - Lighting control
 - Hardware status information
 - Simple GUI tools

