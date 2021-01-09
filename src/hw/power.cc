#include "power.hh"

#include <fstream>
#include <iostream>

int kobo::hw::getWakeupCount() {
    // Fetch the system file
    std::fstream infoFile("/sys/devices/platform/power/wakeup",
                          std::ios_base::in);

    // Parse out the value
    long count;
    infoFile >> count;

    return count;
}