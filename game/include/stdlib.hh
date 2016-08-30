#include <algorithm>
#include <iterator>
#include <vector>

/* Standard functions for use by the engine */

bool isamemberof(int item, std::vector<int> set) {
	return std::find(std::begin(set), std::end(set), item) != std::end(set);
}
