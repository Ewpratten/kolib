#include "board.hh"

#include <algorithm>
#include <array>
#include <cstdio>

#include "../util/fio.hh"
#include <memory>
#include <stdexcept>

std::string kobo::hw::getDeviceCodename() {
    // Try to read codename from env
    std::string codenameFromEnv = std::getenv("PRODUCT");

    if (!codenameFromEnv.empty()) {
        return codenameFromEnv;
    }

    // Allocate a result buffer
    std::array<char, 128> buffer;
    std::string codename;

    // Open the kobo config process
    std::unique_ptr<FILE, decltype(&pclose)> pipe(
        popen("/bin/kobo_config.sh 2>/dev/null", "r"), pclose);

    // Handle failure to run proc
    if (!pipe) {
        throw std::runtime_error("Failed to execute kobo_config.sh");
    }

    // Fetch resulting string
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        codename += buffer.data();
    }

    // The codename might pull in a newline. Remove it
    codename.erase(std::remove(codename.begin(), codename.end(), '\n'),
                   codename.end());

    return codename;
}

std::string kobo::hw::getFirmwareVersion() {
    std::string fwInfo;

    try {
        fwInfo =
            kobo::util::readFromFile<std::string>("/mnt/onboard/.kobo/version");
    } catch (const std::exception& e) {
        return "none";
    }

    // Slice out the firmware data, and return
    int fwStartIndex;
    int fwEndIndex;
    int commasFound = 0;
    for (int i = 0; i < fwInfo.length(); i++) {
        // Look for commas
        if (fwInfo.at(i) == ',') {
            commasFound++;
        }

        // If the second comma has been found, add the next element as the fw
        // string start
        if (fwStartIndex == 0 && commasFound == 2) {
            fwStartIndex = i + 1;
        }

        // If the third comma has been found, mark it as the string end
        if (fwEndIndex == 0 && commasFound == 3) {
            fwEndIndex = i - fwStartIndex;
        }
    }

    return fwInfo.substr(fwStartIndex, fwEndIndex);

    // local version_file = io.open("/mnt/onboard/.kobo/version", "r")
    // if not version_file then
    //     self.firmware_rev = "none"
    // end
    // local version_str = version_file:read()
    // version_file:close()

    // local i = 0
    // for field in util.gsplit(version_str, ",", false, false) do
    //     i = i + 1
    //     if (i == 3) then
    //          self.firmware_rev = field
    //     end
    // end
}