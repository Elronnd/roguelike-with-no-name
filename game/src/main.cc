#include "main.hh"
#include "stddef.hh"
#include "stdlib.hh"
#include "interface.hh"


int main() {
	GameMap gamemap;
	DebugDisplayer display;

	// initialize with middots, no colours
	for (ColouredTileString line: gamemap.mapspace) {
		for (Tile tile: line.somestr) {
			tile = middot;
		}
	}

	Being u;

	u.hp = u.maxhp = rnd(15, 20);
	u.mp = u.maxmp = rnd(15, 20);

	u.ux = rn2(MAX_COLS);
	u.uy = rn2(MAX_ROWS);

	gamemap.mapspace[u.uy].somestr[u.ux] = at;

	display.refresh(gamemap);
}
