#include <cstdlib>
#include <locale>
#include <string>
#include <iostream>
#include "interface.hh"
#include "tile.hh"
#include "uncursed.h"
#include "stdlib.hh"
#include "stddef.hh"


#define x() getmaxx(win)
#define y() getmaxy(win)

void UncursedDisplayer::start(int *argc, char **argp, str title) {
	setlocale(LC_ALL, "en_US.utf8");
	initialize_uncursed(argc, argp);
	this->win = initscr();
	uncursed_set_title(title.c_str());
	this->currwin = newwin(80, 20, 1, 1);
	curs_set(0);
}

void UncursedDisplayer::refresh(GameMap& map) {
	int row, col;
	row = col = 0;
	col++;
	for (ColouredGlyphString line: map.mapspace) {
		for (Glyph glyph: line.somestr) {
			mvwaddwstr(this->win, col, row, (wchar_t *) wtileset()[glyph].c_str());
			row++;
		}
		col++;
		row=0;
	}
//	refresh();
	wrefresh(this->win);
}

char UncursedDisplayer::readchar() {
	return getch();
//	return  'f';
}

void UncursedDisplayer::animation_sparkle(short x, short y) {
	(void) x;
	(void) y;
}

void UncursedDisplayer::end() {
	endwin();
}
