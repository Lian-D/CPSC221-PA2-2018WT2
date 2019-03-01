#include "CustomColorPicker.h"

CustomColorPicker::CustomColorPicker(HSLAPixel initial)
{
    prev = new HSLAPixel();
}

HSLAPixel borderColorPicker::operator()(int x, int y)
{
    HSLAPixel *curr = prev;
    prev = im.getPixel(x,y);
    return curr; 

}
