#ifndef ANGLE_H
#define ANGLE_H

#include <cmath>

#include <QDebug>

static constexpr float degToRad(float deg) { return deg * M_PI / 180.0; }
static constexpr float radToDeg(float rad) { return rad * 180.0 / M_PI; }

class Angle
{
public:
   enum Type{
      Deg,
      Rad

   };

   //! Default angle is 0.0 deg
   Angle();
   Angle(float value, Angle::Type type);

   float deg() const;
   float rad() const;

   bool isDeg() const;
   bool isRad() const;

private:
   friend QDebug operator<<(QDebug dbg, const Angle& a);

   float _value;
   Type _type;
};

QDebug operator<<(QDebug dbg, const Angle& a);

#endif // ANGLE_H
