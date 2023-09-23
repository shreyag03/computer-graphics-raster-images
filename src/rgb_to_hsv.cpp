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

  //find max/min between input red/green/blue values
  double minrgb = std::min(red, green, blue);
  double maxrgb = std::max(red, green, blue);

  //the above is also used to calculate v value
  v = maxrgb;

  //use above to calculate saturation
  if (maxrgb!=0 && maxrgb!=minrgb){
    //if !=0 then there is saturation
    s = (maxrgb-minrgb)/maxrgb; //formula to calculate saturation
    //depending on if r g or b contributed to the maxrgb val, we decide h
    if (maxrgb == red){
      //red is max value
      //red is the starting pointm where hue represents angle around the wheel
      //starting at 0 degrees makes red the starting point
      //balance between green and blue
      h = 60*(0 + (green-blue)/(maxrgb-minrgb));
    }else if (maxrgb==green){
      //green is maximum value
      //located 120 degrees on color wheel, which is 2/3 of the way around the wheel
      //add 2 to the hue to adjust it to the green position
      //balance between blue and red
      h = 60*(2 + (blue-red)/(maxrgb-minrgb));
    }else{
      //blue is max value
      //located 240 degrees on color wheel, 2/3 of the way around THE OTHER WAY from red on the wheel
      //add 4 to the hue to adjust it to the blue positiohn
      //balance between red and green
      h = 60*(4+(red-green)/(maxrgb-minrgb));
    }
    //before we finalize the h value, we have to make sure we account for a -ve h value, by adding 360 to it to get the positive equivalent of the number
    if (h<0){
      h+=360;
    }
  }else{
    s=0; //no saturation for black
    h=0; //if no saturation, then hue is set to 0 (red)
  }

  //function done
  
  ////////////////////////////////////////////////////////////////////////////
}
