#include <iostream>
#include <string>
#include "stdlib.hh"
#include "stddef.hh"
#include "interface.hh"

void DebugDisplayer::refresh(GameMap& map) {
	for (ColouredString line: map.gamemap) {
		cout << line.somestr << endl;
	}
	cout << "hp: " << int(map.hp) << "(" << int(map.maxhp) << "), mp: " << int(map.mp) << "(" << int(map.maxmp) << ")." << endl;
}

void DebugDisplayer::animation_sparkle(short x, short y) {
	cout << "Sparkle animation at (" << x << "," << y << ")" << endl;
}

char JSONDisplayer::getchar() {
	char foo;
	std::cin >> foo;
	return foo;
}
