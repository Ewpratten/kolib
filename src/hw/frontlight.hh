#if !defined(_KOLIB_HW_FRONTLIGHT_HH)
#define _KOLIB_HW_FRONTLIGHT_HH

namespace kobo {
namespace hw {

// void setFrontLightLevel(float percent);
float getFrontLightLevel();

// void setFrontLightEnabled(bool enabled);
bool getFrontLightEnabled();

}  // namespace hw
}  // namespace kobo

#endif  // _KOLIB_HW_FRONTLIGHT_HH
