#include "write_ppm.h"
#include <fstream>
#include <vector>
#include <cassert>
#include <iostream>

bool write_ppm(
  const std::string & filename,
  const std::vector<unsigned char> & data,
  const int width,
  const int height,
  const int num_channels)
{
  assert(
    (num_channels == 3 || num_channels ==1 ) &&
    ".ppm only supports RGB or grayscale images");
  ////////////////////////////////////////////////////////////////////////////
  // Replace with your code here:

  //open file for writing
  std::ofstream ppmFile(filename);
  if (ppmFile.is_open()==false){ //output filename if couldn't open and return false
    std::cerr << "Can't open file: " << filename << std::endl; //cerr => standard error stream (where error messages are sent)
    return false;
  }

  //determine header of ppm file
    //based on the number of channels
    //1 channel => P2 => grayscaele 
    //3 channels => P3 => RGB
    if(num_channels == 1){
      ppmFile << "P2" << std::endl;
    }else{
      ppmFile << "P3" << std::endl;
    }

    //based on width and height
    //ppmFile << width << " " << height << std::endl;

    //maximum intensity val
    //ppmFile << str(width*height*num_channels) << std::endl;

  //write data to file
    for (int w=0; w<width; w++){
      for (int h=0; h<height; h++){
        for (int c=0; c<num_channels; c++){
          int ind = (h*width + w) * c;
          if (c>0){ //if more than 1 channel, then give space between writing
            ppmFile << " ";
          }
          ppmFile << int(data[ind + c]); //write data value of current index to correct channel
        }
        ppmFile << " ";
      }
      //end the data line
      ppmFile << std::endl;
    }

    //close the file
    ppmFile.close();

    //return true
    return true;

  ////////////////////////////////////////////////////////////////////////////
}
