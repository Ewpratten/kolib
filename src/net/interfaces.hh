#if !defined(_KOLIB_NET_INTERFACES_HH)
#define _KOLIB_NET_INTERFACES_HH

#include <string>

namespace kobo {
namespace net {

bool isInterfaceUp(std::string ifName);

}  // namespace net
}  // namespace kobo

#endif  // _KOLIB_NET_INTERFACES_HH
