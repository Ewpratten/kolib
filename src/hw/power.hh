#if !defined(_KOLIB_HW_POWER_HH)
#define _KOLIB_HW_POWER_HH

#include "../util/macros.hh"

namespace kobo {
namespace hw {

// Get the number of times this device has been woken up
// inline int getWakeupCount() {
//     return kobo::util::readFromFile<long>("/sys/devices/platform/power/wakeup");
// }

DEF_FILE_FETCH_MACRO(long, getWakeupCount, "/sys/devices/platform/power/wakeup")

}  // namespace hw
}  // namespace kobo

#endif  // _KOLIB_HW_POWER_HH
