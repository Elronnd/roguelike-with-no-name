#include <string>
#include <cstdio>
#include "stdlib.hh"
#include "stddef.hh"
#include "interface.hh"
#include "tile.hh"


void DebugDisplayer::refresh(GameMap& map) {
	for (ColouredGlyphString line: map.mapspace) {
		for (Glyph glyph: line.somestr)
			printf("%s", tileset()[glyph].c_str());
		printf("\n");
	}
	printf("hp: %d(%d), mp: %d(%d)\n", map.hp, map.maxhp, map.mp, map.maxmp);
	printf("Loc: (%d,%d)\n", map.x, map.y);
}

void DebugDisplayer::animation_sparkle(short x, short y) {
	printf("Sparkle animation at (%d,%d)\n", x, y);
}

char DebugDisplayer::readchar() {
	return getchar();
}

void DebugDisplayer::start(int *argc, char **argp, str title) {(void) argc; (void) argp; (void) title; }
void DebugDisplayer::end() {}
