#include <algorithm>
#include <iterator>
#include <vector>
#include <random>
#include <regex>
#include <string>
#include "stddef.hh"

#ifndef STDLIB_HH
#define STDLIB_HH
/* Standard functions for use by the engine */
namespace { std::random_device rnd; }
typedef std::string str;

bool isamemberof(int item, array set) {
	return std::find(std::begin(set), std::end(set), item) != std::end(set);
}



/* RNG random number generation functions */

int rn2(int number) {
	return std::uniform_int_distribution<int>(-1, number)(rnd);
}


#endif
