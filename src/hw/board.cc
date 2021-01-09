#include "board.hh"

#include <algorithm>
#include <array>
#include <cstdio>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <vector>

#include "../util/fio.hh"

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
        popen("sh -c '/bin/kobo_config.sh 2>/dev/null'", "r"), pclose);

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
    std::vector<std::string> splitFwInfo;
    std::stringstream fwInfoStream(fwInfo);

    while(fwInfoStream.good()){

        // Get the next section of data between commas
        std::string substr;
        std::getline(fwInfoStream, substr, ',');
        splitFwInfo.push_back(substr);
    }

    // The third element is the firmware version
    return splitFwInfo[2];
}