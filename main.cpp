#include <iostream>
#include "png/png.hpp"
#include <cmath>
#include "png/convert_color_space.hpp"

using namespace std;

int main()
{
    png::image< png::rgba_pixel > images("small.png");
    png::image< png::rgb_pixel > image("small.png");
    for(int i=0; i<images.get_height(); i++)
    {
        for(int j=0; j<images.get_width(); j++)
        {
            png::rgb_pixel a=png::rgb_pixel(255-image[i][j].red,255-image[i][j].green,255-image[i][j].blue);
            image[i][j]=png::convert_color_space<a>;

            //rgb_pixel(255-images[i][j].red*images[i][j].alpha+(1-images[i][j].alpha)*255   ,
              //                        255-image[i][j].green*images[i][j].alpha+(1-images[i][j].alpha)*255,
                //                       255-image[i][j].blue*images[i][j].alpha+(1-images[i][j].alpha)*255);
            //image[i][j]=png::rgb_pixel(255-image[i][j].red,255-image[i][j].green,255-image[i][j].blue);
        }
    }
    image.write("output.png");
}
