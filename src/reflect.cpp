#include "reflect.h"

void reflect(
  const std::vector<unsigned char> & input,
  const int width,
  const int height,
  const int num_channels,
  std::vector<unsigned char> & reflected)
{
  reflected.resize(width*height*num_channels);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here

  for (int row=0; row<height; row++){
    for (int col=0; col<width; col++){
      for (int c=0; c<num_channels; c++){
        //reverse order of columns (horizontal reflection), and * by num_channels to consider different color channels if rgb img
        int curr_ind = (row * width * num_channels) + ((width - col - 1)*num_channels);
        int next_ind = (row*width*num_channels) + (col*num_channels);
          //notice above how the current index's width-col-1 = next index's col (reversing the columns)
        
        //now we copy pixel from current img's index into next img's index, so the "next img" is a reversed copy of "current img"
        reflected[next_ind + c] = input[curr_ind + c]; //take into account current channel value

      }
    }
  }

  ////////////////////////////////////////////////////////////////////////////
}
