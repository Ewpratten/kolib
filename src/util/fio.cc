#include "fio.hh"

#include <fstream>
#include <iostream>
#include <limits>
#include <stdexcept>

std::fstream& kobo::util::seekToLine(std::fstream& file, u_int number) {
    file.clear();
    file.seekg(std::ios::beg);
    for (int i = 0; i < number - 1; ++i) {
        file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return file;
}
