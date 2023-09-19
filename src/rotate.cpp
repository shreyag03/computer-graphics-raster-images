#include "rotate.h"

void rotate(
  const std::vector<unsigned char> & input,
  const int width,
  const int height,
  const int num_channels,
  std::vector<unsigned char> & rotated)
{
  rotated.resize(height*width*num_channels);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here

  for (int row=0; row<height; row++){
    for (int col=0; col<width; col++){
      for (int c=0; c<num_channels; c++){
        //change order of "next img"'s col/row so that it is turned 90 degrees, and multiply with number of channels to account for rgb
        int curr_ind = ((row * width) + col) * num_channels; 
        int next_ind = ((height*(width - col - 1)) + row) * num_channels;

        //now we copy pixel from current img's index into next img's index, so the "next img" is a rotated copy of "current img"
        rotated[next_ind + c] = input[curr_ind + c]; //take into account current channel value

      }
    }
  }


  ////////////////////////////////////////////////////////////////////////////
}
