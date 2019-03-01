#ifndef CUSTOMCOLORPICKER_H
#define CUSTOMCOLORPICKER_H

#include "colorPicker.h"

/**
 * stripeColorPicker: a functor that determines the color that should be used
 * given an x and a y coordinate using a stripe pattern.
 *
 */
class CustomColorPicker : public colorPicker
{
  public:
    CustomColorPicker(HSLAPixel fillColor, int stripeSpacing);
    
    virtual HSLAPixel operator()(int x, int y);

  private:
    HSLAPixel color; /**< Color used for the stripe. */
    int spacing;     /**< Space between stripes. */
};

#endif
