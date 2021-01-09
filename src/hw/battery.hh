#if !defined(_KOLIB_HW_BATTERY_HH)
#define _KOLIB_HW_BATTERY_HH

#include <string>

#include "../util/macros.hh"

namespace kobo {
namespace hw {

DEF_FILE_FETCH_MACRO(int, getBatteryCapacity, "/sys/devices/platform/pmic_battery.1/power_supply/mc13892_bat/capacity")
DEF_FILE_FETCH_MACRO(long, getBatteryCurrent, "/sys/devices/platform/pmic_battery.1/power_supply/mc13892_bat/current_now")
DEF_FILE_FETCH_MACRO(int, getBatteryVoltage, "/sys/devices/platform/pmic_battery.1/power_supply/mc13892_bat/voltage_now")
DEF_FILE_FETCH_MACRO(long, getBatteryCharge, "/sys/devices/platform/pmic_battery.1/power_supply/mc13892_bat/charge_now")
DEF_FILE_FETCH_MACRO(std::string, getBatteryStatusString, "/sys/devices/platform/pmic_battery.1/power_supply/mc13892_bat/status")

inline bool isBatteryCharging(){
    return getBatteryStatusString() == "Charging";
}

}  // namespace hw
}  // namespace kobo

#endif  // _KOLIB_HW_BATTERY_HH
