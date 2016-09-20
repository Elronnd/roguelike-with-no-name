#include "main.hh"
#include "stddef.hh"
#include "stdlib.hh"
#include "interface.hh"
#include <memory>

std::unique_ptr<BaseDisplayer> getinterface(bool wantdebug) {
	if (wantdebug) {
		return std::make_unique<DebugDisplayer>();
	} else {
		return std::make_unique<JSONDisplayer>();
	}
}


int main() {
	GameMap gamemap;
	auto display = getinterface(true);

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

	display->refresh(gamemap);
}
