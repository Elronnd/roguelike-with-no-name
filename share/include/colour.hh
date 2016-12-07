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


RGBColour rndclr() {
	return RGBColour(rn2(256), rn2(256), rn2(256));
}

RGBColour oppositeclr(RGBColour colour) {
	return RGBColour(255-colour.r, 255-colour.g, 255-colour.b);
}
