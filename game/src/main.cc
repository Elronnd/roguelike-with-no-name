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
	for (ColouredGlyphString line: engine.map.mapspace) {
		for (Glyph& glyph: line.somestr) {
			glyph = middot;
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

	engine.display->start(&argc, argp);
	engine.display->refresh(engine.map);
	while ((inchar = engine.display->readchar()) != 'q')
		engine.handlemove(inchar);
	engine.display->end();
	return 0;
}
