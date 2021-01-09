#include "interfaces.hh"

#include <sys/stat.h>
#include <sys/types.h>

bool kobo::net::isInterfaceUp(std::string ifName) {
    // Check if the directory exists
    struct stat info;
    std::string netBasePath = "/proc/sys/net/ipv4/conf/";

    return stat((netBasePath.append(ifName)).c_str(), &info) == 0 &&
           (info.st_mode & S_IFDIR);
}