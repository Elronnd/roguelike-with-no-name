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

template<typename T>
inline bool isamemberof(T item, vector<T> set) {
	return std::find(std::begin(set), std::end(set), item) != std::end(set);
}

inline bool isvalidcolour(str hexcolour) {
	static std::regex validator = std::regex("#?[0-1a-fA-F{6}");
	return std::regex_match(hexcolour, validator);
}

// converts, say, f to 15
inline char onehexrgb(unsigned char tchar) {
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


inline RGBColour hex2rgb(str hexcolour) {
	RGBColour RGB;

	if (hexcolour.length() == 7)
		hexcolour.erase(0, 1);

	/* Is it dirty?  yes.  Do I give two shits?  no. */
	RGB.r = 16*onehexrgb(hexcolour[0])+onehexrgb(hexcolour[1]);
	RGB.g = 16*onehexrgb(hexcolour[2])+onehexrgb(hexcolour[3]);
	RGB.b = 16*onehexrgb(hexcolour[4])+onehexrgb(hexcolour[5]);
	return RGB;
}


/* RNG random number generation functions */

// generates a number between 1 and number, inclusive
inline int rn1(int number) {
	return std::uniform_int_distribution<int>(1, number)(rnjesus);
}

// generates a number between 0 and number-1, inclusive
inline int rn2(int number) {
	return std::uniform_int_distribution<int>(0, number-1)(rnjesus);
}

// generates a number between min and max, inclusive
inline int rnd(int min, int max) {
	return std::uniform_int_distribution<int>(min,max)(rnjesus);
}

// generates numbers geometrically.  Increasingly likely to generate lower numbers
inline int rne(int x) {
	int tmp;

//	utmp = (u.ulevel < 15) ? 5 : u.ulevel / 3;
//	was ^^ in nethack
	tmp = 1;
	while (tmp < 100 && !rn2(x))
		tmp++;
	return tmp;
}

// rnz().  Here be dragons.
inline int rnz(int i) {
	int x = i;
	int tmp = 1000;

	tmp += rn2(1000);
	tmp *= rne(4);

	if (rn2(2)) {
		x *= tmp;
		x /= 1000;
	} else {
		x *= 1000;
		x /= tmp;
	}
	return (int) x;
}

// for dnd style Ndn stuff like 5d6 will generate a number between 1 and 6 5
// times and return the cumulative answer
// actual code is from nethack
inline int d(int n, int x) {
	int tmp = 0;

	while (n--)
		tmp += rn1(x);
	return tmp;
}
