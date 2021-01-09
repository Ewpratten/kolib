#if !defined(_KOLIB_KOBOCONF_HH)
#define _KOLIB_KOBOCONF_HH

#include <string>

namespace kobo {
namespace conf {

void writeValue(std::string key, std::string value);
std::string readValue(std::string key);

}  // namespace conf
}  // namespace kobo

#endif  // _KOLIB_KOBOCONF_HH
