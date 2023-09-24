// Desaturate a given rgb color image by a given factor.
//
// Inputs:
//   rgb  width*height*3 array containing rgb image color intensities
//   width  image width (i.e., number of columns)
//   height  image height (i.e., number of rows)
//   factor  fractional amount of saturation to remove: 1-->fully grayscale,
//     0-->retain input color.
// Outputs:
//   desaturated  width*height*3 array containing rgb image color intensities

#include "desaturate.h"
#include "hsv_to_rgb.h"
#include "rgb_to_hsv.h"
#include <vector>
#include <algorithm>

void desaturate(
  const std::vector<unsigned char> & rgb,
  const int width,
  const int height,
  const double factor,
  std::vector<unsigned char> & desaturated)
{
  desaturated.resize(rgb.size());
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here

  //this is going to be very similar to the hue shift function, with the exception of changing hue versus saturation

  //first, we are going to normalize the factor value to be between 0.0 and 1.0
  //to do this, we need to create a variable to store factor's value, so we can use it in the program and manipulate it if wrong
  double fac = std::min(1.0, std::max(0.0, factor));

  //now, we will loop through each pixel in rgb and change it accordingly, and store result in desaturated vector
    //following steps will be carried out with the help of the variables defined in the next line
    int pixel_ind; double red, green, blue, hue, sat, val, new_red, new_green, new_blue;
    //1. loop through rgb image for each pixel
    //2. extract r g and b channels
    //3. convert the r g and b channels into hsv
    //4. apply desaturation factor to saturation value returned by rgb_to_hsv function
    //5. convert h s and v channels into rgb
    //6. store the desaturated rgb values into the desaturated img vector

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
        sat = sat*fac;
          //we don't need to check if sat is in the correct value, because there is no possibility of getting a sat value not in [0, 1] while multiplying it with a factor between [0, 1]
        
        //step 5
        hsv_to_rgb(hue, sat, val, new_red, new_green, new_blue); //red green and blue are now returned properly with the adjusted hue into red green and blue channel variabels respectively

        //step 6
        desaturated[pixel_ind*3 + 0] = static_cast<unsigned char>(new_red);
        desaturated[pixel_ind*3 + 1] = static_cast<unsigned char>(new_green);
        desaturated[pixel_ind*3 + 2] = static_cast<unsigned char>(new_blue);

      }
    }


  ////////////////////////////////////////////////////////////////////////////
}
