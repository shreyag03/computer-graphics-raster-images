#include "rgb_to_hsv.h"
#include <vector>
#include <algorithm>

void rgb_to_hsv(
  const double r,
  const double g,
  const double b,
  double & h,
  double & s,
  double & v)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  
  //   r  red intensity [0,1]
  double red = std::max(0.0, std::min(r, 1.0));
  //   g  green intensity [0,1]
  double green = std::max(0.0, std::min(g, 1.0));
  //   b  blue intensity [0,1]
  double blue = std::max(0.0, std::min(b, 1.0));
  
  h = 0;
  s = 0;
  v = 0;
  ////////////////////////////////////////////////////////////////////////////
}
