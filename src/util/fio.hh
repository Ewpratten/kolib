#if !defined(_KOLIB_UTIL_FIO_HH)
#define _KOLIB_UTIL_FIO_HH

#include <string>

namespace kobo {
namespace util {

template<typename T>
T readFromFile(std::string path);

}  // namespace util
}  // namespace kobo

#endif  // _KOLIB_UTIL_FIO_HH
