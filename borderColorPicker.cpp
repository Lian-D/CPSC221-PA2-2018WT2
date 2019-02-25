#include "borderColorPicker.h"

borderColorPicker::borderColorPicker(HSLAPixel fillColor, PNG & img, double tolerance,HSLAPixel center)
{
    borderColorPicker->color = fillColor;
    borderColorPicker->im = img;
    borderColorPicker->tol = tolerance;
    borderColorPicker->center = center;
}

HSLAPixel borderColorPicker::operator()(int x, int y)
{
    
    for (){ //cycles through x
        for(){ //cycles through y
            HSLAPixel *old = im.getPixel(x,y); //the returned pixel
            if(){ //if we get the elucidian thing
                return fillColor;
            }
            else{
                return *old; //Do nothing
            }
            
        } 
    }
    
}
