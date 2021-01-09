#if !defined(_KOLIB_HW_BOARD_HH)
#define _KOLIB_HW_BOARD_HH

#include <string>

namespace kobo {
namespace hw {

std::string getDeviceCodename();

std::string getFirmwareVersion();

}  // namespace hw
}  // namespace kobo

#endif  // _KOLIB_HW_BOARD_HH
