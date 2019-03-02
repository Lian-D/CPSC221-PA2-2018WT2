#include "borderColorPicker.h"

borderColorPicker::borderColorPicker(HSLAPixel fillColor, PNG & img, double tolerance,HSLAPixel center)
{
    color = fillColor;
    im = img;
    tol = tolerance;
    ctr = center;
}

HSLAPixel borderColorPicker::operator()(int x, int y)
{
    int xedge = x+3;
    int yedge = y+3;

    HSLAPixel *old = im.getPixel(x,y); //the original pixel
    for (int a = (x-3); a <= xedge; a++){
        for (int b= (y-3); b <= yedge; b++){
            if (a >= (int) im.width() || b >= (int) im.height() || a < 0 || b < 0 || ((x-a)*(x-a) + (y-b)*(y-b) <= 9 && im.getPixel(a,b)->dist(ctr) > tol)){
                return color;
            }
        }
    }
    return *old;
}
