#include "angle.h"

Angle::Angle()
   : _value{0.0}, _type{Deg}
{
}

Angle::Angle(float value, Angle::Type type)
   : _value{value}, _type{type}
{
}

float Angle::deg() const
{
   if(_type == Deg){
      return _value;
   }

   return radToDeg(_value);
}

float Angle::rad() const
{
   if(_type == Rad){
      return _value;
   }

   return degToRad(_value);
}

bool Angle::isDeg() const
{
   return _type == Deg;
}

bool Angle::isRad() const
{
   return _type == Rad;
}

QDebug operator<<(QDebug dbg, const Angle& a)
{
   return dbg << "Angle(" << a._value << (a.isDeg() ? "deg" : "rad") << ")";
}
