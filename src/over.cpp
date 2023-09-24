#include "over.h"

void over(
  const std::vector<unsigned char> & A,
  const std::vector<unsigned char> & B,
  const int & width,
  const int & height,
  std::vector<unsigned char> & C)
{
  C.resize(A.size());
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here

  //we are going to use the following steps and variables while looping through every pixel in width*height of images A and B by using a nested for loop
  //assuming A.size() = B.size() = 4*height*width
    //variables
      double alpha_A, alpha_B, alpha_C, red_A, red_B, red_C, green_A, green_B, green_C, blue_A, blue_B, blue_C; int pixel_ind;
    //steps
      //1. extract channels red_A, green_A, blue_A, alpha_A from image A
      //2. extract channels red_B, green_B, blue_B, alpha_B from image B
      //3. calculate alpha composite (using porter-duff over operator to calculate alpha composite values)
        /*
          Using references [1], [2], and [3]
          
          alpha_A       transparency of A at pixel_ind
          alpha_B       transparency of B at pixel_ind

          alpha_C       transparency of C at pixel_ind (what we need to calculate)
                        alpha_C = alpha_A + alpha_B*(1.0-alpha_A)     //alpha composite function (formula to calculate alpha blending)
          
              *alpha channel controls opacity (more alpha <-> more transparent)

          
          red_C         red color channel value of C at pixel_ind
                        red_C = (1/alpha_C)*(red_A * alpha_A + red_B * alpha_B * (1.0-alpha_A))

          green_C       green color channel value of C at pixel_ind
                        green_C = (1/alpha_C)*(green_A * alpha_A + green_B * alpha_B * (1.0-alpha_A))

          blue_C        blue color channel value of C at pixel_ind
                        blue_C = (1/alpha_C)*(blue_A * alpha_A + blue_B * alpha_B * (1.0-alpha_A))

          this will give us the rgba values

        */
       //4. now that we have the rgba values of image c, we store them into unsigned char vector of C

    for (int row = 0; row<height; row++){
      for (int col=0; col<width; col++){
        //calculate pixel index
        pixel_ind = 4*(row*width + col);

        //step 1
        red_A = static_cast<double>(A[pixel_ind + 0]);
        green_A = static_cast<double>(A[pixel_ind + 1]);
        blue_A = static_cast<double>(A[pixel_ind + 2]);
        alpha_A = static_cast<double>(A[pixel_ind + 3]);

        //step 2
        red_B = static_cast<double>(B[pixel_ind + 0]);
        green_B = static_cast<double>(B[pixel_ind + 1]);
        blue_B = static_cast<double>(B[pixel_ind + 2]);
        alpha_B = static_cast<double>(B[pixel_ind + 3]);

        //step 3
          //lets calculate alpha_C first
          alpha_C = alpha_A + alpha_B*(1.0 - alpha_A);

          //next, lets calculate red_C
          red_C = (1.0/alpha_C)*(red_A*alpha_A + red_B*alpha_B*(1.0-alpha_A));
          //and green_C
          green_C = (1.0/alpha_C)*(green_A*alpha_A + green_B*alpha_B*(1.0-alpha_A));
          //and blue_C
          blue_C = (1.0/alpha_C)*(blue_A*alpha_A + blue_B*alpha_B*(1.0-alpha_A));

        //step 4
          //now that we have the rgba values stored for image C, let's send it over using pixel_ind and the respective rgba channel chars
          //store red_C
          C[pixel_ind + 0] = static_cast<unsigned char>(red_C);
          //store green_C
          C[pixel_ind + 1] = static_cast<unsigned char>(green_C);
          //store blue_C
          C[pixel_ind + 2] = static_cast<unsigned char>(blue_C);
          //finally, store alpha_C
          C[pixel_ind + 3] = static_cast<unsigned char>(alpha_C); 
      }
    }

    //porter-duff function finished. C now contains pixel values that lay A over B with their respective rgba channels per pixel.

  ////////////////////////////////////////////////////////////////////////////
}

/*

References: 
  [1] https://keithp.com/~keithp/porterduff/p253-porter.pdf
  [2] Andrew Moylan "Duff-Porter Alpha-Compositing Operators" http://demonstrations.wolfram.com/DuffPorterAlphaCompositingOperators/ Wolfram Demonstrations Project Published: March 7 2011
*/
