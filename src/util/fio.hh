#if !defined(_KOLIB_UTIL_FIO_HH)
#define _KOLIB_UTIL_FIO_HH

#include <string>
#include <fstream>

namespace kobo {
namespace util {

template<typename T>
T readFromFile(std::string path);

std::fstream& seekToLine(std::fstream& file, u_int number);

}  // namespace util
}  // namespace kobo

#endif  // _KOLIB_UTIL_FIO_HH
