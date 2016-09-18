#include <string>
#include <cstdio>
#include "stdlib.hh"
#include "stddef.hh"
#include "interface.hh"
#include "tile.hh"


void DebugDisplayer::refresh(GameMap& map) {
	for (ColouredTileString line: map.mapspace) {
		for (Tile tile: line.somestr)
			printf("%s", tileset()[tile].c_str());
		printf("\n");
	}
	printf("hp: %d(%d), mp: %d(%d)\n", map.hp, map.maxhp, map.mp, map.maxmp);
}

void DebugDisplayer::animation_sparkle(short x, short y) {
	printf("Sparkle animation at (%d,%d)\n", x, y);
}

char DebugDisplayer::readchar() {
	return getchar();
}
