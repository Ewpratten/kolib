#if !defined(_KOLIB_UTIL_FIO_HH)
#define _KOLIB_UTIL_FIO_HH

#include <string>
#include <fstream>
#include <iostream>

namespace kobo {
namespace util {

template <typename T>
T readFromFile(std::string path) {
    // Fetch the file
    std::fstream file(path, std::ios_base::in);

    // If there is an issue with the file, throw an exception
    if (!file.good()) {
        throw std::runtime_error("Failed to open file: " + path);
    }

    // Get file contents
    T result;
    file >> result;

    return result;
}

std::fstream& seekToLine(std::fstream& file, u_int number);

}  // namespace util
}  // namespace kobo

#endif  // _KOLIB_UTIL_FIO_HH
