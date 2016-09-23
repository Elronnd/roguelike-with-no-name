#include "main.hh"
#include "stddef.hh"
#include "stdlib.hh"
#include "interface.hh"
#include <memory>




int main(int argc, char **argp) {
	Engine engine;
	char inchar;

	// default is 'u' for 'uncursed
	// you can also use 'j' for json, and 'd' for debug. case-insensitive
	engine.setinterface();

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
	engine.map.mp = engine.u.mp;

	engine.map.maxhp = engine.u.maxhp;
	engine.map.maxmp = engine.u.maxmp;

	engine.map.mapspace[engine.u.uy].somestr[engine.u.ux] = at;

	// ... but this does
	engine.display->start(&argc, argp);
	engine.display->refresh(engine.map);
	while ((inchar = engine.display->readchar()) != 'q')
		engine.handlemove(inchar);
	return 0;
}
