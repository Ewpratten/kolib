#if !defined(_KOLIB_UTIL_MACROS_HH)
#define _KOLIB_UTIL_MACROS_HH

#include "../util/fio.hh"

// A really quick way to define an inline function that can read and return a
// file's contents
#define DEF_FILE_FETCH_MACRO(type, name, path) \
    inline type name() { return kobo::util::readFromFile<type>(path); }

#endif  // _KOLIB_UTIL_MACROS_HH
