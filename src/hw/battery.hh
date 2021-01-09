#if !defined(_KOLIB_HW_BATTERY_HH)
#define _KOLIB_HW_BATTERY_HH

#include <string>

#include "../util/macros.hh"

namespace kobo {
namespace hw {

DEF_FILE_FETCH_MACRO(
    int, getBatteryCapacity,
    "/sys/devices/platform/pmic_battery.1/power_supply/mc13892_bat/capacity")
DEF_FILE_FETCH_MACRO(
    long, getBatteryCurrent,
    "/sys/devices/platform/pmic_battery.1/power_supply/mc13892_bat/current_now")
DEF_FILE_FETCH_MACRO(
    int, getBatteryVoltage,
    "/sys/devices/platform/pmic_battery.1/power_supply/mc13892_bat/voltage_now")
DEF_FILE_FETCH_MACRO(
    long, getBatteryCharge,
    "/sys/devices/platform/pmic_battery.1/power_supply/mc13892_bat/charge_now")
DEF_FILE_FETCH_MACRO(
    std::string, getBatteryStatusString,
    "/sys/devices/platform/pmic_battery.1/power_supply/mc13892_bat/status")
DEF_FILE_FETCH_MACRO(int, getChargerStatusCode,
                     "/sys/class/power_supply/mc13892_charger/online")
DEF_FILE_FETCH_MACRO(std::string, getChargerType,
                     "/sys/class/power_supply/mc13892_charger/type")

inline bool isBatteryCharging() {
    return getBatteryStatusString() == "Charging";
}

inline bool isChargerOnline() { return getChargerStatusCode() > 0; }

}  // namespace hw
}  // namespace kobo

#endif  // _KOLIB_HW_BATTERY_HH
