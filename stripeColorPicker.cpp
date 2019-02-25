#include "stripeColorPicker.h"

stripeColorPicker::stripeColorPicker(HSLAPixel fillColor, int stripeSpacing)
{
    stripeColorPicker->color = fillColor;
    stripeColorPicker->spacing = stripeSpacing;
}

HSLAPixel stripeColorPicker::operator()(int x, int y)
{
    // If the x or y coordinate is a
    //  * multiple of the spacing, it will be filled with the fillColor.
    //  * otherwise, it will be filled with white.

    //This means modulo of the colors stuff with the spacing given;

    if (x % stripeColorPicker->spacing || y % stripeColorPicker->spacing){
        //This gives us the set stripe color
        return stripeColorPicker->color;
    }
    else {
        //Otherwise it's a whitey boi
        HSLAPixel whiteboi;
        whiteboi.h = 0;
        whiteboi.s = 0;
        whiteboi.l = 100;
        return whiteboi;
    }
}
