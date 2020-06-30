#include "angle.h"

Angle::Angle()
   : _value{0.0}, _type{Deg}
{
}

Angle::Angle(double value, Angle::Type type)
   : _value{value}, _type{type}
{
}

Angle Angle::Degree(double value)
{
   return Angle(value, Deg);
}

Angle Angle::Radians(double value)
{
   return Angle(value, Rad);
}

double Angle::deg() const
{
   if(_type == Deg){
      return _value;
   }

   return radToDeg(_value);
}

double Angle::rad() const
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

void Angle::normalize()
{
   if(isDeg()){
      _value = degNormalize(_value);
      return;
   }

   _value = radNormalize(_value);
}
