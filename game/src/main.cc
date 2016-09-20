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

void Engine::handlemove(char inchar) {
	switch(inchar) {
		case 'h':
			if (u.ux != 0) {
				map.mapspace[u.uy].somestr[u.ux] = middot;
				u.ux--;
				map.mapspace[u.uy].somestr[u.ux] = at;
			}
				display->refresh(map);
			break;
		case 'l':
			if (u.ux != MAX_ROWS) {
				map.mapspace[u.uy].somestr[u.ux] = middot;
				u.ux++;
				map.mapspace[u.uy].somestr[u.ux] = at;
			}
				display->refresh(map);
			break;
		case 'k':
			if (u.uy != 0) {
				map.mapspace[u.uy].somestr[u.ux] = middot;
				u.uy--;
				map.mapspace[u.uy].somestr[u.ux] = at;
			}
				display->refresh(map);
			break;
		case 'j':
			if (u.uy != MAX_COLS) {
				map.mapspace[u.uy].somestr[u.ux] = middot;
				u.uy++;
				map.mapspace[u.uy].somestr[u.ux] = at;
			}
			display->refresh(map);
			break;
	}
}


int main() {
	Engine engine;
	char inchar;
//	auto display = getinterface(true);

	// initialize with middots, no colours
	for (ColouredTileString line: engine.map.mapspace) {
		for (Tile tile: line.somestr) {
			tile = middot;
		}
	}


	engine.u.hp = engine.u.maxhp = rnd(15, 20);
	engine.u.mp = engine.u.maxmp = rnd(15, 20);

	engine.u.ux = rn2(MAX_COLS);
	engine.u.uy = rn2(MAX_ROWS);

	engine.map.hp = engine.u.hp;
	engine.map.hp = engine.u.hp;

	engine.map.maxhp = engine.u.maxhp;
	engine.map.maxmp = engine.u.maxmp;

	engine.map.mapspace[engine.u.uy].somestr[engine.u.ux] = at;

	engine.display->refresh(engine.map);
	while ((inchar = engine.display->readchar()) != 'q')
		engine.handlemove(inchar);
	return 0;
}
