#include "rgb_to_gray.h"

#include <vector>

void rgb_to_gray(
  const std::vector<unsigned char> & rgb,
  const int width,
  const int height,
  std::vector<unsigned char> & gray)
{
  gray.resize(height*width);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here

  //we can convert rgb image to grayscale by averaging rgb channels for each pixel

  //variables used inside loop initalized here
  unsigned char b_pixel, r_pixel, g_pixel;

  for (int row=0; row<height; row++){
    for (int col=0; col<width; col++){
      int gray_pixel = (row*width + col); 
      int rgb_pixel = gray_pixel * 3; //index value accounting the number of channels for rgb img (3)
      
      //average the rgb channels of rgb img
        //red -> channel = 0
        r_pixel = rgb[rgb_pixel + 0];
        //green -> channel 1
        g_pixel = rgb[rgb_pixel + 1];
        //blue -> channel 2
        r_pixel = rgb[rgb_pixel + 2];

        //weighted average of rgb (numbers from tutorial)
        double avg = 0.2126*(static_cast<double>(r_pixel)) + 0.7152*(static_cast<double>(g_pixel)) + 0.0722*(static_cast<double>(b_pixel));

      //cast this avg of rgb img into the gray_pixel index for grayscale img
      gray[gray_pixel] = static_cast<unsigned char>(avg);

    }
  }

  ////////////////////////////////////////////////////////////////////////////
}


