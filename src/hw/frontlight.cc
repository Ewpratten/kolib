#include "frontlight.hh"

#include "../koboconf.hh"

float kobo::hw::getFrontLightLevel() {
    // Fetch the config value
    std::string rawConfigValue = kobo::conf::readValue("FrontLightLevel");

    // Convert to a usable value
    return ((float)std::stoi(rawConfigValue)) / 100.f;
}

bool kobo::hw::getFrontLightEnabled() {
    // Fetch the config value
    std::string rawConfigValue = kobo::conf::readValue("FrontLightState");

    return rawConfigValue == "true";
}