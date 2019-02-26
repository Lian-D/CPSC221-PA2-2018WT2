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
    HSLAPixel *old = im.getPixel(x,y); //the returned pixel
    if (*old->h + tol >= fillColor->h || *old->s + tol >= fillColor->s || *old->l + tol >= fillColor->l|| *old->a + tol >= fillColor->a){
        return fillColor;
    }
    else {
        return *old;
    }
    
}
