#include "simulate_bayer_mosaic.h"
#include <vector>
#include <algorithm>

void simulate_bayer_mosaic(
  const std::vector<unsigned char> & rgb,
  const int & width,
  const int & height,
  std::vector<unsigned char> & bayer)
{
  bayer.resize(width*height);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here

  //     GBRG (Green - Blue / Red - Green)
  //        - Four rays hit sensor, reading green to blue, then red to green (double the green than any other)
  //        - top left = G        
  //          top right = B
  //          bottom left = R
  //          bottom right = G
  //        - shape :             e o           o = odd, e = even
  //                              G B   e
  //                              R G   o




  //to create the bayer mosaic with specified GBRG shape above, we are going to use following variables
  unsigned char r_pixel, g_pixel, b_pixel; double avg; int r_channel, g_channel, b_channel;

  for (int row=0; row<height; row++){
    for (int col=0; col<width; col++){
      //for this coordinate, we calculate the corresponding bayer and rgb index
      int pixel_ind = row*width + col;
      int rgb_pixel = pixel_ind * 3; //multiply pixel index by 3 to account for the 3 channels existing per pixel in rgb images
      
      //we can identify the separate rgb pixel values from this coordinate in the rgb img using corresponding coordinate in bayer mosaic img
        //blue -> channel = 0
        b_pixel = rgb[rgb_pixel + 0];
        //green -> channel 1
        g_pixel = rgb[rgb_pixel + 1];
        //red -> channel 2
        r_pixel = rgb[rgb_pixel + 2];

      //For the pixel in this (row, col) coordinate, determine which channel it belongs to regarding the GBRG pattern. We will use pixel_ind
        //even row, even col
        if (((row%2)==0)&&((col%2)==0)){
            //green channel(G) => average calculated normally
            //weighted average of rgb (numbers from tutorial) for grayscale => emphasis given to g
            avg = 0.2126*(static_cast<double>(r_pixel)) + 0.7152*(static_cast<double>(g_pixel)) + 0.0722*(static_cast<double>(b_pixel));
        }//even row, odd col
        else if (((row%2)==0)&&((col%2)==1)){
            //blue channel(B) => average calculated with emphasis on blue
            //weighted average of rgb (numbers from tutorial) for grayscale => emphasis given to g
            avg = 0.2126*(static_cast<double>(r_pixel)) + 0.7152*(static_cast<double>(b_pixel)) + 0.0722*(static_cast<double>(g_pixel)); //green subsituted by blue
        }//odd row, even col
        else if (((row%2)==1)&&((col%2)==0)){
            //red channel (R) => average calculated with emphasis on red
            //weighted average of rgb (numbers from tutorial) for grayscale => emphasis given to g
            avg = 0.2126*(static_cast<double>(g_pixel)) + 0.7152*(static_cast<double>(r_pixel)) + 0.0722*(static_cast<double>(b_pixel)); //red substituted by green
        }//odd row, odd col
        else{
            //weighted average of rgb (numbers from tutorial) for grayscale => emphasis given to g
            avg = 0.2126*(static_cast<double>(r_pixel)) + 0.7152*(static_cast<double>(g_pixel)) + 0.0722*(static_cast<double>(b_pixel));
            //green channel (G) => average calculated normally
        }

        bayer[pixel_ind] = avg;
    }
  }


  //end of function

  ////////////////////////////////////////////////////////////////////////////
}
