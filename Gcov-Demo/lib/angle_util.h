#ifndef ANGLE_UTIL_H
#define ANGLE_UTIL_H

#include <cmath>

static constexpr double degToRad(double deg) { return deg * M_PI / 180.0; }
static constexpr double radToDeg(double rad) { return rad * 180.0 / M_PI; }

inline static double degNormalize(double deg)
{
   return std::fmod(std::fmod(deg, 360.0) + 360.0, 360.0);
}

inline static double radNormalize(double rad)
{
   return std::fmod(std::fmod(rad, 2.0*M_PI) + 2.0*M_PI, 2.0*M_PI);
}

#endif // ANGLE_UTIL_H
