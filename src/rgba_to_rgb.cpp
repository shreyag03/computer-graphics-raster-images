#include "RGBA_TO_RGB.H"

#include <vector>
#include <algorithm>
#include <cmath>

//unsigned char --> struct to hold rgba and rgb pixel vals

/// @brief 
/// @param rgba 
/// @param width 
/// @param height 
/// @param rgb 
void rgba_to_rgb(
  const std::vector<unsigned char>& rgba,
  const int & width,
  const int & height,
  std::vector<unsigned char> & rgb)
{
  rgb.resize(height*width*3);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here

  //loop through each pixel in rgba
  for (int i=0; i<height; i++){
    for (int j=0; j<width; j++){
      
      int index = i*width + j; //used to calculate rgb and rgba pixel val

      //find index of current pixel in rgba img (each pixel has 4 channels)
      int rgbapixel_now = index * 4;

      //find index of current pixel in rgb img (each pixel has 3 channels)
      int rgbpixel_now = index * 3;

      //the current index of rgba img will be current index of rgb img

      //copy rgb values from rgba img ONLY (do not copy over a, only r, g, and b)
      rgb[rgbpixel_now] = rgba[rgbapixel_now];          //copy over r
      rgb[rgbpixel_now + 1] = rgba[rgbapixel_now + 1];  //copy over g
      rgb[rgbpixel_now + 2] = rgba[rgbapixel_now + 2];  //copy over b

      //notice how there is no space for the 4th channel in rgb image, and so we don't copy it over.
      //4th channel would be the alpha channel in this case 

    }
  }
  ////////////////////////////////////////////////////////////////////////////
}
