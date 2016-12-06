#include "stddef.hh"

#define colour(name, r, g, b) const RGBColour name(r, g, b);

colour(white, 255, 255, 255)
colour(black, 0, 0, 0)

colour(red, 255, 0, 0)
colour(green, 0, 255, 0)
colour(blue, 0, 0, 255)

colour(cyan, 0, 255, 255)
colour(magenta, 255, 0, 255)
colour(yellow, 255, 255, 0)

#undef colour
