#include "koboconf.hh"

#include <fstream>
#include <iostream>

#include "util/fio.hh"

int findLineNumberOfKey(std::fstream& configFile, std::string& key) {
    // Seek to the start of the file
    configFile.clear();
    configFile.seekg(std::ios::beg);

    // Search through the file for the key
    std::string line;
    int lineNumber = 0;

    while (std::getline(configFile, line)) {
        // Try to match the line start to the key
        for (int i = 0; i < key.length(); i++) {
            // Break if there is a string mismatch
            if (i >= line.length() || line.at(i) != key.at(i)) {
                break;
            }

            // Return the line number if there is a match
            if (i >= key.length() - 1) {
                return lineNumber;
            }
        }
        lineNumber++;
    }

    return -1;
}

void kobo::conf::writeValue(std::string key, std::string value) {
    // Open the config file
    std::fstream configFile("/mnt/onboard/.kobo/Kobo/Kobo eReader.conf",
                            std::ios_base::in | std::ios_base::out);

    // Find the line number of the key
    int line = findLineNumberOfKey(configFile, key);

    // Handle an invalid key
    if (line == -1) {
        return;
    }
}

std::string kobo::conf::readValue(std::string key) {
    // Open the config file
    std::fstream configFile("/mnt/onboard/.kobo/Kobo/Kobo eReader.conf",
                            std::ios_base::in);

    // Find the line number of the key
    int line = findLineNumberOfKey(configFile, key);

    // Handle an invalid key
    if (line == -1) {
        return "";
    }

    // Seek to the line number of the key
    kobo::util::seekToLine(configFile, line);

    // Pull in the config line
    std::string configLine;
    configFile >> configLine;

    // Get the value
    return configLine.substr(key.length() + 1);
}