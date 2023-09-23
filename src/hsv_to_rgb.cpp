#include "hsv_to_rgb.h"

#include <algorithm>
#include <vector>

// Convert a color represented by hue, saturation and value to its
// representation using red, green and blue intensities.
//
// Inputs:
//   h  hue in degrees [0,360)
//   s  saturation intensity [0,1]
//   v  value intensity [0,1]
// Outupts:
//   r  red intensity [0,1]
//   g  green intensity [0,1]
//   b  blue intensity [0,1]

void hsv_to_rgb(
  const double h,
  const double s,
  const double v,
  double & r,
  double & g,
  double & b)
{
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:
  //first, we will make sure that h is within the value specified as, [0, 360) 
  //to do this, we need to create new values for h s and v because they are passed through function as constants that we can't alter. So, we will make local copies to this function.
  double hue, sat, val; int section; double position;
  if (h>=360){
    hue=h-360.0; //subtract 360
  }else if(h<0){
    hue=h+360.0; //add 360 to find equivalent positive hue degree value
  }else{
    //if h is in the range
    hue=h;
  }

  //do the same for s and v
  sat = std::min(1.0, std::max(s, 0.0)); //clamps value to 0 if s<0 and to 1 if s>1
  val = std::min(1.0, std::max(v, 0.0)); //same as above but for v

  //calculate ratios of primary colours, r g and b, given value of h
  //going to use a switch-case statement, depending on which section of the colorwheel h represents, from sections 0-5
  section = int(hue/60.0);

  //position => variable that calculates the fractional position of the hue WITHIN the specific section it's in (useful for calculating the shades in terms of the primary colours, r g and b)
  position = (hue-(section*60.0))/60.0;

  //start the switch case to define r g and b depending on the section and position in the section
  switch(section){
    case (0):
      //red to yellow section
      r = 1.0 * sat * val;
      g = position * sat * val;
      b = 0.0;
      break;
    case (1):
      //yellow to green section
      r = (1.0 - position) * sat * val;
      g = 1.0 * sat * val;
      b = 0.0;
      break;
    case(2):
      //green to cyan
      r = 0.0;
      g = 1.0 * sat * val;
      b = position * sat * val;
      break;
    case(3):
      //cyan to blue
      r = 0.0;
      g = (1.0-position) * sat * val;
      b = 1.0 * sat * val;
      break;
    case(4):
      //blue to magenta
      r = position * sat * val;
      g = 0.0;
      b = 1.0 * sat * val;
      break;
    case(5):
      //magenta to red
      r = 1.0 * sat * val;
      g = 0.0;
      b = (1.0-position) * sat * val;
      break;
    default:
      //most likely we won't go through this, but this is in case there was an issue in the code
      r = 0.0;
      g = 0.0;
      b=0.0;
  }

  //function done

  ////////////////////////////////////////////////////////////////////////////
}
