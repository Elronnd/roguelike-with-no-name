#include <iostream>
#include <string>
#include "stdlib.hh"
#include "stddef.hh"
#include "interface.hh"
#include "tile.hh"

using std::cout;
using std::endl;

void DebugDisplayer::refresh(GameMap& map) {
	for (ColouredTileString line: map.mapspace) {
		for (Tile tile: line.somestr)
			cout << tileset()[tile];
		cout << endl;
	}
	cout << "hp: " << int(map.hp) << "(" << int(map.maxhp) << "), mp: " << int(map.mp) << "(" << int(map.maxmp) << ")." << endl;
}

void DebugDisplayer::animation_sparkle(short x, short y) {
	cout << "Sparkle animation at (" << x << "," << y << ")" << endl;
}

char DebugDisplayer::readchar() {
	return getchar();
}
