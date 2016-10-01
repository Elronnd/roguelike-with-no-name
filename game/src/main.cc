#include "main.hh"
#include "stddef.hh"
#include "stdlib.hh"
#include "interface.hh"
#include <memory>

void Engine::init(int argc, char **argp) {
	// default is 'u' for "uncursed"
	// you can also use 'j' for json or 'd' for debug.  case-insensitive
	setinterface();

	makecmds();

	// initialize with middots, no colours
	for (ColouredGlyphString line: this->map.mapspace) {
		for (Glyph& glyph: line.somestr) {
			glyph = middot;
		}
	}

	u.hp = u.maxhp = rnd(15, 20);
	u.mp = u.maxmp = rnd(15, 20);

	u.ux = rn2(MAX_COLS);
	u.uy = rn2(MAX_ROWS);

	map.hp = u.hp;
	map.mp = u.mp;
	map.maxhp = u.maxhp;
	map.maxmp = u.maxmp;

	map.mapspace[u.uy].somestr[u.ux] = at;

	display->start(&argc, argp);
	refresh();
}

void Engine::run() {
	char inchar;

	while ((inchar = display->readchar())) {
		if (isamemberof(inchar, listofvikeys)) {
			if (vikeys[inchar] == cmd_quit)
				break;
			handlemove(isamemberof(inchar, listofvikeys) ? vikeys[inchar] : cmd_unknown);
		} else
			handlemove(cmd_unknown);
	}
        display->end();
}


int main(int argc, char **argp) {
	Engine engine;
	engine.init(argc, argp);
	engine.run();
	return 0;
}
