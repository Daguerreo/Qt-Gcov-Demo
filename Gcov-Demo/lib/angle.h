#ifndef ANGLE_H
#define ANGLE_H

#include "angle_util.h"

class Angle
{
public:
   enum Type{
      Deg,
      Rad

   };

   //! Default angle is 0.0 deg
   Angle();
   Angle(double value, Angle::Type type);

   static Angle Degree(double value);
   static Angle Radians(double value);

   double deg() const;
   double rad() const;

   bool isDeg() const;
   bool isRad() const;

   //! Normalize angle between [0,360) if degrees or [0,2PI) if radians.
   void normalize();

private:
   double _value;
   Type _type;
};

#endif // ANGLE_H
