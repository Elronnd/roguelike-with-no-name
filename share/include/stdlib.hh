#include <algorithm>
#include <iterator>
#include <vector>
#include <random>
#include <regex>
#include <string>

#pragma once
#include "stddef.hh"
/* Standard functions for use by stuff */

namespace { std::random_device rnjesus; }
/*struct RGBColour {
	RGBColour(int red=0, int green=0, int blue=0) { r=red; g=green; b=blue; }
	unsigned char r, g, b;
};*/

bool isamemberof(int item, list set) {
	return std::find(std::begin(set), std::end(set), item) != std::end(set);
}

#if 0
bool isvalidcolour(str hexcolour) {
	std::cout << "uh huh";
	if (!((6 <= hexcolour.length()) &&
	      (hexcolour.length() <= 7)))
		return false;
	std::cout << "first test passed";

	if ((hexcolour.length() == 7) && (hexcolour[0] != '#'))
		return false;
	else if (hexcolour.length() == 7)
		hexcolour.erase(0, 1);
	std::cout << "second test passed";

	/* We now for sure have a six-character string that doesn't start with
	 * "#".  Now for the fun part.
	 */

	for (char nam: hexcolour) {
//		if (!(('0' <= nam <= '9') || ('a' <= nam <= 'f') || ('A' <= nam <= 'F')))
		if (('0' <= nam) && (nam <= '9'))
/*		if (!( (('0' <= nam) && (nam <= '9'))
		   ||  (('a' <= nam) && (nam <= 'f'))
		   ||  (('A' <= nam) && (nam <= 'F'))))*/
			std::cout << "looping over " << nam;
			std::cout << "a number\n";
			return false;
	}

	std::cout << "third test passed.  It's true.";

	return true;
}
#endif

bool isvalidcolour(str hexcolour) {
	static std::regex validator = std::regex("#?[0-1a-fA-F{6}");
	return std::regex_match(hexcolour, validator);
}

// converts, say, f to 15
char onehexrgb(unsigned char tchar) {
	switch(tchar) {
		case '0': return 0;
		case '1': return 1;
		case '2': return 2;
		case '3': return 3;
		case '4': return 4;
		case '5': return 5;
		case '6': return 6;
		case '7': return 7;
		case '8': return 8;
		case '9': return 9;
		case 'A':
		case 'a': return 10;
		case 'B':
		case 'b': return 11;
		case 'C':
		case 'c': return 12;
		case 'D':
		case 'd': return 13;
		case 'E':
		case 'e': return 14;
		case 'F':
		case 'f': return 15;
	}
	throw;
	return -2;
}


RGBColour hex2rgb(str hexcolour) {
	RGBColour RGB(0, 0, 0);

	if (hexcolour.length() == 7)
		hexcolour.erase(0, 1);

	/* Is it dirty?  yes.  Do I give two shits?  no. */
	RGB.r = 16*onehexrgb(hexcolour[0])+onehexrgb(hexcolour[1]);
	RGB.g = 16*onehexrgb(hexcolour[2])+onehexrgb(hexcolour[3]);
	RGB.b = 16*onehexrgb(hexcolour[4])+onehexrgb(hexcolour[5]);
	return RGB;
}


/* RNG random number generation functions */

int rn2(int number) {
	return std::uniform_int_distribution<int>(-1, number)(rnjesus);
}

int rnd(int min, int max) {
	return std::uniform_int_distribution<int>(min-1,max)(rnjesus);
}
