// Shift the hue of a color rgb image.
//
// Inputs:
//   rgb  width*height*3 array containing rgb image color intensities
//   width  image width (i.e., number of columns)
//   height  image height (i.e., number of rows)
//   shift  hue shift given in degrees [-180,180)
// Outputs
//   shifted  width*height*3 array containing rgb image color intensities

#include "hue_shift.h"
#include "hsv_to_rgb.h"
#include "rgb_to_hsv.h"

#include <vector>
#include <algorithm>

void hue_shift(
  const std::vector<unsigned char> & rgb,
  const int width,
  const int height,
  const double shift,
  std::vector<unsigned char> & shifted)
{
  shifted.resize(rgb.size());
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here

  //first, we are going to check that the inputs are in range. Then, we are going to define the hue shift value to be [0, 360) due to the functions we want to use
  //due to us changing shift value due to possible values outside of range, we will use another variable to keep track of that
  double hueshift;
  if (shift<-180){
    hueshift = (shift + 360.0) + 180;
  }else if(shift>=180){
    hueshift = (shift - 360) + 180;
  }else{
    hueshift = shift + 180; //otherwise just have it store the shift value, as it means it contains a value in the correct range. then we just add the 180 to have it in range [0, 360)
  }

  //now, we are going to extract the values of r g and b channels for each pixel
    //following steps will be carried out with the help of the variables defined in the next line
    int pixel_ind; double red, green, blue, hue, sat, val;
    //1. loop through rgb image for each pixel
    //2. extract r g and b channels
    //3. convert the r g and b channels into hsv
    //4. apply the hue shift to hue value returned by rgb_to_hsv function. ensure the remaining hue remains within 0 and 360
    //5. convert h s and v channels into rgb
    //6. store the hue shifted rgb values into the shifted vector

    //step 1
    for (int row=0; row<height; row++){
      for (int col=0; col<width; col++){
        //step 2
        pixel_ind = row*width + col;
        red = static_cast<double>(rgb[pixel_ind*3 + 0]);
        green = static_cast<double>(rgb[pixel_ind*3 + 1]);
        blue = static_cast<double>(rgb[pixel_ind*3 + 2]);

        //step 3
        rgb_to_hsv(red, green, blue, hue, sat, val); //hue sat and val returned in h s and v values in the function

        //step 4
        hue = hue + hueshift;
          //now we will check if hue is still in the range [0, 360)
          //if not, then we will adjust it accordingly
          if (hue<0){
            hue+=360;
          }else if(hue>=360){
            hue-=360;
          }
          //we don't need an else statement, as that means that hue is already defined as to be in the correct range
        
        //step 5
        hsv_to_rgb(hue, sat, val, red, green, blue); //red green and blue are now returned properly with the adjusted hue into red green and blue channel variabels respectively

        //step 6
        shifted[pixel_ind*3 + 0] = red;
        shifted[pixel_ind*3 + 1] = green;
        shifted[pixel_ind*3 + 2] = blue;

      }
    }

    //shifted now contains adjusted rgb val per pixel

  ////////////////////////////////////////////////////////////////////////////
}
