// Given a mosaiced image (interleaved BGGR colors in a single channel), created
// a 3-channel rgb image.
//              B   G
//              G   R
// Inputs:
//   bayer  width*height array containing interleaved color intensities in
//     the GBRG bayer pattern.
//              G   B
//              R   G
//   width  image width (i.e., number of columns)
//   height  image height (i.e., number of rows)
// Outputs:
//   rgb  width*height*3 array containing rgb image color intensities

#include "demosaic.h"
#include <vector>

void demosaic(
  const std::vector<unsigned char> & bayer,
  const int & width,
  const int & height,
  std::vector<unsigned char> & rgb)
{
  rgb.resize(width*height*3);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here

  //the following variables are going to be used to identify R, G, and B channels within rgb image and bayer image
  unsigned char r, g, b; int pixel_above, pixel_below, pixel_left, pixel_right, bayer_ind;

  for (int row=0; row<height; row++){
    for (int col=0; col<width; col++){
      
      pixel_above = (row-1)*width + col;
      pixel_below = (row+1)*width + col;
      pixel_left = row*width + (col-1);
      pixel_right = row*width + (col+1);

      bayer_ind = row*width+col;
      
      if ((row%2==0)&&(col%2==0)){ // even row, even column
        //green #1 (emphasis put on green, find intensities of red and blue)
        //use weighted luminosity with weights provided in tutorial
        r = static_cast<unsigned char>(0.2126*(static_cast<double>(pixel_above)+static_cast<double>(pixel_below)) + 0.7152*(static_cast<double>(pixel_left) + static_cast<double>(pixel_right)));
        b = static_cast<unsigned char>(0.0722*(static_cast<double>(pixel_above)+static_cast<double>(pixel_below) + static_cast<double>(pixel_left) + static_cast<double>(pixel_right)));
        //since green channel, the g is stored in bayer image passed through
        g = bayer[bayer_ind];
      } else if((row%2==0)&&(col%2==1)){ //even row, odd column
        //blue (emphasis put on blue, find intensities of red and green)
        r = static_cast<unsigned char>(0.2126*(static_cast<double>(pixel_left)+static_cast<double>(pixel_right)));
        g = static_cast<unsigned char>(0.7152*(static_cast<double>(pixel_above)+static_cast<double>(pixel_below)));
        //b is stored in bayer
        b = bayer[bayer_ind];
      } else if((row%2==1)&&(col%2==0)){ //odd row, even column
        //red (emphasis put on red, find intensities of blue and green)
        b = static_cast<unsigned char>(0.0722*(static_cast<double>(pixel_above)+static_cast<double>(pixel_below)));
        g = static_cast<unsigned char>(0.7152*(static_cast<double>(pixel_left)+static_cast<double>(pixel_right)));
        r = bayer[bayer_ind];
      } else{ //odd row, odd column
        //green #2 (emphasis put on green, find intensities of red and blue)
        r = static_cast<unsigned char>(0.2126*(static_cast<double>(pixel_above)+static_cast<double>(pixel_below)) + 0.7152*(static_cast<double>(pixel_left) + static_cast<double>(pixel_right)));
        b = static_cast<unsigned char>(0.0722*(static_cast<double>(pixel_above)+static_cast<double>(pixel_below) + static_cast<double>(pixel_left) + static_cast<double>(pixel_right)));
        g = bayer[bayer_ind];
      }
      //store interpolated r, g, and b values into rgb img
      rgb[bayer_ind]=r;
      rgb[bayer_ind+1]=g;
      rgb[bayer_ind+2]=b;
    }
  }
  ////////////////////////////////////////////////////////////////////////////
}
